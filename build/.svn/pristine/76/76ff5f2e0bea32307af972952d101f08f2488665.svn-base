#include "remote.hpp"

#include "burst.hpp"

#include "API/submitNonce.hpp"
#include "API/getMiningInfo.hpp"

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif


Handler *Handlers::burst::route( struct MHD_Connection *connection, Request *req, Response *resp ) {
	// if there's no Content-Type header we need to add it to appease libmicrohttpd
	if ( MHD_lookup_connection_value(connection, MHD_HEADER_KIND, MHD_HTTP_HEADER_CONTENT_TYPE) == NULL )
		MHD_set_connection_value(connection, MHD_HEADER_KIND, MHD_HTTP_HEADER_CONTENT_TYPE, (char *)"application/x-www-form-urlencoded");

	// no need for any more routing
	return NULL;
};



int Handlers::burst::process( struct MHD_Connection *connection, Request *req, Response *resp ) {
	// have we been given a requestType?
	std::string request_type = req->get_query_or_post("requestType");
	
	if (request_type == "getMiningInfo") {
		// call that
		return Handlers::API::getMiningInfo::inner( connection, req, resp );
	} else if (request_type == "submitNonce") {
		// call this
		return Handlers::API::submitNonce::inner( connection, req, resp );
	} else if ( !request_type.empty() ) {
		resp->status_code = 404;
		resp->content = json_error(1, "This Burst pool API endpoint only supports 'getMiningInfo' and 'submitNonce' requestTypes.");
	} else {
		resp->status_code = 400;
		resp->content = json_error(2, "This Burst pool API endpoint requires a 'requestType' argument.");
	}

	// done!
	return MHD_YES;
}
