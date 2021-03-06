#include <cppconn/connection.h>
#include <vector>
#include <string>
#include "IDB/resultset.h"
#include "IDB/tables.h"
#include "IDB/options.h"

namespace IDB {

	class Engine {
		private:
			sql::Connection			*con;

		public:
			Engine(): con(NULL) { };
			Engine( sql::Connection *new_con ): con(new_con) { };
			~Engine();

			sql::Connection *connection();
			void connection( sql::Connection *new_con );
			long long int fetchInt( std::string col, IDB::Tables *tables, IDB::Where *where, IDB::Options *options );
			std::string fetchString( std::string col, IDB::Tables *tables, IDB::Where *where, IDB::Options *options );
			IDB::ResultSet *select( std::vector<std::string> *cols, IDB::Tables *tables, IDB::Where *where, IDB::Options *options );
			int writerow( std::string table, const std::vector<IDB::Where *> &updates );
			int writerow( std::string table, const std::vector<IDB::Where *> &inserts, const std::vector<IDB::Where *> &updates );
			int deleterow( std::string table, IDB::Where *where_clause );
			int execute( std::string sql );
			void thread_end();

			static std::string from_unixtime( time_t t );
			static time_t unix_timestamp( std::string ts );
	};

}
