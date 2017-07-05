#include "sqlLeString.h"
#include "opLe.h"
#include <cppconn/prepared_statement.h>

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif


namespace IDB { 
	std::string sqlLeString::toString() {
		std::string			output;

		output = col + IDB_SQL_OP + "?";

		return output;
	}

	unsigned int sqlLeString::bind(sql::PreparedStatement *pstmt, unsigned int bind_offset) {
		pstmt->setString(bind_offset++, value);

		return bind_offset;
	}
}
