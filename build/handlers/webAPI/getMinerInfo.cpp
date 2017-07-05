#include "webAPI/getMinerInfo.hpp"

#include "mining-info.hpp"

#include "Nonce.hpp"
#include "Block.hpp"

#include "cJSON.hpp"


int Handlers::webAPI::getMinerInfo::process( struct MHD_Connection *connection, Request *req, Response *resp ) {
	// estimated miner hashrate / capacity

	// number of blocks this account has found through this pool


	return MHD_YES;
}
