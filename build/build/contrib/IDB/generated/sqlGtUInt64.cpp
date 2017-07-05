#include "sqlGtUInt64.h"
#include "opGt.h"
#include <cppconn/prepared_statement.h>

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif


namespace IDB { 
	std::string sqlGtUInt64::toString() {
		std::string			output;

		output = col + IDB_SQL_OP + "?";

		return output;
	}

	unsigned int sqlGtUInt64::bind(sql::PreparedStatement *pstmt, unsigned int bind_offset) {
		pstmt->setUInt64(bind_offset++, value);

		return bind_offset;
	}
}
