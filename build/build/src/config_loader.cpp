#include <iostream>
#include <sstream>

#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "database.hpp"
#include "ftime.hpp"
#include "remote.hpp"
#include "config_loader.hpp"

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif

const char *CONFIG_FILE = "config.js";

// actual config storage with some defaults
int DB_POOL_SIZE = 10;
char *BIND_ADDRESS = (char *)NULL;
char *BIND_ADDRESS6 = (char *)NULL;
int LISTEN_PORT = 9999;
char *DOC_ROOT = (char *)"static";
char *LOG_FILE = (char *)"server.log";

char *DB_URI = (char *)"unix:///tmp/mysql.sock";
char *DB_SCHEMA = (char *)"test";
char *DB_USER = (char *)"root";
char *DB_PASSWORD = (char *)"";

bool HTTP_LOGGING = false;


char *config_item( cJSON *root, const char *valueName, bool mandatory ) {
	cJSON *item = cJSON_GetObjectItem(root, valueName);

	if (item == NULL) {
		if (mandatory) {
			std::cerr << "Config file missing '" << valueName << "' entry?" << std::endl;
			exit(2);
		} else {
			return NULL;
		}
	}

	if (item->type == 4)
		return strdup(item->valuestring);
	else if (item->type == 3)
		return strdup( std::to_string(item->valueint).c_str() );

	std::cerr << "Can't parse config file '" << valueName << "' entry?" << std::endl;
	exit(2);
}



void config_init() {
	struct stat sb;

	int fd = open(CONFIG_FILE, O_RDONLY);
	if (fd == -1) {
		perror("Can't open config file");
		exit(1);
	}

	int ret = fstat(fd, &sb);
	if (ret == -1) {
		perror("Can't stat config file");
		close(fd);
		exit(1);
	}

	char *config_buffer = (char *)malloc( sb.st_size );
	ret = read(fd, config_buffer, sb.st_size );
	close(fd);

	if (ret == -1) {
		free(config_buffer);
		perror("Can't read config file");
		exit(1);
	}

	cJSON *root = cJSON_Parse(config_buffer);
	free(config_buffer);

	if (root == NULL) {
		std::cerr << "Couldn't parse config file?" << std::endl;
		exit(2);
	}

	BIND_ADDRESS = config_item(root, "bindAddress", false);
	BIND_ADDRESS6 = config_item(root, "bindAddress6", false);

	if ( !BIND_ADDRESS && !BIND_ADDRESS6 ) {
		std::cerr << "Config file missing 'bindAddress' or 'bindAddress6'" << std::endl;
		exit(2);
	}

	LISTEN_PORT = safe_strtoull( config_item(root, "listenPort") );
	DOC_ROOT = config_item(root, "documentRoot");
	LOG_FILE = config_item(root, "logFile");
	DB_POOL_SIZE = safe_strtoull( config_item(root, "databasePoolSize") );
	DB_URI = config_item(root, "databaseURI");
	DB_SCHEMA = config_item(root, "databaseSchema");
	DB_USER = config_item(root, "databaseUser");
	DB_PASSWORD = config_item(root, "databasePassword");
	
	char *http_logging = config_item(root, "httpLogging", false);
	if (http_logging && std::string(http_logging) == "true")
		HTTP_LOGGING = true;

	more_config(root);

	cJSON_Delete(root);
}
