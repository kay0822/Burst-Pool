#include "sqlLtString.h"
#include "opLt.h"
#include <cppconn/prepared_statement.h>

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif


namespace IDB { 
	std::string sqlLtString::toString() {
		std::string			output;

		output = col + IDB_SQL_OP + "?";

		return output;
	}

	unsigned int sqlLtString::bind(sql::PreparedStatement *pstmt, unsigned int bind_offset) {
		pstmt->setString(bind_offset++, value);

		return bind_offset;
	}
}
