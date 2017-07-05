#include "IDB/where.h"

namespace IDB {
	class sqlLeNull: public Where {
		private:
			std::string			col;

		public:
			sqlLeNull(std::string init_col): col(init_col) { };
			std::string toString();
	};
}
