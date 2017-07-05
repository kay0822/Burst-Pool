#include "IDB/where.h"

namespace IDB {
	class sqlLeDouble: public Where {
		private:
			std::string		col;
			double			value;

		public:
			sqlLeDouble(std::string init_col, double init_value): col(init_col), value(init_value) { };
			std::string toString();
			unsigned int bind(sql::PreparedStatement *pstmt, unsigned int bind_offset);
	};
}
