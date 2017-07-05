#include "IDB/where.h"

namespace IDB {
	class sqlIsNull: public Where {
		private:
			std::string			col;

		public:
			sqlIsNull(std::string eq_col): col(eq_col) { };
			std::string toString();
	};
}
