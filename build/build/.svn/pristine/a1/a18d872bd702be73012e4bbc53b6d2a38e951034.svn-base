#ifndef INCLUDE__BURSTCOIN_HPP_
#define INCLUDE__BURSTCOIN_HPP_

#include "cJSON.hpp"
#include "CryptoCoins.hpp"

#include <stdint.h>
#include <string>
#include <vector>



class BurstCoin : public CryptoCoin {
	private:
		virtual uint64_t unix_to_crypto_time(time_t unix_time);
		virtual time_t crypto_to_unix_time(uint64_t crypto_time);
	
	public:
		BurstCoin(std::string srv);
		
		virtual std::vector<CryptoCoinTx *> *get_recent_transactionIDs( std::string account, time_t unix_time, bool include_unconfirmed = true );
		virtual CryptoCoinTx *get_transaction( CryptoCoinTx *tx );
		virtual bool send_transaction( CryptoCoinTx *tx );
		
		static const uint64_t int_to_float = 100000000UL;
};


#endif
