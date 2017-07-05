#include <sstream>
#include <string>
#include "IDB/options.h"

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif


namespace IDB {
	std::string Options::toString() {
		std::string output;

		if ( !group_by.empty() )
			output += " GROUP BY " + group_by;

		if (having)
			output += " HAVING " + having->toString();

		if ( !order_by.empty() )
			output += " ORDER BY " + order_by;

		if (limit) {
			std::ostringstream ss;
			ss << limit;
			output += " LIMIT " + ss.str();
		}

		if (offset) {
			std::ostringstream ss;
			ss << offset;
			output += " OFFSET " + ss.str();
		}

		if (lock_in_share_mode)
			output += " LOCK IN SHARE MODE ";

		if (for_update)
			output += " FOR UPDATE ";

		return output;
	}

	unsigned int Options::bind(sql::PreparedStatement *pstmt, unsigned int bind_offset) {
		if (having)
			return having->bind(pstmt, bind_offset);

		return bind_offset;
	}


	Options::~Options() {
		if (having)
			delete having;
	}
}
