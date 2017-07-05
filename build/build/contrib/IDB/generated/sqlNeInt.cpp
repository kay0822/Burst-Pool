#include "sqlNeInt.h"
#include "opNe.h"
#include <cppconn/prepared_statement.h>

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif


namespace IDB { 
	std::string sqlNeInt::toString() {
		std::string			output;

		output = col + IDB_SQL_OP + "?";

		return output;
	}

	unsigned int sqlNeInt::bind(sql::PreparedStatement *pstmt, unsigned int bind_offset) {
		pstmt->setInt(bind_offset++, value);

		return bind_offset;
	}
}
