
// object "inside" .hxx template

	private:
		// search modifier variables
		
			bool _SM_after_blockID_p;
			uint64_t _SM_after_blockID;
		
			bool _SM_before_blockID_p;
			uint64_t _SM_before_blockID;
		
			bool _SM_has_reward_value_p;
			bool _SM_has_reward_value;
		

		// our columns
		
			unsigned long long int _blockID;
			bool _blockID_exists;
			bool _blockID_defined;
			bool _blockID_changed;
		
			time_t _first_seen_when;
			bool _first_seen_when_exists;
			bool _first_seen_when_defined;
			bool _first_seen_when_changed;
		
			unsigned long long int _best_nonce_account_id;
			bool _best_nonce_account_id_exists;
			bool _best_nonce_account_id_defined;
			bool _best_nonce_account_id_changed;
		
			unsigned long long int _generator_account_id;
			bool _generator_account_id_exists;
			bool _generator_account_id_defined;
			bool _generator_account_id_changed;
		
			unsigned long long int _block_reward;
			bool _block_reward_exists;
			bool _block_reward_defined;
			bool _block_reward_changed;
		
			bool _is_our_block;
			bool _is_our_block_exists;
			bool _is_our_block_defined;
			bool _is_our_block_changed;
		
			bool _has_been_shared;
			bool _has_been_shared_exists;
			bool _has_been_shared_defined;
			bool _has_been_shared_changed;
		
			unsigned long long int _base_target;
			bool _base_target_exists;
			bool _base_target_defined;
			bool _base_target_changed;
		
			time_t _forged_when;
			bool _forged_when_exists;
			bool _forged_when_defined;
			bool _forged_when_changed;
		
			unsigned long long int _scoop;
			bool _scoop_exists;
			bool _scoop_defined;
			bool _scoop_changed;
		
			unsigned long long int _nonce;
			bool _nonce_exists;
			bool _nonce_defined;
			bool _nonce_changed;
		
			std::string _gen_sig_str;
			bool _gen_sig_str_exists;
			bool _gen_sig_str_defined;
			bool _gen_sig_str_changed;
		
			unsigned long long int _deadline;
			bool _deadline_exists;
			bool _deadline_defined;
			bool _deadline_changed;
		
			unsigned long long int _our_best_deadline;
			bool _our_best_deadline_exists;
			bool _our_best_deadline_defined;
			bool _our_best_deadline_changed;
		
			unsigned long long int _num_potential_miners;
			bool _num_potential_miners_exists;
			bool _num_potential_miners_defined;
			bool _num_potential_miners_changed;
		
			std::string _json;
			bool _json_exists;
			bool _json_defined;
			bool _json_changed;
		

		// generic order_by support
		std::string _order_by;
		
		// handy?
		static const std::string _my_table;
	
	// methods
	
	private:
		// common method to initialize a new object
		void _init();
		// common method to initialize column values for an object
		void _init_columns();

		// common method to copy data from an SQL result set into our object
		void _copy_from_res(IDB::ResultSet *res);

		// method to generate generic search WHERE criteria based on columns with values
		IDB::Where *_search_prep_columns();
		
		// method to generate generic join ON criteria based on columns
		IDB::Where *_search_prep_join(std::map<std::string, std::string> *col_to_table);
		
		// method to do heavy lifting unique to this object for real search_prep() method
		IO::PreppedSearch *_search_prep(IDB::Options *options, std::vector<IO::Object *> *additional);

		// method to do heavy lifting unique to this object for real save() method
		void _save();
		
		// method to do heavy lifting unique to this object for real delete_obj() method
		void _delete_obj();
		
		
			// method to do heavy lifting of deleting child objects
			void _delete_children();
		

		// special constructor for internal use that doesn't clean column values
		Block( IDB::ResultSet *res );

	public:
		// our enum of columns
		typedef enum {
			
				COL_blockID,
			
				COL_first_seen_when,
			
				COL_best_nonce_account_id,
			
				COL_generator_account_id,
			
				COL_block_reward,
			
				COL_is_our_block,
			
				COL_has_been_shared,
			
				COL_base_target,
			
				COL_forged_when,
			
				COL_scoop,
			
				COL_nonce,
			
				COL_gen_sig_str,
			
				COL_deadline,
			
				COL_our_best_deadline,
			
				COL_num_potential_miners,
			
				COL_json,
			
		} Block_columns_t;
		static const std::string Block_column_names[];
	
		// our table
		std::string _table();
	
		// generic constructor
		Block();
		
		// constructor that uses columns from another object
		Block(IO::Object *other_obj);

		// destructor
		virtual ~Block();


		// column accessor methods
		
			void blockID(unsigned long long int new_value);
			inline unsigned long long int blockID() {
				return _blockID;
			};
			void remove_blockID();
			void undef_blockID();
			bool defined_blockID();
			bool exists_blockID();
			bool changed_blockID();
		
			void first_seen_when(time_t new_value);
			inline time_t first_seen_when() {
				return _first_seen_when;
			};
			void remove_first_seen_when();
			void undef_first_seen_when();
			bool defined_first_seen_when();
			bool exists_first_seen_when();
			bool changed_first_seen_when();
		
			void best_nonce_account_id(unsigned long long int new_value);
			inline unsigned long long int best_nonce_account_id() {
				return _best_nonce_account_id;
			};
			void remove_best_nonce_account_id();
			void undef_best_nonce_account_id();
			bool defined_best_nonce_account_id();
			bool exists_best_nonce_account_id();
			bool changed_best_nonce_account_id();
		
			void generator_account_id(unsigned long long int new_value);
			inline unsigned long long int generator_account_id() {
				return _generator_account_id;
			};
			void remove_generator_account_id();
			void undef_generator_account_id();
			bool defined_generator_account_id();
			bool exists_generator_account_id();
			bool changed_generator_account_id();
		
			void block_reward(unsigned long long int new_value);
			inline unsigned long long int block_reward() {
				return _block_reward;
			};
			void remove_block_reward();
			void undef_block_reward();
			bool defined_block_reward();
			bool exists_block_reward();
			bool changed_block_reward();
		
			void is_our_block(bool new_value);
			inline bool is_our_block() {
				return _is_our_block;
			};
			void remove_is_our_block();
			void undef_is_our_block();
			bool defined_is_our_block();
			bool exists_is_our_block();
			bool changed_is_our_block();
		
			void has_been_shared(bool new_value);
			inline bool has_been_shared() {
				return _has_been_shared;
			};
			void remove_has_been_shared();
			void undef_has_been_shared();
			bool defined_has_been_shared();
			bool exists_has_been_shared();
			bool changed_has_been_shared();
		
			void base_target(unsigned long long int new_value);
			inline unsigned long long int base_target() {
				return _base_target;
			};
			void remove_base_target();
			void undef_base_target();
			bool defined_base_target();
			bool exists_base_target();
			bool changed_base_target();
		
			void forged_when(time_t new_value);
			inline time_t forged_when() {
				return _forged_when;
			};
			void remove_forged_when();
			void undef_forged_when();
			bool defined_forged_when();
			bool exists_forged_when();
			bool changed_forged_when();
		
			void scoop(unsigned long long int new_value);
			inline unsigned long long int scoop() {
				return _scoop;
			};
			void remove_scoop();
			void undef_scoop();
			bool defined_scoop();
			bool exists_scoop();
			bool changed_scoop();
		
			void nonce(unsigned long long int new_value);
			inline unsigned long long int nonce() {
				return _nonce;
			};
			void remove_nonce();
			void undef_nonce();
			bool defined_nonce();
			bool exists_nonce();
			bool changed_nonce();
		
			void gen_sig_str(std::string new_value);
			inline std::string gen_sig_str() {
				return _gen_sig_str;
			};
			void remove_gen_sig_str();
			void undef_gen_sig_str();
			bool defined_gen_sig_str();
			bool exists_gen_sig_str();
			bool changed_gen_sig_str();
		
			void deadline(unsigned long long int new_value);
			inline unsigned long long int deadline() {
				return _deadline;
			};
			void remove_deadline();
			void undef_deadline();
			bool defined_deadline();
			bool exists_deadline();
			bool changed_deadline();
		
			void our_best_deadline(unsigned long long int new_value);
			inline unsigned long long int our_best_deadline() {
				return _our_best_deadline;
			};
			void remove_our_best_deadline();
			void undef_our_best_deadline();
			bool defined_our_best_deadline();
			bool exists_our_best_deadline();
			bool changed_our_best_deadline();
		
			void num_potential_miners(unsigned long long int new_value);
			inline unsigned long long int num_potential_miners() {
				return _num_potential_miners;
			};
			void remove_num_potential_miners();
			void undef_num_potential_miners();
			bool defined_num_potential_miners();
			bool exists_num_potential_miners();
			bool changed_num_potential_miners();
		
			void json(std::string new_value);
			inline std::string json() {
				return _json;
			};
			void remove_json();
			void undef_json();
			bool defined_json();
			bool exists_json();
			bool changed_json();
		

		
		// navigator methods
		// these can't be named the same as the object they navigate to due to C++ conflict
		
		// children
		
			Nonce *block_nonces();
		
			Share *block_shares();
		
			Reward *block_rewards();
		
		

		// generic column testing by name
		bool has_field(std::string field);
		bool exists_by_name(std::string field);
		bool defined_by_name(std::string field);
		bool is_key_by_name(std::string field);


		// get specific column typed value by name
		
			bool get_Boolean_by_name(std::string field);
		
			std::string get_String_by_name(std::string field);
		
			double get_Double_by_name(std::string field);
		
			int get_Int_by_name(std::string field);
		
			time_t get_Timestamp_by_name(std::string field);
		
			unsigned char * get_Blob_by_name(std::string field);
		
			unsigned int get_UInt_by_name(std::string field);
		
			unsigned long long int get_UInt64_by_name(std::string field);
		

		// method to clear all fields of object
		void clear();
			
		// method to generate a clone of object
		Block *clone();

		// method to generate empty object but with keys filled in
		// (like a clone but only keys)
		Block *skeleton();

		// method to load this object via explicit keys
		static Block *load( unsigned long long int blockID );

		// method to load this object via a WHERE clause
		static Block *load(IDB::Where *where_clause);
		
		// method to load this object via key values from columns in another object
		static Block *load(IO::Object *other_obj);

		// method to load ALL objects from database as a vector
		static std::vector<Block *> load_all_vector();

		// reload this object from database based on keys
		void refresh();

		// "present" is like search(...) followed by result() - returns first matching record (if any)
		Block *present();
		Block *present(IDB::Options *options, std::vector<IO::Object *> *additional);
		// present_or_self either finds a match or just returns the calling object
		Block *present_or_self();

		// return first/next matching record or null if none left
		Block *result();

		// return a vector of all matching records
		std::vector<Block *> results_vector();
		
		// search modifiers
		
			void after_blockID(uint64_t v);
		
			void before_blockID(uint64_t v);
		
			void has_reward_value(bool v);
		
		
		// ordering modifiers
		void order_by( Block_columns_t col, order_direction_t dir );
		
		
			IO::PreppedSearch *search_prep(IDB::Options *options, std::vector<IO::Object *> *additional);
		
				
		// other methods
		
			STATIC Block * latest_block();
		
			STATIC uint64_t  latest_blockID();
		
			STATIC Block * latest_won_block();
		
			STATIC Nonce * find_best_nonce( uint64_t blockID );
		
			STATIC void  recalculate_shares( uint64_t blockID );
		
			void  reward_miners();
		
			STATIC uint64_t  previous_reward_post_fee();
		
			STATIC void  unpack_gen_sig_str( const std::string gen_sig_str, uint8_t *gen_sig );
		
		
		static bool check_db_shape();
		
		// lock this record
		void lock_record();
