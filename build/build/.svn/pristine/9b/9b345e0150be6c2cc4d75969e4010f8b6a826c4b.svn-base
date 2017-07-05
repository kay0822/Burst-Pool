#include <curl/curl.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <iostream>

#include "remote.hpp"

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif



static size_t write_data( void *buffer, size_t size, size_t nmemb, std::string *output ) {
	size_t length = size * nmemb;
	output->append( (const char *) buffer, length );
	return length;
}


std::string fetch( std::string url, std::string post_data, std::string content_type, std::string auth ) {
	CURL *curl_handle = curl_easy_init();

	std::string output_string;
	struct curl_slist *headers = NULL;
	headers = curl_slist_append( headers, "Accept: application/json" );
	headers = curl_slist_append( headers, "Accept-Language: en_US" );
	if ( !content_type.empty() ) {
		content_type = "Content-Type: " + content_type;
		headers = curl_slist_append( headers, content_type.c_str() );
	}

	curl_easy_setopt( curl_handle, CURLOPT_URL, url.c_str() );
	curl_easy_setopt( curl_handle, CURLOPT_NOSIGNAL, (long) 1);
	curl_easy_setopt( curl_handle, CURLOPT_WRITEFUNCTION, write_data );
	curl_easy_setopt( curl_handle, CURLOPT_WRITEDATA, &output_string );
	curl_easy_setopt( curl_handle, CURLOPT_HTTPHEADER, headers );
	
	if ( ! auth.empty() ) {
		curl_easy_setopt( curl_handle, CURLOPT_USERPWD, auth.c_str() );
		curl_easy_setopt( curl_handle, CURLOPT_HTTPAUTH, CURLAUTH_BASIC );
	}

	if ( ! post_data.empty() )
		curl_easy_setopt( curl_handle, CURLOPT_POSTFIELDS, post_data.c_str() );

	CURLcode result = curl_easy_perform( curl_handle );
	if ( result != 0 )
		std::cout << "CURL error: " << curl_easy_strerror(result) << std::endl;

	curl_slist_free_all( headers );
	curl_easy_cleanup( curl_handle );

	return output_string;
}


std::string qJSON( cJSON *root, std::string param ) {
	cJSON *item = cJSON_GetObjectItem( root, param.c_str() );

	if (item != NULL) {
		if (item->type == 4)
			return item->valuestring;
		else if (item->type == 3)
			return std::to_string(item->valueint);
	}
	
	return "";
}


std::string qJSON( std::string json, std::string param ) {
	std::string result = "";

	cJSON *root = cJSON_Parse( json.c_str() );

	if (root == NULL)
		return result;

	result = qJSON( root, param );

	cJSON_Delete(root);

	return result;
}


std::string json_error( int err_num, std::string err_msg ) {
	return "{\"errorCode\":" + std::to_string(err_num) + ",\"errorDescription\":\"" + err_msg + "\"}";
}


uint64_t safe_strtoull( std::string s ) {
	return strtoull( s.c_str(), NULL, 10 );
}


std::string URL_encode( std::string data ) {
	size_t offset = data.length();

	while( ( offset = data.find_last_of("%?& <>\"\n\r=", offset) ) != std::string::npos ) {
		if ( data[offset] == ' ' )
			data[offset] = '+';
		else {
			char hex[3];
			sprintf( hex, "%02x", data[offset] );
			data.replace( offset, 1, "%" + std::string(hex) );
			// last char?
			if (offset == 0)
				break;

			// carry on
			offset--;
		}
	}

	return data;
}


void push_notification( std::string url, std::string key, std::string user, std::string message, std::string sound ) {
	std::string post_data = "token=" + key + "&user=" + user + "&message=" + message;
	if ( !sound.empty() )
		post_data += "&sound=" + sound;
		
	std::cout << fetch(url, post_data) << std::endl;
}
