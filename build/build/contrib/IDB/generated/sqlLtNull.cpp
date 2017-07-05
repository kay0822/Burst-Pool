#include "sqlLtNull.h"
#include "opLt.h"
#include <cppconn/prepared_statement.h>

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif


namespace IDB { 
	std::string sqlLtNull::toString() {
		std::string			output;

		output = col + IDB_SQL_OP + "null";

		return output;
	}
}
