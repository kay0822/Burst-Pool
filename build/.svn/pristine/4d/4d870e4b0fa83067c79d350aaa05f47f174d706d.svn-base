#include "remote.hpp"
#include "cJSON.hpp"
#include "mining-info.hpp"

#include "webAPI/pool.hpp"

#include "Block.hpp"
#include "BaseHandler.hpp"

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif


/*
 * {
 *  "current":
 * 		{"block":82892,"noncesSubmitted":276,"minersResponded":87,"bestDeadline":3600,"difficulty":1231321,"startedWhen":198239183},
 * 	"previous":
 * 		{"block":82891,"noncesSubmitted":285,"minersResponded":86,"winningDeadline":13,"timeWon":1427787623,"difficulty":98127343,"startedWhen":1293818923},
 * 	"pool":
 * 		{"estimatedCapacity":301000,"totalMiners":90,"uptime":604800,"fee":0.02,"maximumDeadline":3888000,"minimumPayout":300,"maximumPayoutDelay":500,"blocksWon":12313},
 * 	"miner":
 * 		{
 * 			"id":3266889235992335646,"address":"XPAY-GG9X-ESV7-4LLPU","estimatedCapacity":7200,"currentBlockShare":0.028,"currentBlockReward":24,"historicBlockShare":0.023,"historicBlockReward":192,"totalEarned":4410,
 * 			"unconfirmedPayouts":1922,"deferredPayouts":192,"deferredUntilBlock":82163,"miningSoftware":"Blago v1.150223"
 * 		}
 * 	}
 */
int Handlers::webAPI::pool::process( struct MHD_Connection *connection, Request *req, Response *resp ) {
	std::unique_ptr<Block> current_block( Block::latest_block() );

	cJSON *root = cJSON_CreateObject();

	// "current"
	cJSON *current = cJSON_CreateObject();

	cJSON_AddNumberToObject( current, (char *)"block", current_block->blockID() );

	Nonce nonces;
	nonces.blockID( current_block->blockID() );
	cJSON_AddNumberToObject( current, (char *)"noncesSubmitted", nonces.count() );

	Share shares;
	shares.blockID( current_block->blockID() );
	cJSON_AddNumberToObject( current, (char *)"minersResponded", shares.count() );

	cJSON_AddNumberToObject( current, (char *)"bestDeadline", current_block->our_best_deadline() );

	cJSON_AddNumberToObject( current, (char *)"timeBlockStarted", current_block->first_seen_when() );

	cJSON_AddNumberToObject( current, (char *)"difficulty", BLOCK0_BASE_TARGET / current_block->base_target() );

	cJSON_AddItemToObject( root, (char *)"current", current );


	// "previous": last_block (that we won?)
	std::unique_ptr<Block> last_won_block( Block::latest_won_block() );
	if (last_won_block) {
		cJSON *previous = cJSON_CreateObject();

		cJSON_AddNumberToObject( previous, (char *)"block", last_won_block->blockID() );

		Nonce nonces;
		nonces.blockID( last_won_block->blockID() );
		cJSON_AddNumberToObject( previous, (char *)"noncesSubmitted", nonces.count() );

		Share shares;
		shares.blockID( last_won_block->blockID() );
		cJSON_AddNumberToObject( previous, (char *)"minersResponded", shares.count() );

		cJSON_AddNumberToObject( previous, (char *)"winningDeadline", last_won_block->deadline() );

		time_t time_won = last_won_block->first_seen_when() + last_won_block->deadline();
		cJSON_AddNumberToObject( previous, (char *)"timeWon", time_won );
		cJSON_AddNumberToObject( previous, (char *)"timeSinceLastWin", time(NULL) - time_won );
		cJSON_AddNumberToObject( previous, (char *)"timeBlockStarted", last_won_block->first_seen_when() );

		cJSON_AddNumberToObject( previous, (char *)"difficulty", BLOCK0_BASE_TARGET / last_won_block->base_target() );

		cJSON_AddItemToObject( root, (char *)"previous", previous );
	}


	// "pool"
	cJSON *pool = cJSON_CreateObject();

	// total estimated capacity? how about adding all estimated capacities from accounts that submitted on block-before-current
	Share previous_block_shares;
	previous_block_shares.blockID( current_block->blockID() - 1 );

	Account accounts;
	accounts.sum_capacities( true );

	std::unique_ptr<Account> accounts_total( accounts.present() );
	if (accounts_total) {
		cJSON_AddNumberToObject( pool, (char *)"estimatedCapacity", accounts_total->estimated_capacity() );
	}

	// accounts assigned to this pool
	cJSON_AddNumberToObject( pool, (char *)"totalMiners", current_block->num_potential_miners() );

	// uptime
	cJSON_AddNumberToObject( pool, (char *)"uptime", time(NULL) - BaseHandler::server_start_time );

	// fee
	cJSON_AddNumberToObject( pool, (char *)"fee", POOL_FEE_FRACTION );

	// maximumDeadline
	cJSON_AddNumberToObject( pool, (char *)"maximumDeadline", DEADLINE_MAX );

	// minimumPayout
	cJSON_AddNumberToObject( pool, (char *)"minimumPayout", MINIMUM_PAYOUT );

	// maximumPayoutDelay
	cJSON_AddNumberToObject( pool, (char *)"maximumPayoutDelay", MAX_PAYOUT_BLOCK_DELAY );

	// historicBlockCount
	cJSON_AddNumberToObject( pool, (char *)"historicBlockCount", HISTORIC_BLOCK_COUNT );

	Block blocks;
	blocks.is_our_block(true);
	cJSON_AddNumberToObject( pool, (char *)"blocksWon", blocks.count() );

	cJSON_AddItemToObject( root, (char *)"pool", pool );


	// "miner" - if accountID passed
	uint64_t accountID = safe_strtoull( req->get_query_or_post("accountId") );
	std::unique_ptr<Account> account( Account::load(accountID) );
	if (account) {
		cJSON *miner = cJSON_CreateObject();

		uint64_t reward_to_share = Block::previous_reward_post_fee();

		cJSON_AddStringToObject( miner, (char *)"id", std::to_string(accountID).c_str() );
		cJSON_AddStringToObject( miner, (char *)"address", account->account_RS_string().c_str() );

		cJSON_AddNumberToObject( miner, (char *)"estimatedCapacity", account->estimated_capacity() );

		std::unique_ptr<Share> current_block_share( Share::load( current_block->blockID(), accountID ) );
		if (current_block_share) {
			cJSON_AddNumberToObject( miner, (char *)"currentBlockShare", current_block_share->share_fraction() );
			cJSON_AddNumberToObject( miner, (char *)"currentBlockReward", current_block_share->share_fraction() * reward_to_share * CURRENT_BLOCK_REWARD_PERCENT / 100 );
		}

		Share historic_shares;
		historic_shares.accountID( accountID );
		historic_shares.after_blockID( current_block->blockID() - 1 - HISTORIC_BLOCK_COUNT );
		// include this block
		historic_shares.before_blockID( current_block->blockID() - 1 + 1 );
		historic_shares.historic_average(true);

		std::unique_ptr<Share> historic_block_share( historic_shares.present() );
		if (historic_block_share) {
			cJSON_AddNumberToObject( miner, (char *)"historicBlockShare", historic_block_share->share_fraction() );
			cJSON_AddNumberToObject( miner, (char *)"historicBlockReward", historic_block_share->share_fraction() * reward_to_share * (100 - CURRENT_BLOCK_REWARD_PERCENT) / 100 );
		}


		// balance deferred payments?
		Reward rewards;
		rewards.accountID( accountID );
		rewards.is_paid( true );
		rewards.is_confirmed( true );
		rewards.sum_amount(true);

		std::unique_ptr<Reward> reward_total( rewards.present() );
		if (reward_total)
			cJSON_AddNumberToObject( miner, (char *)"totalEarned", reward_total->amount() / BURST_TO_NQT);


		rewards.is_paid( true );
		rewards.is_confirmed( false );

		reward_total.reset( rewards.present() );
		if (reward_total)
			cJSON_AddNumberToObject( miner, (char *)"unconfirmedPayouts", reward_total->amount() / BURST_TO_NQT);

		rewards.is_paid( false );
		rewards.is_confirmed( false );
		rewards.below_amount( MINIMUM_PAYOUT * BURST_TO_NQT );

		reward_total.reset( rewards.present() );
		if (reward_total) {
			uint64_t deferredPayouts = reward_total->amount() / BURST_TO_NQT;
			cJSON_AddNumberToObject( miner, (char *)"deferredPayouts", deferredPayouts);

			if (deferredPayouts) {
				// find first unpaid reward by blockID so we can calculate when it'll be released
				Reward rewards;
				rewards.accountID( accountID );
				rewards.is_paid( false );
				rewards.order_by( Reward::COL_blockID, Reward::ORDER_BY_ASC );

				std::unique_ptr<Reward> first_unpaid( rewards.present() );
				if (first_unpaid)
					cJSON_AddNumberToObject( miner, (char *)"deferredUntilBlock", first_unpaid->blockID() + MAX_PAYOUT_BLOCK_DELAY);
			}
		}

		cJSON_AddItemToObject( root, (char *)"miner", miner );
	}


	std::unique_ptr<char> json( cJSON_PrintUnformatted(root) );

	resp->status_code = 200;
	resp->content = std::string(&*json);
	resp->add_header( "Access-Control-Allow-Origin", "*" );

	cJSON_Delete(root);

	return MHD_YES;
}
