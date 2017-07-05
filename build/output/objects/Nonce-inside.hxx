
// object "inside" .hxx template

	private:
		// search modifier variables
		

		// our columns
		
			unsigned long long int _accountID;
			bool _accountID_exists;
			bool _accountID_defined;
			bool _accountID_changed;
		
			unsigned long long int _blockID;
			bool _blockID_exists;
			bool _blockID_defined;
			bool _blockID_changed;
		
			unsigned long long int _nonce;
			bool _nonce_exists;
			bool _nonce_defined;
			bool _nonce_changed;
		
			time_t _submitted_when;
			bool _submitted_when_exists;
			bool _submitted_when_defined;
			bool _submitted_when_changed;
		
			unsigned long long int _deadline;
			bool _deadline_exists;
			bool _deadline_defined;
			bool _deadline_changed;
		
			std::string _deadline_string;
			bool _deadline_string_exists;
			bool _deadline_string_defined;
			bool _deadline_string_changed;
		
			time_t _forge_when;
			bool _forge_when_exists;
			bool _forge_when_defined;
			bool _forge_when_changed;
		
			bool _is_blocks_best_deadline;
			bool _is_blocks_best_deadline_exists;
			bool _is_blocks_best_deadline_defined;
			bool _is_blocks_best_deadline_changed;
		
			bool _is_accounts_best_deadline;
			bool _is_accounts_best_deadline_exists;
			bool _is_accounts_best_deadline_defined;
			bool _is_accounts_best_deadline_changed;
		
			std::string _miner;
			bool _miner_exists;
			bool _miner_defined;
			bool _miner_changed;
		

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
		Nonce( IDB::ResultSet *res );

	public:
		// our enum of columns
		typedef enum {
			
				COL_accountID,
			
				COL_blockID,
			
				COL_nonce,
			
				COL_submitted_when,
			
				COL_deadline,
			
				COL_deadline_string,
			
				COL_forge_when,
			
				COL_is_blocks_best_deadline,
			
				COL_is_accounts_best_deadline,
			
				COL_miner,
			
		} Nonce_columns_t;
		static const std::string Nonce_column_names[];
	
		// our table
		std::string _table();
	
		// generic constructor
		Nonce();
		
		// constructor that uses columns from another object
		Nonce(IO::Object *other_obj);

		// destructor
		virtual ~Nonce();


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
		
			void blockID(unsigned long long int new_value);
			inline unsigned long long int blockID() {
				return _blockID;
			};
			void remove_blockID();
			void undef_blockID();
			bool defined_blockID();
			bool exists_blockID();
			bool changed_blockID();
		
			void nonce(unsigned long long int new_value);
			inline unsigned long long int nonce() {
				return _nonce;
			};
			void remove_nonce();
			void undef_nonce();
			bool defined_nonce();
			bool exists_nonce();
			bool changed_nonce();
		
			void submitted_when(time_t new_value);
			inline time_t submitted_when() {
				return _submitted_when;
			};
			void remove_submitted_when();
			void undef_submitted_when();
			bool defined_submitted_when();
			bool exists_submitted_when();
			bool changed_submitted_when();
		
			void deadline(unsigned long long int new_value);
			inline unsigned long long int deadline() {
				return _deadline;
			};
			void remove_deadline();
			void undef_deadline();
			bool defined_deadline();
			bool exists_deadline();
			bool changed_deadline();
		
			void deadline_string(std::string new_value);
			inline std::string deadline_string() {
				return _deadline_string;
			};
			void remove_deadline_string();
			void undef_deadline_string();
			bool defined_deadline_string();
			bool exists_deadline_string();
			bool changed_deadline_string();
		
			void forge_when(time_t new_value);
			inline time_t forge_when() {
				return _forge_when;
			};
			void remove_forge_when();
			void undef_forge_when();
			bool defined_forge_when();
			bool exists_forge_when();
			bool changed_forge_when();
		
			void is_blocks_best_deadline(bool new_value);
			inline bool is_blocks_best_deadline() {
				return _is_blocks_best_deadline;
			};
			void remove_is_blocks_best_deadline();
			void undef_is_blocks_best_deadline();
			bool defined_is_blocks_best_deadline();
			bool exists_is_blocks_best_deadline();
			bool changed_is_blocks_best_deadline();
		
			void is_accounts_best_deadline(bool new_value);
			inline bool is_accounts_best_deadline() {
				return _is_accounts_best_deadline;
			};
			void remove_is_accounts_best_deadline();
			void undef_is_accounts_best_deadline();
			bool defined_is_accounts_best_deadline();
			bool exists_is_accounts_best_deadline();
			bool changed_is_accounts_best_deadline();
		
			void miner(std::string new_value);
			inline std::string miner() {
				return _miner;
			};
			void remove_miner();
			void undef_miner();
			bool defined_miner();
			bool exists_miner();
			bool changed_miner();
		

		
		// navigator methods
		// these can't be named the same as the object they navigate to due to C++ conflict
		
			Account *account();
		
			Block *block();
		
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
		Nonce *clone();

		// method to generate empty object but with keys filled in
		// (like a clone but only keys)
		Nonce *skeleton();

		// method to load this object via explicit keys
		static Nonce *load( unsigned long long int accountID, unsigned long long int blockID, unsigned long long int nonce );

		// method to load this object via a WHERE clause
		static Nonce *load(IDB::Where *where_clause);
		
		// method to load this object via key values from columns in another object
		static Nonce *load(IO::Object *other_obj);

		// method to load ALL objects from database as a vector
		static std::vector<Nonce *> load_all_vector();

		// reload this object from database based on keys
		void refresh();

		// "present" is like search(...) followed by result() - returns first matching record (if any)
		Nonce *present();
		Nonce *present(IDB::Options *options, std::vector<IO::Object *> *additional);
		// present_or_self either finds a match or just returns the calling object
		Nonce *present_or_self();

		// return first/next matching record or null if none left
		Nonce *result();

		// return a vector of all matching records
		std::vector<Nonce *> results_vector();
		
		// search modifiers
		
		
		// ordering modifiers
		void order_by( Nonce_columns_t col, order_direction_t dir );
		
		
				
		// other methods
		
			void  save_and_rank();
		
			STATIC Nonce * get_best_block_nonce( uint64_t blockID );
		
			STATIC Nonce * get_first_block_nonce( uint64_t blockID );
		
			STATIC Nonce * get_worst_block_nonce( uint64_t blockID );
		
			STATIC Nonce * get_last_block_nonce( uint64_t blockID );
		
			STATIC Nonce * get_best_account_nonce( uint64_t blockID, uint64_t accountID );
		
			STATIC uint8_t * plot_nonce( uint64_t account_id, uint64_t nonce );
		
			STATIC uint64_t  calculate_deadline( uint64_t account_id, uint64_t nonce, uint64_t blockID, uint32_t scoop, uint64_t base_target, std::string gen_sig_str );
		
			STATIC std::string  deadline_to_string( uint64_t deadline );
		
		
		static bool check_db_shape();
		
		// lock this record
		void lock_record();
