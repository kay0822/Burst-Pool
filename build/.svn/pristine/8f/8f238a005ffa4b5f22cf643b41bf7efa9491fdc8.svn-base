#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <pthread_np.h>

#include "server.hpp"
#include "ftime.hpp"
#include "config_loader.hpp"
#include "database.hpp"

#include "Block.hpp"
#include "Nonce.hpp"

#include "blockchain_common.hpp"

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif

#define NUM_THREADS 10
// #define USE_LOCK


static volatile bool time_to_die = false;


// bleh this shouldn't be here
Handler *handler_factory() { return NULL; }



static void test_save_and_rank( Nonce *nonce ) {
#ifndef USE_LOCK
	IO::Object::start_transaction();
#else
	time_t before_lock = time(NULL);
	std::cout << ftime() << " thread " << pthread_getthreadid_np() << " locking 'nonce'" << std::endl;
	IO::Object::get_lock("nonce", 100);
	std::cout << ftime() << " thread " << pthread_getthreadid_np() << " locked 'nonce'" << std::endl;
	time_t after_lock = time(NULL);
#endif

	std::unique_ptr<Block> block( nonce->block() );

#ifndef USE_LOCK
	time_t before_lock = time(NULL);
	// stop other access to this Block info while we determine best nonces
	std::cout << ftime() << " thread " << pthread_getthreadid_np() << " locking block" << std::endl;
	block->lock_record();
	std::cout << ftime() << " thread " << pthread_getthreadid_np() << " locked block" << std::endl;
	time_t after_lock = time(NULL);
#endif

#if 0
	// refresh block data from database
	block->refresh();

	std::unique_ptr<Nonce> best_block_nonce( Nonce::get_best_block_nonce( nonce->blockID() ) );

	// if there's no existing best nonce for this block
	// OR this nonce's deadline is better than the existing best nonce...
	if ( !best_block_nonce || nonce->deadline() < best_block_nonce->deadline() ) {
		// ... then we are the new best nonce for this block
		nonce->is_blocks_best_deadline( true );
		block->our_best_deadline( nonce->deadline() );

		if (best_block_nonce) {
			// demote previous best
			best_block_nonce->is_blocks_best_deadline( false );
			best_block_nonce->save();

			// update Block if the best account has changed
			if ( nonce->accountID() != best_block_nonce->accountID() )
				block->best_nonce_account_id( nonce->accountID() );
		}

		block->save();
	}
#endif

	std::unique_ptr<Nonce> best_account_nonce( Nonce::get_best_account_nonce( nonce->blockID(), nonce->accountID() ) );

	std::cout << ftime() << " thread " << pthread_getthreadid_np() << " best_account_nonce = 0x" << std::hex << (uint64_t)(&*best_account_nonce) << std::dec << std::endl;

	// if this account has no best nonce for this block
	// OR this nonce's deadline is better than the existing account's best nonce...
	if ( !best_account_nonce || nonce->deadline() < best_account_nonce->deadline() ) {
		// ... then we are the new best nonce for this account (and block)
		nonce->is_accounts_best_deadline( true );

		if (best_account_nonce) {
			// demote previous best nonce for this account-block
			best_account_nonce->is_accounts_best_deadline( false );
			best_account_nonce->save();

			std::cout << ftime() << " thread " << pthread_getthreadid_np() << " account " << nonce->accountID() << ", block " << block->blockID() << " best deadline was " << best_account_nonce->deadline() <<
						" now " << nonce->deadline() << ", having waited for " << (after_lock - before_lock) << "s " << std::endl;
		} else {
			std::cout << ftime() << " thread " << pthread_getthreadid_np() << " account " << nonce->accountID() << ", block " << block->blockID() << " first best deadline " << nonce->deadline() <<
						", having waited for " << (after_lock - before_lock) << "s " << std::endl;
		}
	} else {
		std::cout << ftime() << " thread " << pthread_getthreadid_np() << " account " << nonce->accountID() << ", block " << block->blockID() << " best deadline STILL " << best_account_nonce->deadline() <<
					", having waited for " << (after_lock - before_lock) << "s " << std::endl;
		nonce->is_accounts_best_deadline( false );
	}

	nonce->save();

	Nonce best_account_nonces;
	best_account_nonces.accountID( nonce->accountID() );
	best_account_nonces.blockID( nonce->blockID() );
	best_account_nonces.is_accounts_best_deadline(true);
	std::cout << ftime() << " thread " << pthread_getthreadid_np() << " best account nonces count: " << best_account_nonces.count() << std::endl;

#ifndef USE_LOCK
	std::cout << ftime() << " thread " << pthread_getthreadid_np() << " commit" << std::endl;
	IO::Object::commit();
#else
	std::cout << ftime() << " thread " << pthread_getthreadid_np() << " releasing 'nonce' lock" << std::endl;
	IO::Object::release_lock("nonce");
#endif

	// Block::recalculate_shares( nonce->blockID() );
}


static void *nonce_stress(void *arg) {
	make_db_connection();

	while(!time_to_die) {
		// generate random nonce
		Nonce nonce;
		nonce.accountID(999);
		nonce.blockID(999);
		nonce.nonce( arc4random_uniform( 1<<31 ) );
		nonce.submitted_when( time(NULL) );
		nonce.deadline( arc4random_uniform( 1<<31 ) );
		nonce.deadline_string( "TEST" );
		nonce.forge_when( time(NULL) );

		// std::cout << ftime() << " thread " << pthread_getthreadid_np() << " deadline " << nonce.deadline() << " pre-save" << std::endl;
		test_save_and_rank( &nonce );
		// std::cout << ftime() << " thread " << pthread_getthreadid_np() << " deadline " << nonce.deadline() << " saved" << std::endl;

		sleep( arc4random_uniform(2) );
	}

	return NULL;
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

	std::vector<pthread_t> threads( NUM_THREADS );

	for(int i=0; i<NUM_THREADS; i++)
		pthread_create( &threads[i], NULL, nonce_stress, NULL );

	sleep(30);
	time_to_die = true;

	std::cout << ftime() << "--- STOP ---" << std::endl;

	return 0;
}
