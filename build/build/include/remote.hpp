#ifndef REMOTE_HPP_
#define REMOTE_HPP_

#include <string>
#include <stdint.h>
#include "cJSON.hpp"

std::string fetch( std::string url, std::string post_data = "", std::string content_type = "", std::string auth = "" );
std::string qJSON( cJSON *root, std::string param );
std::string qJSON( std::string json, std::string param );
std::string json_error( int err_num, std::string err_msg );
uint64_t safe_strtoull( std::string s );
std::string URL_encode( std::string data );

void push_notification( std::string url, std::string key, std::string user, std::string message, std::string sound = "" );


#endif
