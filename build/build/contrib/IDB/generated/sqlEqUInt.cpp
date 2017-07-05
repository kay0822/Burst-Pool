#include "sqlEqUInt.h"
#include "opEq.h"
#include <cppconn/prepared_statement.h>

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif


namespace IDB { 
	std::string sqlEqUInt::toString() {
		std::string			output;

		output = col + IDB_SQL_OP + "?";

		return output;
	}

	unsigned int sqlEqUInt::bind(sql::PreparedStatement *pstmt, unsigned int bind_offset) {
		pstmt->setUInt(bind_offset++, value);

		return bind_offset;
	}
}
