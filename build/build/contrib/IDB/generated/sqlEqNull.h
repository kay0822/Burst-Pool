#include "IDB/where.h"

namespace IDB {
	class sqlEqNull: public Where {
		private:
			std::string			col;

		public:
			sqlEqNull(std::string init_col): col(init_col) { };
			std::string toString();
	};
}
