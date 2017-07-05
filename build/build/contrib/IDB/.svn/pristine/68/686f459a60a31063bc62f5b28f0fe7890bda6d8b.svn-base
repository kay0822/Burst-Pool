#ifndef IDB_WHERE
#define IDB_WHERE 1

#include <cppconn/prepared_statement.h>
#include <string>

#define IDB_NO_WHERE (IDB::Where *)0

namespace IDB {
	class Where {
		public:
			virtual std::string toString() =0;
			virtual unsigned int bind(sql::PreparedStatement *pstmt, unsigned int bind_offset);
			virtual ~Where() { };
	};
}

#endif
