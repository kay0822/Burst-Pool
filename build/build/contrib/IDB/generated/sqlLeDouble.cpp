#include "sqlLeDouble.h"
#include "opLe.h"
#include <cppconn/prepared_statement.h>

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif


namespace IDB { 
	std::string sqlLeDouble::toString() {
		std::string			output;

		output = col + IDB_SQL_OP + "?";

		return output;
	}

	unsigned int sqlLeDouble::bind(sql::PreparedStatement *pstmt, unsigned int bind_offset) {
		pstmt->setDouble(bind_offset++, value);

		return bind_offset;
	}
}
