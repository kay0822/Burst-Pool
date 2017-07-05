
// handler HXX of methods - always regenerated

#ifdef STATIC
#undef STATIC
#endif
#define STATIC static


	void update_account_info( uint64_t accountID );


	void add_account_award( cJSON *awards, char *award_name, Nonce *nonce, time_t block_start_time );


	cJSON *generate_awards( uint64_t blockID, time_t block_start_time );


	void websocket_alert();


	updates();


	void init();



#undef STATIC
#define STATIC
