#include "IDB/sqlIsNotNull.h"
#include <cppconn/prepared_statement.h>

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif


namespace IDB { 

	std::string sqlIsNotNull::toString() {
		std::string			output;

		output = col + " is not null";

		return output;
	}

}
