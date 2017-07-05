#include <iostream>

#include "BurstCoin.hpp"
#include "remote.hpp"

#include "ftime.hpp"


static const uint64_t BURST_GENESIS_TIMESTAMP = 1407722400UL;

		
BurstCoin::BurstCoin( std::string srv ) {
	server = srv;
	currency = "BURST";
}


time_t BurstCoin::crypto_to_unix_time( uint64_t crypto_time ) {
	return crypto_time + BURST_GENESIS_TIMESTAMP;
}


uint64_t BurstCoin::unix_to_crypto_time( time_t unix_time ) {
	return unix_time - BURST_GENESIS_TIMESTAMP;
}


std::vector<CryptoCoinTx *> *BurstCoin::get_recent_transactionIDs( std::string account, time_t unix_time, bool include_unconfirmed ) {
	auto all_txs = new std::vector<CryptoCoinTx *>;

	uint64_t burst_time = unix_to_crypto_time( unix_time );

	// "timestamp" seems to be a block timestamp rather than a transaction's timestamp
	// so transactions appear in block-time-granularity

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
				
				CryptoCoinTx *tx = new CryptoCoinTx;
				tx->currency = "BURST";
				tx->tx_id = tid;

				all_txs->push_back( tx );
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

					CryptoCoinTx *tx = new CryptoCoinTx;
					tx->currency = "BURST";
					tx->tx_id = tid;
	
					all_txs->push_back( tx );
				}
			}

			cJSON_Delete(root);
		} else {
			std::cerr << ftime() << __FUNCTION__ << "/unconfirmed no response from Burst server?" << std::endl;
		}
	}

	return all_txs;
}




CryptoCoinTx *BurstCoin::get_transaction( CryptoCoinTx *info_tx ) {
	std::string tx_json = fetch( "http://" + server + "/burst?requestType=getTransaction&transaction=" + info_tx->tx_id );
	
	if ( tx_json.empty() )
		return NULL;
	
	cJSON *root = cJSON_Parse( tx_json.c_str() );
	
	if ( root == NULL )
		return NULL;
	
	cJSON *subtype = cJSON_GetObjectItem( root, "subtype" ); 	
	if ( subtype && subtype->valueint == 0 ) {
		CryptoCoinTx *tx = new CryptoCoinTx;
		tx->currency = "BURST";
		tx->tx_id = info_tx->tx_id;
		
		tx->sender = cJSON_GetObjectItem( root, (char *)"senderRS" )->valuestring;
		tx->recipient = cJSON_GetObjectItem( root, (char *)"recipientRS" )->valuestring;
	
		cJSON *tx_confirmations = cJSON_GetObjectItem( root, (char *)"confirmations" );
		if (tx_confirmations) 
			tx->confirmations = tx_confirmations->valueint;
		
		tx->amount = safe_strtoull( cJSON_GetObjectItem( root, "amountNQT" )->valuestring );
		tx->int_to_float = int_to_float;
		
		tx->fee = 0; // not supported for now
		tx->fee_inclusive = false;


		cJSON *attachment = cJSON_GetObjectItem( root, "attachment" );
		if (attachment != NULL) {
			cJSON *messageJSON = cJSON_GetObjectItem( attachment, "message" );
			if (messageJSON != NULL)
				tx->message = messageJSON->valuestring;
		}

		#ifdef DEBUG_BURSTCOIN
			std::cout << "TX from " << tx->sender << " to " << tx->recipient << std::endl;
		#endif
		
		cJSON *tx_time = cJSON_GetObjectItem( root, (char *)"timestamp" );
		if (tx_time) {
			tx->crypto_timestamp = tx_time->valueint;
			tx->unix_timestamp = crypto_to_unix_time( tx->crypto_timestamp );
		} else {
			tx->unix_timestamp = time(NULL);
			tx->crypto_timestamp = unix_to_crypto_time( tx->unix_timestamp );
		}

		cJSON_Delete(root);
		return tx;
	}
	
	bad_tx:
	
	cJSON_Delete(root);
	return NULL;	
}


bool BurstCoin::send_transaction( CryptoCoinTx *tx ) {
	// don't even try to send zero amount
	if ( tx->amount <= 0 )
		return false;

	// fee is amount / 1000
	uint64_t fee = ( ( (tx->amount / int_to_float) - 1 ) / 1000 + 1) * int_to_float;

	std::string payment_data = "requestType=sendMoney&recipient=" + tx->recipient + "&deadline=1440&amountNQT=" + std::to_string(tx->amount) + "&feeNQT=" + std::to_string(fee);

	if ( !tx->message.empty() )
		payment_data += "&messageIsText=true&message=" + URL_encode(tx->message);

	payment_data += "&secretPhrase=";

	int pass_len = tx->encoded_passphrase.size();
	char pass[pass_len];
	memset(pass, 0, pass_len + 1);

	for(int i=0; i<pass_len; i++)
		pass[i] = tx->encoded_passphrase[i] ^ ( (i+1) % 16 );

	// use
	int post_data_size = pass_len + payment_data.length() + 1;
	char post_data[post_data_size];
	memset(post_data, 0, post_data_size);

	strcpy( post_data, payment_data.c_str() );
	strcpy( &post_data[ payment_data.length() ], pass );

	// clean
	memset(pass, 0, pass_len);

	std::cout << ftime() << "Sending payment of " << (double)(tx->amount/int_to_float) << " to " << tx->recipient << std::endl;

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
				tx->tx_id = tx_id_str->valuestring;
				tx->fee = fee;
				tx->fee_inclusive = false;

				cJSON_Delete(root);

				return true;
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
	return false;
}
