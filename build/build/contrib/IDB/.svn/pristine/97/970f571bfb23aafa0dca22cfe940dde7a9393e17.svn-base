#include "IDB/where.h"
#include <vector>

namespace IDB {
	class sqlSHA: public Where {
		private:
			std::string					sha_col;
			std::string					sha_salt;
			std::string					sha_salt_col;
			std::string					sha_plaintext;

		public:
			sqlSHA(std::string col, std::string salt, std::string salt_col, std::string plaintext): \
				sha_col(col), sha_salt(salt), sha_salt_col(salt_col), sha_plaintext(plaintext) { };
			std::string toString();
			unsigned int bind(sql::PreparedStatement *pstmt, unsigned int bind_offset);
	};
}
