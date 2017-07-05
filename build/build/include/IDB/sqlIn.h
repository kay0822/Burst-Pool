#include "inIDB_SQL_TYPE.h"

namespace IDB {
	class sqlInIDB_SQL_TYPE: public Where {
		private:
			std::string						col;
			std::vector<IDB_CXX_TYPE>		values;

		public:
			sqlInIDB_SQL_TYPE(std::string init_col, std::vector<IDB_CXX_TYPE> *init_values);
			sqlInIDB_SQL_TYPE(std::string init_col, std::list<IDB_CXX_TYPE> *init_values);
			std::string toString();
			
			#ifndef NO_BIND_NEEDED
				unsigned int bind(sql::PreparedStatement *pstmt, unsigned int bind_offset);
			#endif
	};
}
