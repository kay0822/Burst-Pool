#include "IDB/where.h"

namespace IDB {
	class sqlIDB_OPBoolean: public Where {
		private:
			std::string		col;
			bool			value;

		public:
			sqlIDB_OPBoolean(std::string init_col, bool init_value): col(init_col), value(init_value) { };
			std::string toString();
			unsigned int bind(sql::PreparedStatement *pstmt, unsigned int bind_offset);
	};
}
