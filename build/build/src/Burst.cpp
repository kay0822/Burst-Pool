#include <iostream>

#include "Burst.hpp"
#include "remote.hpp"
#include "cJSON.hpp"
#include "ftime.hpp"

// 21910633 = 21/04/2015 17:17:13 BST = 1429633033
// 21914722 = 21/04/2015 18:25:22 BST = 1429640722

// GMT: #define BURST_GENESIS_TIMESTAMP 1407722400
// BST: #define BURST_GENESIS_TIMESTAMP 1407726000
#define BURST_GENESIS_TIMESTAMP 1407722400

std::string Burst::get_transaction( uint64_t tx_id ) {
	return fetch( "http://" + server + "/burst?requestType=getTransaction&transaction=" + std::to_string(tx_id) );
}


std::vector<uint64_t> Burst::get_recent_transactions( std::string account, time_t unix_time, bool include_unconfirmed ) {
	std::vector<uint64_t> tx_ids;
	time_t burst_time = unix_to_burst_time( unix_time );

	// "timestamp" seems to be a block timestamp rather than a transaction's timestamp
	// so transactions appear in block-time-granulatity

	std::string monitor_URL = "http://" + server + "/burst?requestType=getAccountTransactionIds&account="
								+ account + "&timestamp=" + std::to_string(burst_time) + "&numberOfConfirmations=1";

	std::string response_json = fetch(monitor_URL);

	cJSON *root = cJSON_Parse( response_json.c_str() );

	if (root != NULL) {
		cJSON *tids = cJSON_GetObjectItem( root, "transactionIds" );

		if (tids != NULL) {
			int tids_length = cJSON_GetArraySize( tids );

			for(int i=0; i<tids_length; i++) {
				std::string tid = cJSON_GetArrayItem( tids, i )->valuestring;

				tx_ids.push_back( safe_strtoull(tid) );
			}
		}

		cJSON_Delete(root);
	} else {
		std::cerr << ftime() << __FUNCTION__ << "/confirmed no response from Burst server?" << std::endl;
	}

	if (include_unconfirmed) {
		monitor_URL = "http://" + server + "/burst?requestType=getUnconfirmedTransactionIds&account=" + account;

		response_json = fetch(monitor_URL);

		root = cJSON_Parse( response_json.c_str() );

		if (root != NULL) {
			cJSON *tids = cJSON_GetObjectItem( root, "unconfirmedTransactionIds" );

			if (tids != NULL) {
				int tids_length = cJSON_GetArraySize( tids );

				for(int i=0; i<tids_length; i++) {
					std::string tid = cJSON_GetArrayItem( tids, i )->valuestring;

					tx_ids.push_back( safe_strtoull(tid) );
				}
			}

			cJSON_Delete(root);
		} else {
			std::cerr << ftime() << __FUNCTION__ << "/unconfirmed no response from Burst server?" << std::endl;
		}
	}

	return tx_ids;
}


int Burst::get_confirmations( uint64_t tx_id ) {
	// if we can't find it then it's lost and we should re-pay
	std::string tx_json = fetch( "http://" + server + "/burst?requestType=getTransaction&transaction=" + std::to_string(tx_id) );

	if ( qJSON( tx_json, "errorCode") == "5" ) {
		// lost...
		return -1;
	} else {
		std::string confirmations = qJSON( tx_json, "confirmations" );

		if ( !confirmations.empty() )
			return safe_strtoull( confirmations );
	}

	// no info yet
	return 0;
}


uint64_t Burst::send_money( const char *encoded_passphrase, std::string account, uint64_t amountNQT, bool subtract_fee, std::string message ) {
	// don't even try to send zero amount
	if ( !amountNQT )
		return 0;

	// fee is amount / 1000
	uint64_t fee = ( ( (amountNQT / BURST_TO_NQT) - 1 ) / 1000 + 1) * BURST_TO_NQT;

	std::string payment_data = "requestType=sendMoney&recipient=" + account + "&deadline=1440&amountNQT=" + std::to_string(amountNQT) + "&feeNQT=" + std::to_string(fee);

	if ( !message.empty() )
		payment_data += "&messageIsText=true&message=" + URL_encode(message);

	payment_data += "&secretPhrase=";

	int pass_len = strlen(encoded_passphrase);
	char pass[pass_len];
	memset(pass, 0, pass_len + 1);

	for(int i=0; i<pass_len; i++)
		pass[i] = encoded_passphrase[i] ^ ( (i+1) % 16 );

	// use
	int post_data_size = pass_len + payment_data.length() + 1;
	char post_data[post_data_size];
	memset(post_data, 0, post_data_size);

	strcpy( post_data, payment_data.c_str() );
	strcpy( &post_data[ payment_data.length() ], pass );

	// clean
	memset(pass, 0, pass_len);

	std::cout << ftime() << "Sending payment of " << (double)(amountNQT/BURST_TO_NQT) << " to " << account << std::endl;

	std::string payment_json = fetch( "http://" + server + "/burst", post_data);

	std::cout << ftime() << "Payment response JSON:\n" << payment_json << std::endl;

	// clean
	memset(post_data, 0, post_data_size);

	// if payment_json contains signatureHash then it's good
	if ( qJSON( payment_json, "signatureHash" ) != "" ) {
		// return tx id
		cJSON *root = cJSON_Parse( payment_json.c_str() );

		cJSON *tx_info = cJSON_GetObjectItem( root, (char *)"transactionJSON" );
		if (tx_info) {
			cJSON *tx_id_str = cJSON_GetObjectItem( tx_info, (char *)"transaction" );

			if (tx_id_str) {
				// success!
				uint64_t tx_id = safe_strtoull( tx_id_str->valuestring );

				cJSON_Delete(root);

				return tx_id;
			} else {
				std::cout << ftime() << "No transaction in payment response JSON??" << std::endl;
			}
		} else {
			std::cout << ftime() << "No transactionJSON in payment response JSON??" << std::endl;
		}

		cJSON_Delete(root);
	} else {
		std::cout << ftime() << "No signatureHash in payment response JSON??" << std::endl;
	}

	// no good
	return 0;
}


time_t Burst::unix_to_burst_time(time_t unix_time) {
	return unix_time - BURST_GENESIS_TIMESTAMP;
}


time_t Burst::burst_to_unix_time(time_t burst_time) {
	return burst_time + BURST_GENESIS_TIMESTAMP;
}
