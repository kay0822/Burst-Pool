#include "IDB/sqlIsNull.h"
#include <cppconn/prepared_statement.h>

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif


namespace IDB { 

	std::string sqlIsNull::toString() {
		std::string			output;

		output = col + " is null";

		return output;
	}

}
