#include "IDB/where.h"

namespace IDB {
	class sqlGtCol: public Where {
		private:
			std::string			col;
			std::string			col2;

		public:
			sqlGtCol(std::string init_col, std::string init_col2): col(init_col), col2(init_col2) { };
			std::string toString();
	};
}
