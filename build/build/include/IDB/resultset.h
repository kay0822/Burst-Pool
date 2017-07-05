#ifndef __IDB__RESULTSET
#define __IDB__RESULTSET

#include <cppconn/resultset.h>

namespace IDB {
	class ResultSet: public sql::ResultSet {
		public:
			time_t getTimestamp(uint32_t columnIndex);
	};
}

#endif
