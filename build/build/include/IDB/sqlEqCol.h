#include "IDB/where.h"

namespace IDB {
	class sqlEqCol: public Where {
		private:
			std::string			col;
			std::string			col2;

		public:
			sqlEqCol(std::string init_col, std::string init_col2): col(init_col), col2(init_col2) { };
			std::string toString();
	};
}
