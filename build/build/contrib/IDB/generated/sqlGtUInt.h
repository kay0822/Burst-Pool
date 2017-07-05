#include "IDB/where.h"

namespace IDB {
	class sqlGtUInt: public Where {
		private:
			std::string			col;
			unsigned long int	value;

		public:
			sqlGtUInt(std::string init_col, unsigned long int init_value): col(init_col), value(init_value) { };
			std::string toString();
			unsigned int bind(sql::PreparedStatement *pstmt, unsigned int bind_offset);
	};
}
