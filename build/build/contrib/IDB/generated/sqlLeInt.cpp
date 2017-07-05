#include "sqlLeInt.h"
#include "opLe.h"
#include <cppconn/prepared_statement.h>

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif


namespace IDB { 
	std::string sqlLeInt::toString() {
		std::string			output;

		output = col + IDB_SQL_OP + "?";

		return output;
	}

	unsigned int sqlLeInt::bind(sql::PreparedStatement *pstmt, unsigned int bind_offset) {
		pstmt->setInt(bind_offset++, value);

		return bind_offset;
	}
}
