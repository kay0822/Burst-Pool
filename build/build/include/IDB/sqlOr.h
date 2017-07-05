#include "IDB/where.h"

namespace IDB {
	class sqlOr: public Where {
		private:
			Where			*left;
			Where			*right;

		public:
			sqlOr(Where *new_left, Where *new_right): left(new_left), right(new_right) { };
			std::string toString();
			~sqlOr();
			unsigned int bind(sql::PreparedStatement *pstmt, unsigned int bind_offset);
	};
}
