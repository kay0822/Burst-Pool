#include "IDB/sqlSHA.h"
#include <cppconn/prepared_statement.h>

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif


namespace IDB { 
	std::string sqlSHA::toString() {
		std::string		output;
		std::string		delimiter = "";

		output = sha_col + " = SHA2( CONCAT( ?, " + sha_salt_col + ", ? ), 256 )";

		return output;
	}

	unsigned int sqlSHA::bind(sql::PreparedStatement *pstmt, unsigned int bind_offset) {
		pstmt->setString(bind_offset++, sha_salt);
		pstmt->setString(bind_offset++, sha_plaintext);

		return bind_offset;
	}
}
