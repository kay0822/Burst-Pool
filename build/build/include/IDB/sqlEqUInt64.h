#include "IDB/where.h"

namespace IDB {
	class sqlEqUInt64: public Where {
		private:
			std::string				col;
			unsigned long long int	value;

		public:
			sqlEqUInt64(std::string init_col, unsigned long long int init_value): col(init_col), value(init_value) { };
			std::string toString();
			unsigned int bind(sql::PreparedStatement *pstmt, unsigned int bind_offset);
	};
}
