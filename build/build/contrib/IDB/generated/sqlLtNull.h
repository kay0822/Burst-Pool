#include "IDB/where.h"

namespace IDB {
	class sqlLtNull: public Where {
		private:
			std::string			col;

		public:
			sqlLtNull(std::string init_col): col(init_col) { };
			std::string toString();
	};
}
