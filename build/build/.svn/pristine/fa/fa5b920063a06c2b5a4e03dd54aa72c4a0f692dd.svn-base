#include "IDB/IDB.h"

extern char *DB_URI;
extern char *DB_USER;
extern char *DB_PASSWORD;
extern char *DB_SCHEMA;
extern int DB_POOL_SIZE;

IDB::Engine *make_db_connection();
IDB::Engine *request_db_connection();
void check_db_connection(IDB::Engine **idb);
void release_db_connection(IDB::Engine *idb);
void database_init();
void database_pool_init();
void database_shutdown();
