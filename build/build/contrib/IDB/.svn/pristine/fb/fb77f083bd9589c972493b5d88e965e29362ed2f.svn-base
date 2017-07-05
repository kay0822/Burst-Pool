#include <vector>
#include <list>
#include "IDB/where.h"
#include "sqlInIDB_SQL_TYPE.h"
#include "inIDB_SQL_TYPE.h"
#include <cppconn/prepared_statement.h>

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif


namespace IDB { 
	sqlInIDB_SQL_TYPE::sqlInIDB_SQL_TYPE(std::string init_col, std::vector<IDB_CXX_TYPE> *init_values) {
		col = init_col;
		for(int i=0; i < init_values->size(); i++) {
			values.push_back( init_values->at(i) );
		}
	}

	sqlInIDB_SQL_TYPE::sqlInIDB_SQL_TYPE(std::string init_col, std::list<IDB_CXX_TYPE> *init_values) {
		col = init_col;
		for(std::list<IDB_CXX_TYPE>::iterator it = init_values->begin(); it != init_values->end(); it++) {
			values.push_back( *it );
		}
	}

	std::string sqlInIDB_SQL_TYPE::toString() {
		std::string		output;

		output = col + " in (";

		for(int i=0; i<values.size(); i++) {
			if ( i > 0 )
				output += ",";
				
			#ifndef IN_ARG
				output += "?";
			#else
				output += IN_ARG;
			#endif
		}

		output += ")";

		return output;
	}

	#ifndef NO_BIND_NEEDED
		unsigned int sqlInIDB_SQL_TYPE::bind(sql::PreparedStatement *pstmt, unsigned int bind_offset) {
			for(int i=0; i < values.size(); i++) {
				pstmt->setIDB_SQL_TYPE(bind_offset++, values[i]);
			}
	
			return bind_offset;
		}
	#endif
}
