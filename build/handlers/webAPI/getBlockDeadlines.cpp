#include "webAPI/getBlockDeadlines.hpp"

#include "mining-info.hpp"

#include "Nonce.hpp"
#include "Block.hpp"

#include "cJSON.hpp"


int Handlers::webAPI::getBlockDeadlines::process( struct MHD_Connection *connection, Request *req, Response *resp ) {
	uint64_t latest_blockID = Block::latest_blockID();

	Nonce nonces;
	nonces.blockID( latest_blockID );
	nonces.is_accounts_best_deadline( true );
	uint64_t n_nonces = nonces.search();

	cJSON *array = cJSON_CreateArray();

	while( Nonce *nonce = nonces.result() ) {
		cJSON *entry = cJSON_CreateObject();
		cJSON_AddStringToObject( entry, (char *)"accountId", Account::accountID_to_RS_string( nonce->accountID() ).c_str() );
		cJSON_AddStringToObject( entry, (char *)"deadline", std::to_string( nonce->deadline() ).c_str() );
		cJSON_AddStringToObject( entry, (char *)"deadline_string", nonce->deadline_string().c_str() );
		cJSON_AddItemToArray(array, entry);
	}

	cJSON *root = cJSON_CreateObject();
	cJSON_AddNumberToObject( root, (char *)"block", latest_blockID );
	cJSON_AddItemToObject( root, (char *)"deadlines", array );

	char *json = cJSON_PrintUnformatted(root);

	resp->status_code = 200;
	resp->content = std::string(json);

	free(json);

	cJSON_Delete(root);

	return MHD_YES;
}
