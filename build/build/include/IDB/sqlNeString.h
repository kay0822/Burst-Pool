#include "IDB/where.h"

namespace IDB {
	class sqlNeString: public Where {
		private:
			std::string			col;
			std::string			value;

		public:
			sqlNeString(std::string init_col, std::string init_value): col(init_col), value(init_value) { };
			std::string toString();
			unsigned int bind(sql::PreparedStatement *pstmt, unsigned int bind_offset);
	};
}
