#include "IDB/where.h"

namespace IDB {
	class sqlLikeString: public Where {
		private:
			std::string			col;
			std::string			value;

		public:
			sqlLikeString(std::string eq_col, std::string eq_value): col(eq_col), value(eq_value) { };
			std::string toString();
			unsigned int bind(sql::PreparedStatement *pstmt, unsigned int bind_offset);
	};
}
