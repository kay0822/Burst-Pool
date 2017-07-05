#include "Handler.hpp"

#include <string>
#include <map>
#include <sys/stat.h>

typedef std::map< std::string, std::string > mime_type_map_t;

class StaticHandler: public Handler {
	public:
		static std::string document_root;
	
		virtual int process_headers( struct MHD_Connection *connection, Request *req, Response *resp );
		virtual int process( struct MHD_Connection *connection, Request *req, Response *resp );

		static void register_mime_type( std::string ext, std::string mime_type );

	private:
		static mime_type_map_t		mime_type_map;
		std::string					safe_url;
		struct stat					file_sb;
		std::string					e_tag;

		int untaint_url( std::string tainted_url );
};
