#ifndef IDB_OPTIONS
#define IDB_OPTIONS 1

#include "IDB/where.h"

#include <cppconn/prepared_statement.h>

#define IDB_NO_OPTIONS (IDB::Options *)0

namespace IDB {
	class Options {
		public:
			std::string			group_by;
			IDB::Where			*having;
			std::string			order_by;
			unsigned int		limit;
			unsigned int		offset;
			bool				lock_in_share_mode;
			bool				for_update;
		
			Options(): having(IDB_NO_WHERE), limit(0), offset(0), lock_in_share_mode(false), for_update(false) {};
			std::string toString();
			unsigned int bind(sql::PreparedStatement *pstmt, unsigned int bind_offset);
			~Options();
	};
}

#endif
