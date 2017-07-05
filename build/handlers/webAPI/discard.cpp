#include <string.h>

#include "webAPI/discard.hpp"

#include "WebSocket.hpp"


#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif


WEBSOCKET_HANDLER_INIT(Handlers::webAPI::discard, "discard");


Handlers::webAPI::discard::discard() {
	std::cout << "discard constructor" << std::endl;
}


void Handlers::webAPI::discard::init() {
	std::cout << "discard init" << std::endl;
	WebSocketHandler::init();
}
