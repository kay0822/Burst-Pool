#include "sqlLtUInt.h"
#include "opLt.h"
#include <cppconn/prepared_statement.h>

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif


namespace IDB { 
	std::string sqlLtUInt::toString() {
		std::string			output;

		output = col + IDB_SQL_OP + "?";

		return output;
	}

	unsigned int sqlLtUInt::bind(sql::PreparedStatement *pstmt, unsigned int bind_offset) {
		pstmt->setUInt(bind_offset++, value);

		return bind_offset;
	}
}
