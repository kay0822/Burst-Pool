// handler HPP - generated only if it doesn't exist

#ifndef __HANDLER__webAPI__pool
#define __HANDLER__webAPI__pool

#include "Handler.hpp"
#include "config.hpp"


	namespace Handlers {

	namespace webAPI {


#ifdef HANDLER_SUPERCLASS
class pool: public HANDLER_SUPERCLASS {
#else
class pool: public Handler {
#endif


	// custom stuff goes here!



	public:
		#include "webAPI/pool-inside.hxx"

};



	} // webAPI namespace

	} // Handlers namespace


#endif

