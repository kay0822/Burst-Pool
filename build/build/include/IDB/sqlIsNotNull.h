#include "IDB/where.h"

namespace IDB {
	class sqlIsNotNull: public Where {
		private:
			std::string			col;

		public:
			sqlIsNotNull(std::string eq_col): col(eq_col) { };
			std::string toString();
	};
}
