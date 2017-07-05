#include "webAPI/calcBlockShares.hpp"

#include "mining-info.hpp"
#include "remote.hpp"

#include "Nonce.hpp"
#include "Block.hpp"


int Handlers::webAPI::calcBlockShares::process( struct MHD_Connection *connection, Request *req, Response *resp ) {
	uint64_t blockID = safe_strtoull( req->form("blockID") );

	if (blockID) {
		Block::recalculate_shares(blockID);
	} else {
		Block blocks;
		blocks.search();

		while( Block *block = blocks.result() ) {
			Block::recalculate_shares( block->blockID() );
			delete block;
		}
	}

	return MHD_YES;
}
