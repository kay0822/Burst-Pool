#include "IDB/where.h"

namespace IDB {
	class sqlAnd: public Where {
		private:
			Where			*left;
			Where			*right;

		public:
			sqlAnd(Where *new_left, Where *new_right): left(new_left), right(new_right) { };
			~sqlAnd();
			std::string toString();
			unsigned int bind(sql::PreparedStatement *pstmt, unsigned int bind_offset);
	};
}
