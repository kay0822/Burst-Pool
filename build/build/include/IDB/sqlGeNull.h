#include "IDB/where.h"

namespace IDB {
	class sqlGeNull: public Where {
		private:
			std::string			col;

		public:
			sqlGeNull(std::string init_col): col(init_col) { };
			std::string toString();
	};
}
