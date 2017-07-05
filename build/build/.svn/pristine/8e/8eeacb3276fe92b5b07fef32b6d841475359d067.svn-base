#ifndef __HTTP_COOKIE_HPP__
#define __HTTP_COOKIE_HPP__

#include <string>
#include <time.h>

class HTTP_Cookie {

	public:
		std::string					name;
		std::string					value;
		time_t						expires;
		std::string					path;
		std::string					domain;
		bool						secure;
		bool						http_only;
		
		HTTP_Cookie();

		std::string to_string();
};

#endif
