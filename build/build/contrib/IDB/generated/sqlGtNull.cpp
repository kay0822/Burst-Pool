#include "sqlGtNull.h"
#include "opGt.h"
#include <cppconn/prepared_statement.h>

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif


namespace IDB { 
	std::string sqlGtNull::toString() {
		std::string			output;

		output = col + IDB_SQL_OP + "null";

		return output;
	}
}
