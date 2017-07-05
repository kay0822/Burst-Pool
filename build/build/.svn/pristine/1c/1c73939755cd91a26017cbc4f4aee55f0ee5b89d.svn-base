#include "CryptoCoins.hpp"


void CryptoCoins::add_coin_server( CryptoCoin *coin ) {
	coin_servers.push_back( coin );
}


std::vector<CryptoCoinTx *> *CryptoCoins::get_recent_transactionIDs( CryptoCoinTx *tx, time_t unix_time, bool include_unconfirmed ) {
	for( auto coin : coin_servers )
		if ( coin->currency == tx->currency )
			return coin->get_recent_transactionIDs( tx->recipient, unix_time, include_unconfirmed );
	
	return NULL;
}


CryptoCoinTx *CryptoCoins::get_transaction( CryptoCoinTx *tx ) {
	for( auto coin : coin_servers )
		if ( coin->currency == tx->currency )
			return coin->get_transaction( tx );
			
	return NULL;
}


bool CryptoCoins::send_transaction( CryptoCoinTx *tx ) {
	for( auto coin : coin_servers )
		if ( coin->currency == tx->currency )
			return coin->send_transaction( tx );

	return false;
}


int CryptoCoins::get_confirmations( CryptoCoinTx *tx ) {
	for( auto coin : coin_servers )
		if ( coin->currency == tx->currency )
			return coin->get_confirmations( tx );

	return -1;
}


int CryptoCoin::get_confirmations( CryptoCoinTx *info_tx ) {
	std::unique_ptr<CryptoCoinTx> tx( get_transaction( info_tx ) );
	
	if (tx)
		return tx->confirmations;
		
	return -1;
}
