#include "sqlIDB_OPCol.h"
#include "opIDB_OP.h"
#include <cppconn/prepared_statement.h>

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif


namespace IDB { 
	std::string sqlIDB_OPCol::toString() {
		std::string output;

		output = col + IDB_SQL_OP + col2;

		return output;
	}
}
