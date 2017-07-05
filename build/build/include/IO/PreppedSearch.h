#ifndef IO_PREPPED_SEARCH_INCLUDED
#define IO_PREPPED_SEARCH_INCLUDED

#include <IDB/IDB.h>
#include <vector>
#include <string>

namespace IO {
	class PreppedSearch {
		public:
			std::vector<std::string>	*cols;
			IDB::Tables					*tables;
			IDB::Where					*where;
			IDB::Options				*options;

			~PreppedSearch();
	};
};

#endif
