#include "IDB/where.h"

namespace IDB {
	class sqlGtNull: public Where {
		private:
			std::string			col;

		public:
			sqlGtNull(std::string init_col): col(init_col) { };
			std::string toString();
	};
}
