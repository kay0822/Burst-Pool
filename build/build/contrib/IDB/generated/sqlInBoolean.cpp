#include <vector>
#include <list>
#include "IDB/where.h"
#include "sqlInBoolean.h"
#include "inBoolean.h"
#include <cppconn/prepared_statement.h>

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif


namespace IDB { 
	sqlInBoolean::sqlInBoolean(std::string init_col, std::vector<IDB_CXX_TYPE> *init_values) {
		col = init_col;
		for(int i=0; i < init_values->size(); i++) {
			values.push_back( init_values->at(i) );
		}
	}

	sqlInBoolean::sqlInBoolean(std::string init_col, std::list<IDB_CXX_TYPE> *init_values) {
		col = init_col;
		for(std::list<IDB_CXX_TYPE>::iterator it = init_values->begin(); it != init_values->end(); it++) {
			values.push_back( *it );
		}
	}

	std::string sqlInBoolean::toString() {
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
		unsigned int sqlInBoolean::bind(sql::PreparedStatement *pstmt, unsigned int bind_offset) {
			for(int i=0; i < values.size(); i++) {
				pstmt->setBoolean(bind_offset++, values[i]);
			}
	
			return bind_offset;
		}
	#endif
}
