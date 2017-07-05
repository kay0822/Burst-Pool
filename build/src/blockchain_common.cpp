#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>

#include "remote.hpp"
#include "server.hpp"
#include "cJSON.hpp"
#include "ftime.hpp"
#include "config.hpp"

#include "mining-info.hpp"

#include "Block.hpp"
#include "Nonce.hpp"

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif


void refresh_previous_block( uint64_t prev_blockID, bool force_refresh ) {
	Block *block = Block::load( prev_blockID );

	if (block == NULL) {
		// if block isn't in database then maybe no-one submitted a nonce for it!
		std::cout << ftime() << " Couldn't load previous block from database - no activity for previous block?" << std::endl;
		block = new Block();
		block->blockID( prev_blockID );
	}

	if (force_refresh || block->generator_account_id() == 0) {
		std::cout << ftime() << " Refreshing block: " << prev_blockID << std::endl;

		// grab info about previous block
		std::string block_json = fetch( "http://" + BURST_SERVER + "/burst?requestType=getBlock&height=" + std::to_string(prev_blockID) );

		uint64_t generator = safe_strtoull( qJSON( block_json, "generator" ) );

		if (generator) {
			uint64_t block_reward = safe_strtoull( qJSON( block_json, "blockReward" ) );
			uint64_t base_target = safe_strtoull( qJSON( block_json, "baseTarget" ) );
			uint64_t timestamp = safe_strtoull( qJSON( block_json, "timestamp" ) );
			uint64_t scoop = safe_strtoull( qJSON( block_json, "scoopNum" ) );
			uint64_t nonce = safe_strtoull( qJSON( block_json, "nonce" ) );
			std::string gen_sig_str = qJSON( block_json, "generationSignature" );

			block->generator_account_id( generator );
			block->block_reward( block_reward );
			block->base_target( base_target );
			block->forged_when( timestamp + GENESIS_TIMESTAMP );
			block->scoop( scoop );
			block->nonce( nonce );
			block->gen_sig_str( gen_sig_str );

			// calc deadline
			if (block->deadline() == 0) {
				uint64_t deadline = Nonce::calculate_deadline( generator, nonce, prev_blockID, scoop, base_target, gen_sig_str );
				block->deadline( deadline );
			}

			Nonce *best_nonce = Block::find_best_nonce( prev_blockID );

			if (best_nonce) {
				block->best_nonce_account_id( best_nonce->accountID() );
				block->our_best_deadline( best_nonce->deadline() );

				block->is_our_block( best_nonce->accountID() == generator );

				delete best_nonce;
			}

			block->save();
		}
	}

	delete block;
}


uint64_t send_pool_money( uint64_t accountID, uint64_t amount, std::string message ) {
	std::string payment_data = "requestType=sendMoney&recipient=" + std::to_string(accountID) + "&deadline=1440&amountNQT=" + std::to_string(amount) + "&feeNQT=" + std::to_string(PAYMENT_SEND_FEE);
	if ( !message.empty() )
		payment_data += "&messageIsText=true&message=" + URL_encode(message);
	payment_data += "&secretPhrase=";

	char *p = strdup(OUR_ACCOUNT_PASSPHRASE);
	for(int i=0; i<strlen(p); i++)
		p[i] = p[i] ^ ( (i+1) % 16 );

	// use
	int post_data_size = strlen(p) + payment_data.length() + 1;
	char *post_data = (char *)malloc( post_data_size );
	memset(post_data, 0, post_data_size);
	strncpy( post_data, payment_data.c_str(), payment_data.length() );
	strncpy( &post_data[payment_data.length()], p, strlen(p) );

	std::cout << ftime() << " Sending payment of " << (double)amount/BURST_TO_NQT << " to " << accountID << std::endl;

	std::string payment_json = fetch( "http://" + BURST_SERVER + "/burst", post_data);

	std::cout << ftime() << " Payment response JSON:\n" << payment_json << std::endl;

	// clean
	memset(p, 0, strlen(p));
	free(p);
	memset(post_data, 0, strlen(post_data));
	free(post_data);

	// if payment_json contains signatureHash then it's good
	if ( qJSON( payment_json, "signatureHash" ) != "" ) {
		// return tx id
		cJSON *root = cJSON_Parse( payment_json.c_str() );

		cJSON *tx_info = cJSON_GetObjectItem( root, (char *)"transactionJSON" );
		if (tx_info) {
			cJSON *tx_id_str = cJSON_GetObjectItem( tx_info, (char *)"transaction" );

			if (tx_id_str) {
				uint64_t tx_id = safe_strtoull( tx_id_str->valuestring );
				cJSON_Delete(root);
				return tx_id;
			} else {
				std::cout << ftime() << " No transaction in payment response JSON??" << std::endl;
			}
		} else {
			std::cout << ftime() << " No transactionJSON in payment response JSON??" << std::endl;
		}

		cJSON_Delete(root);
	} else {
		std::cout << ftime() << " No signatureHash in payment response JSON??" << std::endl;
	}

	// no good
	return 0;
}
