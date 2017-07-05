#include "IDB/sqlOr.h"
#include <cppconn/prepared_statement.h>

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif


namespace IDB {

	std::string sqlOr::toString() {
		std::string			output;

		output = "(" + left->toString() + ") OR (" + right->toString() + ")";

		return output;
	}

	unsigned int sqlOr::bind(sql::PreparedStatement *pstmt, unsigned int bind_offset) {
		bind_offset = left->bind(pstmt, bind_offset);
		bind_offset = right->bind(pstmt, bind_offset);

		return bind_offset;
	}

	sqlOr::~sqlOr() {
		delete left;
		delete right;
	}
}
