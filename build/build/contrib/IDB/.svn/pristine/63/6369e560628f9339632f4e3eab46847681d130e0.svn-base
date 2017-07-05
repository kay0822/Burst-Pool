#include "IDB/sqlAnd.h"
#include <cppconn/prepared_statement.h>

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif


namespace IDB {
	std::string sqlAnd::toString() {
		std::string			output;

		output = "(" + left->toString() + ") AND (" + right->toString() + ")";

		return output;
	}

	unsigned int sqlAnd::bind(sql::PreparedStatement *pstmt, unsigned int bind_offset) {
		bind_offset = left->bind(pstmt, bind_offset);
		bind_offset = right->bind(pstmt, bind_offset);

		return bind_offset;
	}

	sqlAnd::~sqlAnd() {
		delete left;
		delete right;
	}
}
