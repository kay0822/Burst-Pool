#include "betweenIDB_SQL_TYPE.h"

#ifndef NO_SUCH_SQL

namespace IDB {
	class sqlBetweenIDB_SQL_TYPE: public Where {
		private:
			std::string						col;
			IDB_CXX_TYPE					min, max;

		public:
			sqlBetweenIDB_SQL_TYPE(std::string init_col, IDB_CXX_TYPE min_value, IDB_CXX_TYPE max_value);
			std::string toString();
			
			#ifndef NO_BIND_NEEDED
				unsigned int bind(sql::PreparedStatement *pstmt, unsigned int bind_offset);
			#endif
	};
}

#endif
