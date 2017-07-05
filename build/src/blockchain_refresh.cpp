#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>

#include "server.hpp"
#include "ftime.hpp"
#include "config_loader.hpp"
#include "database.hpp"

#include "Block.hpp"

#include "blockchain_common.hpp"

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif


static volatile bool time_to_die = false;


// bleh this shouldn't be here
Handler *handler_factory() { return NULL; }



static void blockchain_refresh() {
	// wait for fresh block
	uint64_t current_blockID = Block::latest_blockID();

	std::cout << ftime() << "Waiting for block after " << current_blockID << "..." << std::endl;

	while( !time_to_die ) {
		uint64_t latest_blockID = Block::latest_blockID();

		if ( latest_blockID > current_blockID )
			break;

		sleep(2);
	}

	// go through all blocks and refresh data in case we missed something while we were down
	std::cout << ftime() << "Starting block refresh..." << std::endl;

	for(int blockID = current_blockID; !time_to_die && blockID > 0; blockID--) {
		uint64_t latest_blockID = Block::latest_blockID();

		if ( latest_blockID > current_blockID ) {
			// pause whole blockchain refresh to forcably refresh most recent blocks
			std::cout << ftime() << "New block so refreshing recent blocks..." << std::endl;

			for(int recent_blockID = current_blockID; !time_to_die && recent_blockID > current_blockID - 4; recent_blockID--) {
				refresh_previous_block( recent_blockID, true );
				sleep(1);
			}

			current_blockID = latest_blockID;
			std::cout << ftime() << "Carrying on whole blockchain refresh..." << std::endl;
		}

		refresh_previous_block( blockID, false );
		sleep(1);
	}

	std::cout << ftime() << "Ending block refresh..." << std::endl;
}


static void handle_signal(int sig) {
	std::cout << ftime() << "!!! Received sig " << sig << " !!!" << std::endl;
	time_to_die = true;
}


int main() {
	close(0);

	config_init();

	std::cout << ftime() << "--- START ---" << std::endl;

	database_init();

	signal( SIGCHLD, SIG_IGN );
	signal( SIGINT, handle_signal );
	signal( SIGTERM, handle_signal );

	IDB::Engine *idb = make_db_connection();
	IO::Object::set_engine( idb );

	blockchain_refresh();

	std::cout << ftime() << "--- STOP ---" << std::endl;

	return 0;
}
