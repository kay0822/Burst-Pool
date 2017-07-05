#ifndef __TEMPLATE_HPP__
#define __TEMPLATE_HPP__

#include "Request.hpp"

#include <string>
#include <list>
#include <map>

#include "time.h"

typedef std::map<unsigned long long int,const char *> sigfig_suffixes_t;
typedef std::pair<unsigned long long int,const char *> sigfig_suffix_tuple;

typedef std::string (*string_string_func_t)(std::string);

class Template {
	public:
		virtual ~Template();
		virtual std::string render() =0;
		
		static std::string HTML_escape( std::string str );
		static std::string HTML_escape_with_BRs( std::string str );
		static std::string JavaScript_escape( std::string str );
		static std::string URL_escape( std::string str );
		
		static std::string JS_quote( std::string str );
		
		static std::list<std::string> map( string_string_func_t fn, std::list<std::string> &items );
		static std::string join( std::string delimiter, std::list<std::string> items );
		static std::string join( const char delimiter[], std::list<std::string> items );

		static std::string pretty_bytesize( long long int value, char sigfig = 4 );
		static std::string pretty_size( long long int value, char sigfig = 4 );
		static std::string sigfig_suffix( long long int value, sigfig_suffixes_t *suffixes, char sigfig = 4 );
		static std::string pretty_price( double price, char sigfig = 2 );
		
		static std::string pretty_time( time_t time, std::string time_fmt = "" );
	
	protected:
		static std::string find_and_replace( std::string str, std::string find, std::string replace );
};

#endif
