#include "PreppedSearch.h"

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif


namespace IO {
	PreppedSearch::~PreppedSearch() {
		if (cols) {
			delete cols;
		}
		if (tables && tables != IDB_NO_TABLES) {
			delete tables;
		}
		if (where && where != IDB_NO_WHERE) {
			delete where;
		}
		if (options && options != IDB_NO_OPTIONS) {
			delete options;
		}
	};
};
