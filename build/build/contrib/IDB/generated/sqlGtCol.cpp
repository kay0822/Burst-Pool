#include "sqlGtCol.h"
#include "opGt.h"
#include <cppconn/prepared_statement.h>

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif


namespace IDB { 
	std::string sqlGtCol::toString() {
		std::string output;

		output = col + IDB_SQL_OP + col2;

		return output;
	}
}
