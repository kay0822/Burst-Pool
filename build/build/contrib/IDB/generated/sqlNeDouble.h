#include "IDB/where.h"

namespace IDB {
	class sqlNeDouble: public Where {
		private:
			std::string		col;
			double			value;

		public:
			sqlNeDouble(std::string init_col, double init_value): col(init_col), value(init_value) { };
			std::string toString();
			unsigned int bind(sql::PreparedStatement *pstmt, unsigned int bind_offset);
	};
}
