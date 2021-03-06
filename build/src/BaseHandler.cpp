#include <curl/curl.h>

#include "Request.hpp"
#include "StaticHandler.hpp"
#include "StaticTemplateHandler.hpp"
#include "RegistryHandler.hpp"

#include "BaseHandler.hpp"

#include "handlers/handlers.hxx"
#include "templates/static-templates.hxx"

#include "config_loader.hpp"
#include "config.hpp"
#include "server.hpp"

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif


time_t BaseHandler::server_start_time;


Handler *handler_factory() { return new BaseHandler(); }


Handler *BaseHandler::route( struct MHD_Connection *connection, Request *req, Response *resp ) {
	// everything's ok - carry on
	return new RegistryHandler;
};


int BaseHandler::process_headers( struct MHD_Connection *connection, Request *req, Response *resp ) {
	// could fill in 'extra' stuff using headers

	return Handler::process_headers( connection, req, resp );
};


void BaseHandler::global_init() {
	server_start_time = time(NULL);

	StaticHandler::document_root = DOC_ROOT;

	// URL substrings are checked IN ORDER

	// import generated list of staff handlers...
	 using namespace Handlers;

	#include "handlers.cxx"

	RegistryHandler::register_handler<StaticHandler>( "/css" );
	RegistryHandler::register_handler<StaticHandler>( "/js" );
	RegistryHandler::register_handler<StaticHandler>( "/images" );
	RegistryHandler::register_handler<StaticHandler>( "/fonts" );
	RegistryHandler::register_handler<StaticHandler>( "/audio" );
	RegistryHandler::register_handler<StaticHandler>( "/favicon.ico" );
	RegistryHandler::register_handler<StaticHandler>( "/google" );
	RegistryHandler::register_handler<StaticHandler>( "/robots.txt" );

	RegistryHandler::register_handler<StaticTemplateHandler>( "/" );
	RegistryHandler::register_handler<StaticTemplateHandler>( "[root]" );

	// URL full-strings are checked IN ORDER
	#include "templates/static-templates.cxx"

	// this is a bit like a redirect!
	StaticTemplateHandler::register_template<Templates::home>( "/" );

	// extension -> mime-type mappings
	StaticHandler::register_mime_type( ".js", "text/javascript" );
	StaticHandler::register_mime_type( ".css", "text/css" );
	StaticHandler::register_mime_type( ".png", "image/png" );
	StaticHandler::register_mime_type( ".mp3", "audio/mpeg" );
	StaticHandler::register_mime_type( ".ttf", "application/x-font-truetype" );

	// init objects too!
	curl_global_init(CURL_GLOBAL_ALL);

	Handlers::webAPI::updates::init();
	Handlers::webAPI::discard::init();
}


void BaseHandler::global_shutdown() {
	// reverse order to above
	Handlers::webAPI::updates::shutdown();
	Handlers::webAPI::discard::shutdown();

	curl_global_cleanup();
}
