#include "IDB/where.h"

namespace IDB {
	class sqlIDB_OPNull: public Where {
		private:
			std::string			col;

		public:
			sqlIDB_OPNull(std::string init_col): col(init_col) { };
			std::string toString();
	};
}
