
// object "inside" .hxx template

	private:
		// search modifier variables
		
			bool _SM_needs_updating_p;
			bool _SM_needs_updating;
		
			bool _SM_sum_capacities_p;
			bool _SM_sum_capacities;
		

		// our columns
		
			unsigned long long int _accountID;
			bool _accountID_exists;
			bool _accountID_defined;
			bool _accountID_changed;
		
			time_t _first_seen_when;
			bool _first_seen_when_exists;
			bool _first_seen_when_defined;
			bool _first_seen_when_changed;
		
			unsigned long long int _reward_recipient;
			bool _reward_recipient_exists;
			bool _reward_recipient_defined;
			bool _reward_recipient_changed;
		
			time_t _last_updated_when;
			bool _last_updated_when_exists;
			bool _last_updated_when_defined;
			bool _last_updated_when_changed;
		
			unsigned long long int _last_nonce;
			bool _last_nonce_exists;
			bool _last_nonce_defined;
			bool _last_nonce_changed;
		
			time_t _last_nonce_when;
			bool _last_nonce_when_exists;
			bool _last_nonce_when_defined;
			bool _last_nonce_when_changed;
		
			std::string _account_name;
			bool _account_name_exists;
			bool _account_name_defined;
			bool _account_name_changed;
		
			unsigned long long int _estimated_capacity;
			bool _estimated_capacity_exists;
			bool _estimated_capacity_defined;
			bool _estimated_capacity_changed;
		
			std::string _account_RS_string;
			bool _account_RS_string_exists;
			bool _account_RS_string_defined;
			bool _account_RS_string_changed;
		
			bool _has_used_this_pool;
			bool _has_used_this_pool_exists;
			bool _has_used_this_pool_defined;
			bool _has_used_this_pool_changed;
		

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
		
		

		// special constructor for internal use that doesn't clean column values
		Account( IDB::ResultSet *res );

	public:
		// our enum of columns
		typedef enum {
			
				COL_accountID,
			
				COL_first_seen_when,
			
				COL_reward_recipient,
			
				COL_last_updated_when,
			
				COL_last_nonce,
			
				COL_last_nonce_when,
			
				COL_account_name,
			
				COL_estimated_capacity,
			
				COL_account_RS_string,
			
				COL_has_used_this_pool,
			
		} Account_columns_t;
		static const std::string Account_column_names[];
	
		// our table
		std::string _table();
	
		// generic constructor
		Account();
		
		// constructor that uses columns from another object
		Account(IO::Object *other_obj);

		// destructor
		virtual ~Account();


		// column accessor methods
		
			void accountID(unsigned long long int new_value);
			inline unsigned long long int accountID() {
				return _accountID;
			};
			void remove_accountID();
			void undef_accountID();
			bool defined_accountID();
			bool exists_accountID();
			bool changed_accountID();
		
			void first_seen_when(time_t new_value);
			inline time_t first_seen_when() {
				return _first_seen_when;
			};
			void remove_first_seen_when();
			void undef_first_seen_when();
			bool defined_first_seen_when();
			bool exists_first_seen_when();
			bool changed_first_seen_when();
		
			void reward_recipient(unsigned long long int new_value);
			inline unsigned long long int reward_recipient() {
				return _reward_recipient;
			};
			void remove_reward_recipient();
			void undef_reward_recipient();
			bool defined_reward_recipient();
			bool exists_reward_recipient();
			bool changed_reward_recipient();
		
			void last_updated_when(time_t new_value);
			inline time_t last_updated_when() {
				return _last_updated_when;
			};
			void remove_last_updated_when();
			void undef_last_updated_when();
			bool defined_last_updated_when();
			bool exists_last_updated_when();
			bool changed_last_updated_when();
		
			void last_nonce(unsigned long long int new_value);
			inline unsigned long long int last_nonce() {
				return _last_nonce;
			};
			void remove_last_nonce();
			void undef_last_nonce();
			bool defined_last_nonce();
			bool exists_last_nonce();
			bool changed_last_nonce();
		
			void last_nonce_when(time_t new_value);
			inline time_t last_nonce_when() {
				return _last_nonce_when;
			};
			void remove_last_nonce_when();
			void undef_last_nonce_when();
			bool defined_last_nonce_when();
			bool exists_last_nonce_when();
			bool changed_last_nonce_when();
		
			void account_name(std::string new_value);
			inline std::string account_name() {
				return _account_name;
			};
			void remove_account_name();
			void undef_account_name();
			bool defined_account_name();
			bool exists_account_name();
			bool changed_account_name();
		
			void estimated_capacity(unsigned long long int new_value);
			inline unsigned long long int estimated_capacity() {
				return _estimated_capacity;
			};
			void remove_estimated_capacity();
			void undef_estimated_capacity();
			bool defined_estimated_capacity();
			bool exists_estimated_capacity();
			bool changed_estimated_capacity();
		
			void account_RS_string(std::string new_value);
			inline std::string account_RS_string() {
				return _account_RS_string;
			};
			void remove_account_RS_string();
			void undef_account_RS_string();
			bool defined_account_RS_string();
			bool exists_account_RS_string();
			bool changed_account_RS_string();
		
			void has_used_this_pool(bool new_value);
			inline bool has_used_this_pool() {
				return _has_used_this_pool;
			};
			void remove_has_used_this_pool();
			void undef_has_used_this_pool();
			bool defined_has_used_this_pool();
			bool exists_has_used_this_pool();
			bool changed_has_used_this_pool();
		

		
		// navigator methods
		// these can't be named the same as the object they navigate to due to C++ conflict
		
		// children
		
		

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
		Account *clone();

		// method to generate empty object but with keys filled in
		// (like a clone but only keys)
		Account *skeleton();

		// method to load this object via explicit keys
		static Account *load( unsigned long long int accountID );

		// method to load this object via a WHERE clause
		static Account *load(IDB::Where *where_clause);
		
		// method to load this object via key values from columns in another object
		static Account *load(IO::Object *other_obj);

		// method to load ALL objects from database as a vector
		static std::vector<Account *> load_all_vector();

		// reload this object from database based on keys
		void refresh();

		// "present" is like search(...) followed by result() - returns first matching record (if any)
		Account *present();
		Account *present(IDB::Options *options, std::vector<IO::Object *> *additional);
		// present_or_self either finds a match or just returns the calling object
		Account *present_or_self();

		// return first/next matching record or null if none left
		Account *result();

		// return a vector of all matching records
		std::vector<Account *> results_vector();
		
		// search modifiers
		
			void needs_updating(bool v);
		
			void sum_capacities(bool v);
		
		
		// ordering modifiers
		void order_by( Account_columns_t col, order_direction_t dir );
		
		
			IO::PreppedSearch *search_prep(IDB::Options *options, std::vector<IO::Object *> *additional);
		
				
		// other methods
		
			void  save();
		
			STATIC Account * load_or_create( uint64_t some_accountID );
		
			uint64_t  estimate_capacity();
		
			void  update_check();
		
			STATIC std::string  accountID_to_RS_string( uint64_t accountID );
		
		
		static bool check_db_shape();
		
		// lock this record
		void lock_record();
