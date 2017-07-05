#include "sqlNeBoolean.h"
#include "opNe.h"
#include <cppconn/prepared_statement.h>

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif


namespace IDB { 
	std::string sqlNeBoolean::toString() {
		std::string			output;

		output = col + IDB_SQL_OP + "?";

		return output;
	}

	unsigned int sqlNeBoolean::bind(sql::PreparedStatement *pstmt, unsigned int bind_offset) {
		pstmt->setBoolean(bind_offset++, value);

		return bind_offset;
	}
}
