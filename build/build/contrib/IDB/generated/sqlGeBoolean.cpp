#include "sqlGeBoolean.h"
#include "opGe.h"
#include <cppconn/prepared_statement.h>

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif


namespace IDB { 
	std::string sqlGeBoolean::toString() {
		std::string			output;

		output = col + IDB_SQL_OP + "?";

		return output;
	}

	unsigned int sqlGeBoolean::bind(sql::PreparedStatement *pstmt, unsigned int bind_offset) {
		pstmt->setBoolean(bind_offset++, value);

		return bind_offset;
	}
}
