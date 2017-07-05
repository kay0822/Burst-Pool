#include "IDB/where.h"

namespace IDB {
	class sqlIDB_OPDouble: public Where {
		private:
			std::string		col;
			double			value;

		public:
			sqlIDB_OPDouble(std::string init_col, double init_value): col(init_col), value(init_value) { };
			std::string toString();
			unsigned int bind(sql::PreparedStatement *pstmt, unsigned int bind_offset);
	};
}
