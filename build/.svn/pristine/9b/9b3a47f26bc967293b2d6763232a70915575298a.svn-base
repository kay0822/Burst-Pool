#include "Block.hpp"

#include "API/getMiningInfo.hpp"

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif


STATIC int Handlers::API::getMiningInfo::inner( struct MHD_Connection *connection, Request *req, Response *resp ) {
	std::unique_ptr<Block> latest_block( Block::latest_block() );

	resp->status_code = 200;
	resp->content = latest_block->json();

	return MHD_YES;
}


int Handlers::API::getMiningInfo::process( struct MHD_Connection *connection, Request *req, Response *resp ) {
	return inner(connection, req, resp);
}
