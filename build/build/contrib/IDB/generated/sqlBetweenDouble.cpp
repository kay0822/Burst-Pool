#include "betweenDouble.h"

#ifndef NO_SUCH_SQL

#include <vector>
#include <list>
#include "IDB/where.h"
#include <cppconn/prepared_statement.h>
#include "sqlBetweenDouble.h"

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif


namespace IDB { 
	sqlBetweenDouble::sqlBetweenDouble(std::string init_col, IDB_CXX_TYPE min_value, IDB_CXX_TYPE max_value) {
		col = init_col;
		min = min_value;
		max = max_value;
	}

	std::string sqlBetweenDouble::toString() {
		#ifndef BETWEEN_SQL
			return col + " between ? and ?";
		#else
			return BETWEEN_SQL;
		#endif
	}

	#ifndef NO_BIND_NEEDED
		unsigned int sqlBetweenDouble::bind(sql::PreparedStatement *pstmt, unsigned int bind_offset) {
			pstmt->setDouble(bind_offset++, min);
			pstmt->setDouble(bind_offset++, max);
	
			return bind_offset;
		}
	#endif
}

#endif
