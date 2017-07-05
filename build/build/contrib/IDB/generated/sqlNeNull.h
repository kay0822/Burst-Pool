#include "IDB/where.h"

namespace IDB {
	class sqlNeNull: public Where {
		private:
			std::string			col;

		public:
			sqlNeNull(std::string init_col): col(init_col) { };
			std::string toString();
	};
}
