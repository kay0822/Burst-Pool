
// object "inside" .hxx template

	private:
		// search modifier variables
		
			bool _SM_before_blockID_p;
			uint64_t _SM_before_blockID;
		
			bool _SM_after_blockID_p;
			uint64_t _SM_after_blockID;
		
			bool _SM_historic_average_p;
			bool _SM_historic_average;
		
			bool _SM_mean_weighted_deadline_p;
			bool _SM_mean_weighted_deadline;
		

		// our columns
		
			unsigned long long int _blockID;
			bool _blockID_exists;
			bool _blockID_defined;
			bool _blockID_changed;
		
			unsigned long long int _accountID;
			bool _accountID_exists;
			bool _accountID_defined;
			bool _accountID_changed;
		
			double _share_fraction;
			bool _share_fraction_exists;
			bool _share_fraction_defined;
			bool _share_fraction_changed;
		
			unsigned long long int _deadline;
			bool _deadline_exists;
			bool _deadline_defined;
			bool _deadline_changed;
		
			std::string _deadline_string;
			bool _deadline_string_exists;
			bool _deadline_string_defined;
			bool _deadline_string_changed;
		
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
		Share( IDB::ResultSet *res );

	public:
		// our enum of columns
		typedef enum {
			
				COL_blockID,
			
				COL_accountID,
			
				COL_share_fraction,
			
				COL_deadline,
			
				COL_deadline_string,
			
				COL_miner,
			
		} Share_columns_t;
		static const std::string Share_column_names[];
	
		// our table
		std::string _table();
	
		// generic constructor
		Share();
		
		// constructor that uses columns from another object
		Share(IO::Object *other_obj);

		// destructor
		virtual ~Share();


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
		
			void share_fraction(double new_value);
			inline double share_fraction() {
				return _share_fraction;
			};
			void remove_share_fraction();
			void undef_share_fraction();
			bool defined_share_fraction();
			bool exists_share_fraction();
			bool changed_share_fraction();
		
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
		Share *clone();

		// method to generate empty object but with keys filled in
		// (like a clone but only keys)
		Share *skeleton();

		// method to load this object via explicit keys
		static Share *load( unsigned long long int blockID, unsigned long long int accountID );

		// method to load this object via a WHERE clause
		static Share *load(IDB::Where *where_clause);
		
		// method to load this object via key values from columns in another object
		static Share *load(IO::Object *other_obj);

		// method to load ALL objects from database as a vector
		static std::vector<Share *> load_all_vector();

		// reload this object from database based on keys
		void refresh();

		// "present" is like search(...) followed by result() - returns first matching record (if any)
		Share *present();
		Share *present(IDB::Options *options, std::vector<IO::Object *> *additional);
		// present_or_self either finds a match or just returns the calling object
		Share *present_or_self();

		// return first/next matching record or null if none left
		Share *result();

		// return a vector of all matching records
		std::vector<Share *> results_vector();
		
		// search modifiers
		
			void before_blockID(uint64_t v);
		
			void after_blockID(uint64_t v);
		
			void historic_average(bool v);
		
			void mean_weighted_deadline(bool v);
		
		
		// ordering modifiers
		void order_by( Share_columns_t col, order_direction_t dir );
		
		
			IO::PreppedSearch *search_prep(IDB::Options *options, std::vector<IO::Object *> *additional);
		
				
		// other methods
		
			STATIC Share * historic_shares( uint64_t to_blockID, uint64_t block_count );
		
		
		static bool check_db_shape();
		
		// lock this record
		void lock_record();
