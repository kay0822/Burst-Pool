#include "IDB/engine.h"
#include "IDB/resultset.h"

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif


time_t IDB::ResultSet::getTimestamp( uint32_t columnIndex ) {
	return IDB::Engine::unix_timestamp( getString( columnIndex ) );
}
