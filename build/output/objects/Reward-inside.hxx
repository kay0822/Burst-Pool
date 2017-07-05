
// object "inside" .hxx template

	private:
		// search modifier variables
		
			bool _SM_before_blockID_p;
			uint64_t _SM_before_blockID;
		
			bool _SM_below_amount_p;
			uint64_t _SM_below_amount;
		
			bool _SM_paid_before_block_id_p;
			uint64_t _SM_paid_before_block_id;
		
			bool _SM_sum_amount_p;
			bool _SM_sum_amount;
		

		// our columns
		
			unsigned long long int _blockID;
			bool _blockID_exists;
			bool _blockID_defined;
			bool _blockID_changed;
		
			unsigned long long int _accountID;
			bool _accountID_exists;
			bool _accountID_defined;
			bool _accountID_changed;
		
			unsigned long long int _amount;
			bool _amount_exists;
			bool _amount_defined;
			bool _amount_changed;
		
			bool _is_paid;
			bool _is_paid_exists;
			bool _is_paid_defined;
			bool _is_paid_changed;
		
			unsigned long long int _tx_id;
			bool _tx_id_exists;
			bool _tx_id_defined;
			bool _tx_id_changed;
		
			bool _is_confirmed;
			bool _is_confirmed_exists;
			bool _is_confirmed_defined;
			bool _is_confirmed_changed;
		
			unsigned long long int _paid_at_block_id;
			bool _paid_at_block_id_exists;
			bool _paid_at_block_id_defined;
			bool _paid_at_block_id_changed;
		

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
		Reward( IDB::ResultSet *res );

	public:
		// our enum of columns
		typedef enum {
			
				COL_blockID,
			
				COL_accountID,
			
				COL_amount,
			
				COL_is_paid,
			
				COL_tx_id,
			
				COL_is_confirmed,
			
				COL_paid_at_block_id,
			
		} Reward_columns_t;
		static const std::string Reward_column_names[];
	
		// our table
		std::string _table();
	
		// generic constructor
		Reward();
		
		// constructor that uses columns from another object
		Reward(IO::Object *other_obj);

		// destructor
		virtual ~Reward();


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
		
			void accountID(unsigned long long int new_value);
			inline unsigned long long int accountID() {
				return _accountID;
			};
			void remove_accountID();
			void undef_accountID();
			bool defined_accountID();
			bool exists_accountID();
			bool changed_accountID();
		
			void amount(unsigned long long int new_value);
			inline unsigned long long int amount() {
				return _amount;
			};
			void remove_amount();
			void undef_amount();
			bool defined_amount();
			bool exists_amount();
			bool changed_amount();
		
			void is_paid(bool new_value);
			inline bool is_paid() {
				return _is_paid;
			};
			void remove_is_paid();
			void undef_is_paid();
			bool defined_is_paid();
			bool exists_is_paid();
			bool changed_is_paid();
		
			void tx_id(unsigned long long int new_value);
			inline unsigned long long int tx_id() {
				return _tx_id;
			};
			void remove_tx_id();
			void undef_tx_id();
			bool defined_tx_id();
			bool exists_tx_id();
			bool changed_tx_id();
		
			void is_confirmed(bool new_value);
			inline bool is_confirmed() {
				return _is_confirmed;
			};
			void remove_is_confirmed();
			void undef_is_confirmed();
			bool defined_is_confirmed();
			bool exists_is_confirmed();
			bool changed_is_confirmed();
		
			void paid_at_block_id(unsigned long long int new_value);
			inline unsigned long long int paid_at_block_id() {
				return _paid_at_block_id;
			};
			void remove_paid_at_block_id();
			void undef_paid_at_block_id();
			bool defined_paid_at_block_id();
			bool exists_paid_at_block_id();
			bool changed_paid_at_block_id();
		

		
		// navigator methods
		// these can't be named the same as the object they navigate to due to C++ conflict
		
			Block *block();
		
			Account *account();
		
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
		Reward *clone();

		// method to generate empty object but with keys filled in
		// (like a clone but only keys)
		Reward *skeleton();

		// method to load this object via explicit keys
		static Reward *load( unsigned long long int blockID, unsigned long long int accountID );

		// method to load this object via a WHERE clause
		static Reward *load(IDB::Where *where_clause);
		
		// method to load this object via key values from columns in another object
		static Reward *load(IO::Object *other_obj);

		// method to load ALL objects from database as a vector
		static std::vector<Reward *> load_all_vector();

		// reload this object from database based on keys
		void refresh();

		// "present" is like search(...) followed by result() - returns first matching record (if any)
		Reward *present();
		Reward *present(IDB::Options *options, std::vector<IO::Object *> *additional);
		// present_or_self either finds a match or just returns the calling object
		Reward *present_or_self();

		// return first/next matching record or null if none left
		Reward *result();

		// return a vector of all matching records
		std::vector<Reward *> results_vector();
		
		// search modifiers
		
			void before_blockID(uint64_t v);
		
			void below_amount(uint64_t v);
		
			void paid_before_block_id(uint64_t v);
		
			void sum_amount(bool v);
		
		
		// ordering modifiers
		void order_by( Reward_columns_t col, order_direction_t dir );
		
		
			IO::PreppedSearch *search_prep(IDB::Options *options, std::vector<IO::Object *> *additional);
		
				
		// other methods
		
			STATIC uint64_t  total_unpaid();
		
			STATIC uint64_t  total_paid_by_accountID( uint64_t accountID );
		
			STATIC uint64_t  total_unpaid_by_accountID( uint64_t accountID );
		
			STATIC uint64_t  total_deferred_by_accountID( uint64_t accountID, uint64_t threshold );
		
			STATIC uint64_t  total_unconfirmed_by_accountID( uint64_t accountID );
		
		
		static bool check_db_shape();
		
		// lock this record
		void lock_record();
