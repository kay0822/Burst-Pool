#include "IDB/where.h"
#include <vector>

namespace IDB {
	class sqlConcat: public Where {
		private:
			std::vector<std::string>			values;

		public:
			sqlConcat(std::vector<std::string> *strings);
			std::string toString();
			unsigned int bind(sql::PreparedStatement *pstmt, unsigned int bind_offset);
	};
}
