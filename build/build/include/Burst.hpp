#ifndef INCLUDE__BURST_HPP_
#define INCLUDE__BURST_HPP_

#include <stdint.h>
#include <string>
#include <vector>


#ifndef BURST_TO_NQT
#define BURST_TO_NQT 100000000UL
#endif


class Burst {
	private:
		std::string server;
		
	public:
		Burst(std::string srv): server(srv) {};
		
		std::string get_transaction( uint64_t tx_id );
		std::vector<uint64_t> get_recent_transactions( std::string account, time_t unix_time, bool include_unconfirmed = true );
		int get_confirmations( uint64_t tx_id );
		uint64_t send_money( const char *encoded_passphrase, std::string account, uint64_t amountNQT, bool subtract_fee, std::string message = "");
		time_t unix_to_burst_time(time_t unix_time);
		time_t burst_to_unix_time(time_t burst_time);
};

#endif
