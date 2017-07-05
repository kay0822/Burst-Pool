#include "sqlIDB_OPString.h"
#include "opIDB_OP.h"
#include <cppconn/prepared_statement.h>

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif


namespace IDB { 
	std::string sqlIDB_OPString::toString() {
		std::string			output;

		output = col + IDB_SQL_OP + "?";

		return output;
	}

	unsigned int sqlIDB_OPString::bind(sql::PreparedStatement *pstmt, unsigned int bind_offset) {
		pstmt->setString(bind_offset++, value);

		return bind_offset;
	}
}
