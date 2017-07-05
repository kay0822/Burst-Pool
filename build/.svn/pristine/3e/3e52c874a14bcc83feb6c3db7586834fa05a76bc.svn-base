#include "webAPI/genBlockRewards.hpp"

#include "mining-info.hpp"

#include "Nonce.hpp"
#include "Block.hpp"


int Handlers::webAPI::genBlockRewards::process( struct MHD_Connection *connection, Request *req, Response *resp ) {
	Block blocks;
	blocks.is_our_block(true);
	blocks.has_been_shared(false);
	blocks.search();

	while( Block *block = blocks.result() ) {
		block->reward_miners();
		delete block;
	}

	return MHD_YES;
}
