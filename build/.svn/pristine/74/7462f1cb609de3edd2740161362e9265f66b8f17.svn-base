#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>

extern "C" {
	#include "shabal.h"
};

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


static volatile bool time_to_die = false;


// bleh this shouldn't be here
Handler *handler_factory() { return NULL; }



void blockchain_monitor() {
	// check for:
	// new block
	//		grab new mining info
	uint64_t blockID;
	uint64_t base_target;
	std::string gen_sig_str;
	uint8_t gen_sig[32];

	while(!time_to_die) {
		std::unique_ptr<Block> latest_block( Block::latest_block() );

		std::string mining_json = fetch( "http://" + BURST_SERVER + "/burst?requestType=getMiningInfo" );

		// decode
		blockID = safe_strtoull( qJSON( mining_json, "height" ) );
		base_target = safe_strtoull( qJSON( mining_json, "baseTarget" ) );
		gen_sig_str = qJSON( mining_json, "generationSignature" );

		if (blockID > latest_block->blockID() || ( !gen_sig_str.empty() && gen_sig_str != latest_block->gen_sig_str() ) ) {
			if ( blockID > latest_block->blockID() )
				std::cout << ftime() << "New block! Block: " << blockID << std::endl;
			else
				std::cout << ftime() << "Generation signature changed! Forked blockchain recoalescing?" << std::endl;

			Block::unpack_gen_sig_str( gen_sig_str, gen_sig );

			std::unique_ptr<Block> block( Block::load( blockID ) );
			if (!block) {
				block.reset( new Block() );
				block->blockID( blockID );
			}

			// shabal256 hash of gen_sig (in binary form) and then block number (uint64_t)
			shabal_context sc;

			shabal_init(&sc, 256);
			shabal(&sc, gen_sig, 32);

			uint64_t block_swapped = htobe64( blockID );
			shabal(&sc, &block_swapped, sizeof(block_swapped));

			uint8_t new_gen_sig[32];
			shabal_close(&sc, 0, 0, new_gen_sig);

			// finally we get to determine scoop number
			uint32_t scoop = ((new_gen_sig[30] & 0x0F) << 8) | new_gen_sig[31];

			std::cout << ftime() << "Block " << blockID << ", scoop " << scoop << ", base target " << base_target << std::endl;
			block->scoop( scoop );
			block->base_target( base_target );
			block->gen_sig_str( gen_sig_str );

			// unpack miningInfo JSON so we can add our fields
			cJSON *root = cJSON_Parse( mining_json.c_str() );
			if (root != NULL) {
				cJSON_AddNumberToObject( root, (char *)"targetDeadline", DEADLINE_MAX );
				// Unformatted is required for DCCT miner as it doesn't expect tabs between field name and value
				char *json = cJSON_PrintUnformatted(root);
				block->json( json );
				free(json);
				cJSON_Delete(root);
			}

			block->save();

			// find out number of potential miners
			std::string miners_json = fetch( "http://" + BURST_SERVER + "/burst?requestType=getAccountsWithRewardRecipient&account=" + std::to_string(OUR_ACCOUNT_ID) );

			std::cout << ftime() << "Our miners: " << miners_json << std::endl;

			cJSON *miners_root = cJSON_Parse( miners_json.c_str() );
			if (miners_root != NULL) {
				cJSON *accounts = cJSON_GetObjectItem( miners_root, "accounts" );

				if (accounts != NULL) {
					block->num_potential_miners( cJSON_GetArraySize( accounts ) );
					block->save();
				}

				cJSON_Delete(miners_root);
			}
		}

		sleep(1);
	}
};


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

	blockchain_monitor();

	std::cout << ftime() << "--- STOP ---" << std::endl;

	return 0;
}

