#ifndef INCLUDE__BITCOIN_HPP_
#define INCLUDE__BITCOIN_HPP_

#include "cJSON.hpp"
#include "CryptoCoins.hpp"

#include <stdint.h>
#include <string>
#include <vector>
#include <map>


class BitCoinBlock {
	public:
		std::string hash;
		std::string previous_hash;
		std::vector<CryptoCoinTx *> txs;
		time_t block_time;
};


class BitCoin : public CryptoCoin {
	private:
		std::string request( std::string method, cJSON *params = NULL );
		static std::map<std::string,BitCoinBlock *> block_by_hash;
		static std::map<std::string,CryptoCoinTx *> tx_by_hash;
		std::string server_auth;
		
		cJSON *get_vout( cJSON *result, uint64_t vout_index );
		std::string get_vout_address( cJSON *vout );
		std::string get_transaction_json( std::string tx_hash );
		
	public:
		BitCoin(std::string srv);
		
		virtual std::vector<CryptoCoinTx *> *get_recent_transactionIDs( std::string account, time_t unix_time, bool include_unconfirmed = true );
		virtual CryptoCoinTx *get_transaction( CryptoCoinTx *tx );
		virtual bool send_transaction( CryptoCoinTx *tx );
		virtual int get_confirmations( CryptoCoinTx *info_tx );
		
		static const uint64_t int_to_float = 100000000UL;		
};


#endif
