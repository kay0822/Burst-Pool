/*
		Create table Accounts (
			accountID					bigint unsigned not null unique,
			first_seen_when				timestamp not null default current_timestamp,
			reward_recipient			bigint unsigned not null,
			last_updated_when			timestamp null default null,
			last_nonce					bigint unsigned,
			last_nonce_when				timestamp null default null,
			account_name				varchar(255),
			estimated_capacity			bigint unsigned,
			account_RS_string			varchar(255) not null,
			has_used_this_pool			boolean not null default false,
			primary key					(accountID)
		);
*/

#include "Block.hpp"
#include "Share.hpp"

#include "remote.hpp"
#include "config.hpp"

#include "Account.cxx"


#define ESTIMATED_CAPACITY_DEADLINES 8

SEARCHMOD( needs_updating, bool );
SEARCHMOD( sum_capacities, bool );


SEARCHPREP {
	SEARCHPREP_SUPER;

	if ( SEARCHMOD_IS_SET(needs_updating) ) {
		if ( SEARCHMOD_VALUE(needs_updating) ) {
			IDB::Where *new_clause = new IDB::sqlLtString( "last_updated_when", IDB::Engine::from_unixtime( time(NULL) - ACCOUNT_UPDATE_TIMEOUT ) );
			SEARCHPREP_ADD( new_clause );
		} else {
			IDB::Where *new_clause = new IDB::sqlGeString( "last_updated_when", IDB::Engine::from_unixtime( time(NULL) - ACCOUNT_UPDATE_TIMEOUT ) );
			SEARCHPREP_ADD( new_clause );
		}
	}

	if ( SEARCHMOD_IS_SET(sum_capacities) ) {
		ps->cols->clear();
		ps->cols->push_back("null");
		ps->cols->push_back("null");
		ps->cols->push_back("null");
		ps->cols->push_back("null");
		ps->cols->push_back("null");
		ps->cols->push_back("null");
		ps->cols->push_back("null");
		// change estimated_capacity
		ps->cols->push_back( "sum(estimated_capacity) as estimated_capacity" );
		ps->cols->push_back("null");
		ps->cols->push_back("null");
	}

	SEARCHPREP_END;
}




void Account::save() {
	if ( accountID() && account_RS_string().empty() )
		account_RS_string( accountID_to_RS_string( accountID() ) );

	IO::Object::save();
}


STATIC Account *Account::load_or_create( uint64_t some_accountID ) {
	// passed a 0 accountID?
	if ( some_accountID == 0 )
		return NULL;

	Account *account = Account::load( some_accountID );

	if (account == NULL) {
		account = new Account;
		account->accountID( some_accountID );
		account->last_updated_when( 0 );
		account->save();
	}

	return account;
}


uint64_t Account::estimate_capacity() {
	uint64_t latest_blockID = Block::latest_blockID();
	uint64_t from_blockID = latest_blockID - HISTORIC_CAPACITY_BLOCK_COUNT;

	Share shares;
	shares.accountID( accountID() );
	// don't include latest block as trying to access that contributes to transaction deadlocks
	shares.before_blockID( latest_blockID - 1 );
	shares.after_blockID( from_blockID );
	shares.mean_weighted_deadline( true );
	shares.limit( ESTIMATED_CAPACITY_DEADLINES );
	shares.search();

	uint64_t total = 0;
	while( Share *share = shares.result() ) {
		total += share->deadline(); // actually weighted deadline
		delete share;
	}

	uint64_t mean_weighted_deadline = total / ESTIMATED_CAPACITY_DEADLINES;
	if (mean_weighted_deadline == 0)
		return 0;

	// capacity in GiB
	// fudge based on known capacitiy of known account!!
	// CatBref (15188591833767009677) has 120190592 nonces = 31507242549248 bytes (~31TB)
	const uint64_t fudge_factor = 48541769974784UL;
	return fudge_factor / mean_weighted_deadline;
}


void Account::update_check() {
	if ( last_updated_when() < (time(NULL) - ACCOUNT_UPDATE_TIMEOUT) ) {
		std::string account_json = fetch( "http://" + BURST_SERVER + "/burst?requestType=getAccount&account=" + std::to_string( accountID() ) );

		if ( !qJSON( account_json, "account" ).empty() ) {
			// check for account "name"
			account_name( qJSON( account_json, "name" ) );
			last_updated_when( time(NULL) );

			// if it's an account that has used this pool then we need to check
			// reward recipient, etc. too
			if ( has_used_this_pool() ) {
				std::string reward_json = fetch( "http://" + BURST_SERVER + "/burst?requestType=getRewardRecipient&account=" + std::to_string( accountID() ) );

				uint64_t recipient = safe_strtoull( qJSON( reward_json, "rewardRecipient" ) );
				// std::cout << "Reward recipient for " << std::to_string(accountID()) << ": " << recipient << std::endl;

				reward_recipient( recipient );

				estimated_capacity( estimate_capacity() );
			}
		} else {
			std::cout << "Account::update_check called with account unknown to blockchain: " << std::to_string( accountID() ) << std::endl;
			std::cout << account_json << std::endl;
		}
	}
}


static const char initial_codeword[] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static const char gexp[] = {1, 2, 4, 8, 16, 5, 10, 20, 13, 26, 17, 7, 14, 28, 29, 31, 27, 19, 3, 6, 12, 24, 21, 15, 30, 25, 23, 11, 22, 9, 18, 1};
static const char glog[] = {0, 0, 1, 18, 2, 5, 19, 11, 3, 29, 6, 27, 20, 8, 12, 23, 4, 10, 30, 17, 7, 22, 28, 26, 21, 25, 9, 16, 13, 14, 24, 15};
static const char codeword_map[] = {3, 2, 1, 0, 7, 6, 5, 4, 13, 14, 15, 16, 12, 8, 9, 10, 11};
static const char alphabet[] = "23456789ABCDEFGHJKLMNPQRSTUVWXYZ";

#define BASE_32_LENGTH 13
#define BASE_10_LENGTH 20


static char gmult(char a, char b) {
    if (a == 0 || b == 0)
        return 0;

    char idx = (glog[a] + glog[b]) % 31;

    return gexp[idx];
}


STATIC std::string Account::accountID_to_RS_string( uint64_t accountID ) {
	if (accountID == 0)
		return "";

	// convert accountID into array of digits
	std::string plain_string = std::to_string( accountID );
	int length = plain_string.length();

	char plain_string_10[BASE_10_LENGTH];
	memset(plain_string_10, 0, BASE_10_LENGTH);

    for(int i = 0; i < length; i++)
        plain_string_10[i] = (char)plain_string[i] - (char)'0';

    int codeword_length = 0;
    char codeword[ sizeof(initial_codeword) ];
    memcpy(codeword, initial_codeword, sizeof(initial_codeword));

    do {  // base 10 to base 32 conversion
        int new_length = 0;
        int digit_32 = 0;

        for (int i = 0; i < length; i++) {
            digit_32 = digit_32 * 10 + plain_string_10[i];

            if (digit_32 >= 32) {
                plain_string_10[new_length] = digit_32 >> 5;
                digit_32 &= 31;
                new_length++;
            } else if (new_length > 0) {
                plain_string_10[new_length] = 0;
                new_length++;
            }
        }

        length = new_length;
        codeword[codeword_length] = digit_32;
        codeword_length++;
    } while(length > 0);

    char p[] = {0, 0, 0, 0};
    for (int i = BASE_32_LENGTH - 1; i >= 0; i--) {
        char fb = codeword[i] ^ p[3];
        p[3] = p[2] ^ gmult(30, fb);
        p[2] = p[1] ^ gmult(6, fb);
        p[1] = p[0] ^ gmult(9, fb);
        p[0] =        gmult(17, fb);
    }

    for(int i = 0; i<sizeof(p); i++)
    	codeword[BASE_32_LENGTH + i] = p[i];

    std::string account_RS_string;

    for (int i = 0; i < sizeof(initial_codeword); i++) {
        char codeword_index = codeword_map[i];
        char alphabet_index = codeword[codeword_index];

        account_RS_string += alphabet[alphabet_index];

        if ((i & 3) == 3 && i < 13)
            account_RS_string += "-";
    }

    return account_RS_string;
}
