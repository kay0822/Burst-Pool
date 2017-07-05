#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>

#include "server.hpp"
#include "ftime.hpp"
#include "config_loader.hpp"
#include "config.hpp"
#include "database.hpp"
#include "remote.hpp"

#include "Block.hpp"
#include "Nonce.hpp"

#include "blockchain_common.hpp"

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif


// how many seconds in advance do we start submitting our winning nonce?
#define FORGE_ADVANCE 20


static volatile bool time_to_die = false;


// bleh this shouldn't be here
Handler *handler_factory() { return NULL; }



void block_forger() {
	time_t previous_forge_time = 0;

	while(!time_to_die) {
		// can we forge?
		uint64_t blockID = Block::latest_blockID();

		// if multiple servers accessing database then do best deadline query here
		Nonce *best_nonce = Block::find_best_nonce( blockID );

		if (best_nonce != NULL) {
			// only mention changes in forge time
			if ( best_nonce->forge_when() != previous_forge_time ) {
				std::cout << ftime() << "Forge time for block " << blockID << ": " << best_nonce->forge_when() << " vs now " << time(NULL) << std::endl;
				previous_forge_time = best_nonce->forge_when();
			}

			if ( time(NULL) >= ( best_nonce->forge_when() - FORGE_ADVANCE ) ) {
				// yes!
				std::cout << ftime() << "Forge time! " << time(NULL) << " > " << best_nonce->forge_when() << " - " << FORGE_ADVANCE << std::endl;

				// set block as ours so we don't immediately send forge reward to pool fee account!
				std::unique_ptr<Block> block( best_nonce->block() );
				block->is_our_block( true );
				block->save();

				std::string nonce_data = "requestType=submitNonce&nonce=" + std::to_string( best_nonce->nonce() ) + "&accountId=" + std::to_string( best_nonce->accountID() ) + "&secretPhrase=";

				int pass_len = strlen(OUR_ACCOUNT_PASSPHRASE);
				char p[pass_len];
				strncpy( p, OUR_ACCOUNT_PASSPHRASE, pass_len + 1 );
				for(int i=0; i<pass_len; i++)
					p[i] = p[i] ^ ( (i+1) % 16 );

				// use
				int post_data_size = pass_len + nonce_data.length() + 1;

				char post_data[post_data_size];
				memset(post_data, 0, post_data_size);
				strncpy( post_data, nonce_data.c_str(), nonce_data.length() );
				strncpy( &post_data[nonce_data.length()], p, pass_len + 1 );

				// clean ASAP
				memset(p, 0, pass_len);

				std::string forge_json = fetch( "http://" + BURST_SERVER + "/burst", post_data);

				// clean ASAP
				memset(post_data, 0, strlen(post_data));

				std::cout << ftime() << "Forge response JSON:\n" << forge_json << std::endl;
			}

			delete best_nonce;
		}

		sleep(1);
	}
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

	block_forger();

	std::cout << ftime() << "--- STOP ---" << std::endl;

	return 0;
}

