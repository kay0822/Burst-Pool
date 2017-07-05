#include "IDB/where.h"

namespace IDB {
	class sqlEqBoolean: public Where {
		private:
			std::string		col;
			bool			value;

		public:
			sqlEqBoolean(std::string init_col, bool init_value): col(init_col), value(init_value) { };
			std::string toString();
			unsigned int bind(sql::PreparedStatement *pstmt, unsigned int bind_offset);
	};
}
