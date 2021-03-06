#include <iostream>

#include "BitCoin.hpp"
#include "remote.hpp"

#include "ftime.hpp"

		
BitCoin::BitCoin( std::string srv ) {
	// does server have auth data in?
	size_t at_pos = srv.find('@');
	if (at_pos != std::string::npos) {
		server = srv.substr(at_pos + 1);
		server_auth = srv.substr(0, at_pos);
	} else {
		server = srv;
	}

	currency = "BTC";
}


std::string BitCoin::request( std::string method, cJSON *params ) {
	cJSON *root = cJSON_CreateObject();
	cJSON_AddStringToObject( root, (char *)"jsonrpc", (char *)"1.0" );
	cJSON_AddStringToObject( root, (char *)"id", (char *)"squirrels" );
	cJSON_AddStringToObject( root, (char *)"method", method.c_str() );

	if (!params)
		params = cJSON_CreateArray();

	cJSON_AddItemToObject( root, (char *)"params", params );

	char *json = cJSON_PrintUnformatted(root);

	#if DEBUG_BITCOIN > 1
		std::cout << "TO bitcoind: " << json << std::endl;
	#endif

	std::string response = fetch( "http://" + server, std::string(json), "text/plain", server_auth );
	free(json);

	#if DEBUG_BITCOIN > 1
		std::cout << "FROM bitcoind: " << response << std::endl;
	#endif

	// LOOK OUT! This will also delete any passed params
	cJSON_Delete(root);

	return response;
}


cJSON *BitCoin::get_vout( cJSON *result, uint64_t vout_index ) {
	cJSON *vout_array = cJSON_GetObjectItem( result, (char *)"vout" );
	
	if (vout_array) {
		uint64_t vout_size = cJSON_GetArraySize( vout_array );
		
		if (vout_index < vout_size)
			return cJSON_GetArrayItem( vout_array, vout_index );
	}
	
	// no luck
	return NULL;
}


std::string BitCoin::get_vout_address( cJSON *vout ) {
	cJSON *pub_script = cJSON_GetObjectItem( vout, (char *)"scriptPubKey" );
	
	if (pub_script) {
		cJSON *address_array = cJSON_GetObjectItem( pub_script, (char *)"addresses" );
		
		if (address_array)
			return  cJSON_GetArrayItem( address_array, 0 )->valuestring;
	}
	
	return "";
}


std::string BitCoin::get_transaction_json( std::string tx_hash ) {
	cJSON *tx_id = cJSON_CreateString( tx_hash.c_str() );
	cJSON *verbose = cJSON_CreateNumber( 1 );

	cJSON *params = cJSON_CreateArray();
	cJSON_AddItemToArray( params, tx_id );
	cJSON_AddItemToArray( params, verbose );

	return request( "getrawtransaction", params );
}



CryptoCoinTx *BitCoin::get_transaction( CryptoCoinTx *info_tx ) {
	// if info_tx has a recipient then use that as it's probably come from get_recent_transactionIDs
	// so we know the authoritative recipient rather than having to take a guess
	// ditto with amount, which is a bit worrying - so throw an error if we don't have pre-saved data
	if ( info_tx->recipient.empty() ) {
		// this is just BAD NEWS
		std::cerr << "Couldn't determine recipient for BitCoin tx " << info_tx->tx_id << std::endl;
		return NULL;			
	}

	std::string tx_json = get_transaction_json( info_tx->tx_id );
			
	cJSON *root = cJSON_Parse( tx_json.c_str() );
	cJSON *vin_root = NULL;
	
	if (root) {
		cJSON *result = cJSON_GetObjectItem( root, (char *)"result" );
		
		if (!result) {
			std::cout << "No transaction result?" << std::endl;
			goto bad_tx;
		}
		
		// use first vin address as "sender"
		// this is vin[0]->get_tx()->vout[0]->addresses[0]
		cJSON *vin_array = cJSON_GetObjectItem( result, (char *)"vin" );
		
		if (!vin_array) {
			std::cout << "No tx vin array?" << std::endl;
			goto bad_tx;
		}
		
		cJSON *vin = cJSON_GetArrayItem( vin_array, 0 );
		
		if (!vin) {
			std::cout << "No tx vin[0]?" << std::endl;
			goto bad_tx;
		}
		
		cJSON *vin_tx = cJSON_GetObjectItem( vin, (char *)"txid" );
		
		if (!vin_tx) {
			// could be "coinbase" transaction to reward block finder
			if ( !cJSON_GetObjectItem( vin, (char *)"coinbase" ) )
				std::cout << "No tx vin[0] txid and not coinbase?" << std::endl;
				
			goto bad_tx;
		}
		
		uint64_t vout_index = cJSON_GetObjectItem( vin, (char *)"vout" )->valueint;
		std::string vin_tx_hash = vin_tx->valuestring;
		std::string vin_tx_json = get_transaction_json( vin_tx_hash );
		vin_root = cJSON_Parse( vin_tx_json.c_str() );
		
		if (!vin_root) {
			std::cout << "No tx for tx's vin[0] txid?" << std::endl;
			goto bad_tx;
		}
		
		cJSON *vin_result = cJSON_GetObjectItem( vin_root, (char *)"result" );
		
		if (!vin_result) {
			std::cout << "No result for tx's vin[0] tx?" << std::endl;
			goto bad_tx;
		}

		cJSON *vin_vout = get_vout( vin_result, vout_index );
		
		if (!vin_vout) {
			std::cout << "No vout for tx's vin[0] tx?" << std::endl;
			goto bad_tx;
		}
		
		std::string vin_address = get_vout_address( vin_vout );
		
		if ( vin_address.empty() ) {
			std::cout << "No address for tx's vin[0] tx's vout?" << std::endl;
			goto bad_tx;
		}
		
		CryptoCoinTx *tx = new CryptoCoinTx;
		tx->currency = "BTC";
		tx->tx_id = info_tx->tx_id;
		tx->sender = vin_address;
		tx->recipient = info_tx->recipient;

		cJSON *tx_confirmations = cJSON_GetObjectItem( result, (char *)"confirmations" );
		if (tx_confirmations) 
			tx->confirmations = tx_confirmations->valueint;
		
		tx->amount = info_tx->amount;
		tx->int_to_float = int_to_float;
		tx->fee = 0; // not supported for now
		tx->fee_inclusive = false;
		
		#ifdef DEBUG_BITCOIN
			std::cout << "TX from " << tx->sender << " to " << tx->recipient << std::endl;
		#endif
		
		cJSON *tx_time = cJSON_GetObjectItem( result, (char *)"time" );
		
		if (tx_time)
			tx->crypto_timestamp = tx_time->valueint;
		else
			tx->crypto_timestamp = time(NULL);
		
		tx->unix_timestamp = tx->crypto_timestamp;

		cJSON_Delete(vin_root);
		cJSON_Delete(root);

		return tx;
	} else {
		std::cout << "No tx response?" << std::endl;
		goto bad_tx;
	}
	
	bad_tx:
	
	if (vin_root)
		cJSON_Delete(vin_root);
		
	if (root)
		cJSON_Delete(root);
	
	return NULL;
}


std::vector<CryptoCoinTx *> *BitCoin::get_recent_transactionIDs( std::string account, time_t unix_time, bool include_unconfirmed ) {
	std::vector<CryptoCoinTx *> *all_txs = new std::vector<CryptoCoinTx *>;

	// use "listtransactions" in blocks of 10 until timestamps are less than unix_time
	int batch_start = 0;
	const int batch_size = 10;
	bool more_batches = true;
	
	while( more_batches ) {
		// grab batch
		cJSON *account_json = cJSON_CreateString( account.c_str() );
		cJSON *batch_size_json = cJSON_CreateNumber( batch_size );
		cJSON *batch_start_json = cJSON_CreateNumber( batch_start );

		cJSON *params = cJSON_CreateArray();
		cJSON_AddItemToArray( params, account_json );
		cJSON_AddItemToArray( params, batch_size_json );
		cJSON_AddItemToArray( params, batch_start_json );
		
		std::string txs_json = request( "listtransactions", params ); 

		cJSON *root = cJSON_Parse( txs_json.c_str() );
		if (root) {
			cJSON *results = cJSON_GetObjectItem( root, (char *)"result");
			if (results) {
				batch_start += batch_size;
				
				int tx_count = cJSON_GetArraySize(results);
	
				for(int i=0; i<tx_count; i++) {
					cJSON *tx_info = cJSON_GetArrayItem(results, i);
					
					// receives only!
					std::string category = cJSON_GetObjectItem(tx_info, (char *)"category")->valuestring;
					if (category != "receive")
						continue;
					
					time_t tx_time = cJSON_GetObjectItem(tx_info, (char *)"time")->valueint;
					
					// before threshold? we don't want it 
					if (tx_time < unix_time) {
						more_batches = false;
						continue;
					}
	
					// filter out unconfirmed transaction?
					if ( !include_unconfirmed && cJSON_GetObjectItem(tx_info, (char *)"confirmations")->valueint == 0 )
						continue;
					
					CryptoCoinTx *tx = new CryptoCoinTx;
					tx->currency = "BTC";
					tx->tx_id = cJSON_GetObjectItem(tx_info, (char *)"txid")->valuestring;
					// save recipient here to prevent wrong guesses later
					tx->recipient = cJSON_GetObjectItem(tx_info, (char *)"account")->valuestring;
					// and amount
					tx->amount = cJSON_GetObjectItem(tx_info, (char *)"amount")->valuedouble * int_to_float;
					
					all_txs->push_back( tx );
				}
				
				// if we didn't receive a full batch of transactions then we've had them all
				if (tx_count < batch_size)
					more_batches = false;
			} else {
				// no results? maybe bitcoind starting up, etc.
				more_batches = false;
			}
				
			cJSON_Delete(root);
		} else {
			// couldn't parse? looks bad - let's bail out
			more_batches = false;
		}
	}
	
	return all_txs;
}


int BitCoin::get_confirmations( CryptoCoinTx *info_tx ) {
	std::string tx_json = get_transaction_json( info_tx->tx_id );
			
	cJSON *root = cJSON_Parse( tx_json.c_str() );
	
	if (root) {
		cJSON *result = cJSON_GetObjectItem( root, (char *)"result" );
		
		if (!result) {
			std::cout << "No transaction result?" << std::endl;
			goto bad_tx;
		}
		
		cJSON *tx_confirmations = cJSON_GetObjectItem( result, (char *)"confirmations" );
		if (tx_confirmations) {
			cJSON_Delete(root);
			return tx_confirmations->valueint;
		} else {
			// no confirmations yet
			cJSON_Delete(root);
			return 0;
		}
	}
	
	bad_tx:
	
	if (root)
		cJSON_Delete(root);
	
	return -1;	
}


bool BitCoin::send_transaction( CryptoCoinTx *tx ) {
	cJSON *sender = cJSON_CreateString( tx->sender.c_str() );
	cJSON *recipient = cJSON_CreateString( tx->recipient.c_str() );
	cJSON *amount = cJSON_CreateNumber( (double)(tx->amount) / (double)(int_to_float) );

	cJSON *params = cJSON_CreateArray();
	cJSON_AddItemToArray( params, sender );
	cJSON_AddItemToArray( params, recipient );
	cJSON_AddItemToArray( params, amount );
	
	std::string json = request( "sendfrom", params );
	
	cJSON *root = cJSON_Parse( json.c_str() );
	if (root) {
		cJSON *result = cJSON_GetObjectItem( root, (char *)"result" );
		
		if (!result) {
			std::cout << "No transaction result?" << std::endl;
			goto bad_tx;
		}
		
		cJSON *error = cJSON_GetObjectItem( root, "error" );
		if (error) {
			cJSON *message = cJSON_GetObjectItem( error, "message" );
			if (message) {
				std::cout << "Send failed: " << message->valuestring << std::endl;
				goto bad_tx;
			}
		}
		
		std::string tx_id = result->valuestring ? result->valuestring : "";
		
		if ( !tx_id.empty() ) { 
			tx->tx_id = tx_id; 
			cJSON_Delete(root);
			return true;
		}
	}

	bad_tx:
	
	if (root)
		cJSON_Delete(root);
	
	return false;
}
