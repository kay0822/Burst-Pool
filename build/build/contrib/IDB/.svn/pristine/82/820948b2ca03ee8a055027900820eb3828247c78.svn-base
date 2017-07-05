#include "IDB/sqlLikeString.h"
#include <cppconn/prepared_statement.h>

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif


namespace IDB { 

	std::string sqlLikeString::toString() {
		std::string		output;

		output = col + " like ?";

		return output;
	}

	unsigned int sqlLikeString::bind(sql::PreparedStatement *pstmt, unsigned int bind_offset) {
		pstmt->setString(bind_offset++, value);

		return bind_offset;
	}

}
