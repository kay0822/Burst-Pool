#ifndef INCLUDE__CRYPTOCOINS_HPP_
#define INCLUDE__CRYPTOCOINS_HPP_

#include <stdint.h>
#include <string>
#include <vector>
#include <time.h>


class CryptoCoinTx {
	public:
		std::string			currency;
		std::string			tx_id;
		uint64_t			confirmations;
		std::string			sender;
		std::string			recipient;
		uint64_t			amount;
		uint64_t			int_to_float;
		uint64_t			fee;
		bool				fee_inclusive;
		uint64_t			crypto_timestamp;
		time_t				unix_timestamp;
		std::string			message;
		std::string			encoded_passphrase;
};


class CryptoCoin {
	protected:
		std::string server;
		virtual uint64_t unix_to_crypto_time(time_t unix_time) { return unix_time; };
		virtual time_t crypto_to_unix_time(uint64_t crypto_time) { return crypto_time; };

	public:
		std::string	currency;
		virtual std::vector<CryptoCoinTx *> *get_recent_transactionIDs( std::string account, time_t unix_time, bool include_unconfirmed = true ) =0;
		virtual CryptoCoinTx *get_transaction( CryptoCoinTx *tx ) =0;
		virtual bool send_transaction( CryptoCoinTx *tx ) =0;
		virtual int get_confirmations( CryptoCoinTx *tx );
};


class CryptoCoins {
	private:
		std::vector<CryptoCoin *> coin_servers;
		
	public:
		void add_coin_server( CryptoCoin *coin );

		std::vector<CryptoCoinTx *> *get_recent_transactionIDs( CryptoCoinTx *tx, time_t unix_time, bool include_unconfirmed = true );
		CryptoCoinTx *get_transaction( CryptoCoinTx *tx );
		bool send_transaction( CryptoCoinTx *tx );
		int get_confirmations( CryptoCoinTx *tx );
};

#endif
