#include "sqlEqDouble.h"
#include "opEq.h"
#include <cppconn/prepared_statement.h>

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif


namespace IDB { 
	std::string sqlEqDouble::toString() {
		std::string			output;

		output = col + IDB_SQL_OP + "?";

		return output;
	}

	unsigned int sqlEqDouble::bind(sql::PreparedStatement *pstmt, unsigned int bind_offset) {
		pstmt->setDouble(bind_offset++, value);

		return bind_offset;
	}
}
