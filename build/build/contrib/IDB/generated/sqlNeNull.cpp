#include "sqlNeNull.h"
#include "opNe.h"
#include <cppconn/prepared_statement.h>

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif


namespace IDB { 
	std::string sqlNeNull::toString() {
		std::string			output;

		output = col + IDB_SQL_OP + "null";

		return output;
	}
}
