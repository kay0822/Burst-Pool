
// object .cxx include file template

#include "Share.hpp"

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif

#define FULLTEXT_FIELD(field)

#define SEARCHMOD(name, type)
#define SEARCHMOD_IS_SET(name) _SM_ ## name ## _p
#define SEARCHMOD_VALUE(name) _SM_ ## name
#define SEARCHPREP IO::PreppedSearch *Share::search_prep(IDB::Options *options, std::vector<IO::Object *> *additional)
#define SEARCHPREP_SUPER IO::PreppedSearch *ps = this->_search_prep(options, additional);
#define SEARCHPREP_ADD(new_clause) ps->where = ps->where == IDB_NO_WHERE ? new_clause : new IDB::sqlAnd( ps->where, new_clause )
#define SEARCHPREP_END return ps;
#define SEARCHPREP_FULLTEXT(field, value)

#define CHILD_OBJECT(name, navigator)
#define CHILD_OBJECTS(name, navigator)
#define DELETE_CHILDREN _delete_children()

#define NO_NAVIGATOR(field)

#ifdef STATIC
#undef STATIC
#endif
#define STATIC


// SAME ORDER AS .hxx FILE PLEASE!!

const std::string Share::_my_table = "Shares";


// PRIVATE METHODS


// common method to initialize a new object
void Share::_init() {
	// init results to null
	results = NULL;

	// initialize search modifiers
	
		_SM_before_blockID_p = false;
	
		_SM_after_blockID_p = false;
	
		_SM_historic_average_p = false;
	
		_SM_mean_weighted_deadline_p = false;
	
}


void Share::_init_columns() {
	// initialize columns
	
		_blockID_exists = false;
		_blockID_defined = false;
		_blockID_changed = false;
		_blockID = (unsigned long long int)0;
	
		_accountID_exists = false;
		_accountID_defined = false;
		_accountID_changed = false;
		_accountID = (unsigned long long int)0;
	
		_share_fraction_exists = false;
		_share_fraction_defined = false;
		_share_fraction_changed = false;
		_share_fraction = (double)0.0;
	
		_deadline_exists = false;
		_deadline_defined = false;
		_deadline_changed = false;
		_deadline = (unsigned long long int)0;
	
		_deadline_string_exists = false;
		_deadline_string_defined = false;
		_deadline_string_changed = false;
		_deadline_string = "";
	
		_miner_exists = false;
		_miner_defined = false;
		_miner_changed = false;
		_miner = "";
	
}


// common method to copy data from an SQL result set into our object
void Share::_copy_from_res(IDB::ResultSet *res) {
	
		try {
			
			if ( res->isNull( 1 ) ) {
				this->undef_blockID();
			} else {
				this->blockID( res->getUInt64( 1 ) );
			}
			_blockID_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Share column index 0" << std::endl;
			throw(e);
		}
	
		try {
			
			if ( res->isNull( 2 ) ) {
				this->undef_accountID();
			} else {
				this->accountID( res->getUInt64( 2 ) );
			}
			_accountID_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Share column index 1" << std::endl;
			throw(e);
		}
	
		try {
			
			if ( res->isNull( 3 ) ) {
				this->undef_share_fraction();
			} else {
				this->share_fraction( res->getDouble( 3 ) );
			}
			_share_fraction_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Share column index 2" << std::endl;
			throw(e);
		}
	
		try {
			
			if ( res->isNull( 4 ) ) {
				this->undef_deadline();
			} else {
				this->deadline( res->getUInt64( 4 ) );
			}
			_deadline_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Share column index 3" << std::endl;
			throw(e);
		}
	
		try {
			
			if ( res->isNull( 5 ) ) {
				this->undef_deadline_string();
			} else {
				this->deadline_string( res->getString( 5 ) );
			}
			_deadline_string_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Share column index 4" << std::endl;
			throw(e);
		}
	
		try {
			
			if ( res->isNull( 6 ) ) {
				this->undef_miner();
			} else {
				this->miner( res->getString( 6 ) );
			}
			_miner_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Share column index 5" << std::endl;
			throw(e);
		}
	
}


// method to generate generic search WHERE criteria based on columns with values
IDB::Where *Share::_search_prep_columns() {
	IDB::Where					*where_clause = IDB_NO_WHERE;
	IDB::Where					*new_clause;

	
		if (_blockID_exists) {
			if (_blockID_defined) {
				
					new_clause = new IDB::sqlEqUInt64( "Shares.blockID", _blockID );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Shares.blockID" );
			}

			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		if (_accountID_exists) {
			if (_accountID_defined) {
				
					new_clause = new IDB::sqlEqUInt64( "Shares.accountID", _accountID );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Shares.accountID" );
			}

			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		if (_share_fraction_exists) {
			if (_share_fraction_defined) {
				
					new_clause = new IDB::sqlEqDouble( "Shares.share_fraction", _share_fraction );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Shares.share_fraction" );
			}

			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		if (_deadline_exists) {
			if (_deadline_defined) {
				
					new_clause = new IDB::sqlEqUInt64( "Shares.deadline", _deadline );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Shares.deadline" );
			}

			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		if (_deadline_string_exists) {
			if (_deadline_string_defined) {
				
					new_clause = new IDB::sqlEqString( "Shares.deadline_string", _deadline_string );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Shares.deadline_string" );
			}

			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		if (_miner_exists) {
			if (_miner_defined) {
				
					new_clause = new IDB::sqlEqString( "Shares.miner", _miner );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Shares.miner" );
			}

			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	

	return where_clause;
}


// method to generate generic join ON criteria based on columns
IDB::Where *Share::_search_prep_join(std::map<std::string, std::string> *col_to_table) {
	IDB::Where									*on_clause = IDB_NO_WHERE;
	std::map<std::string, std::string>::iterator	it;

	
		

		it = col_to_table->find("blockID");
		if (it != col_to_table->end()) {
			std::string col_name = it->second;
			col_name += ".blockID";
			IDB::Where *new_clause = new IDB::sqlEqCol( col_name, "Shares.blockID" );

			if (on_clause == IDB_NO_WHERE) {
				on_clause = new_clause;
			} else {
				on_clause = new IDB::sqlAnd( on_clause, new_clause );
			}
		}
	
		

		it = col_to_table->find("accountID");
		if (it != col_to_table->end()) {
			std::string col_name = it->second;
			col_name += ".accountID";
			IDB::Where *new_clause = new IDB::sqlEqCol( col_name, "Shares.accountID" );

			if (on_clause == IDB_NO_WHERE) {
				on_clause = new_clause;
			} else {
				on_clause = new IDB::sqlAnd( on_clause, new_clause );
			}
		}
	
		
		
		
		

	return on_clause;
}


// method to do heavy lifting unique to this object for real search_prep() method
IO::PreppedSearch *Share::_search_prep(IDB::Options *options, std::vector<IO::Object *> *additional) {
	IO::PreppedSearch							*ps = new IO::PreppedSearch();
	IDB::Tables									*tables = new IDB::Tables("Shares");
	IDB::Where									*where_clause = IDB_NO_WHERE;
	IDB::Where									*new_clause;
	std::map<std::string, std::string>			col_to_table;

	where_clause = this->_search_prep_columns();

	
		col_to_table["blockID"] = "Shares";
	
		col_to_table["accountID"] = "Shares";
	
		col_to_table["share_fraction"] = "Shares";
	
		col_to_table["deadline"] = "Shares";
	
		col_to_table["deadline_string"] = "Shares";
	
		col_to_table["miner"] = "Shares";
	
	
	if (additional) {
		std::vector<IO::Object *>::iterator	it;
		IDB::Where							*on_clause = IDB_NO_WHERE;
	
		for(it = additional->begin(); it != additional->end(); it++) {
			IO::PreppedSearch *additional_ps = (*it)->search_prep(IDB_NO_OPTIONS, (std::vector<IO::Object *> *) NULL);

			/* join additional using columns from map */
			on_clause = (*it)->_search_prep_join(&col_to_table);
			tables->join("join", (*it)->_table(), on_clause);
			
			/* add additional columns to where */
			new_clause = additional_ps->where;

			if (new_clause != IDB_NO_WHERE) {
				if (where_clause != IDB_NO_WHERE) {
					where_clause = new IDB::sqlAnd( where_clause, new_clause );
				} else {
					where_clause = new_clause;
				}
			}

			// don't delete where clause - we're using it
			additional_ps->where = IDB_NO_WHERE;
			delete additional_ps;
		}
	}

	ps->cols = new std::vector<std::string>();
	/* use distinct results in case additional objects cause multiple rows to be returned for object requested */
	ps->cols->push_back("distinct Shares.*");

	ps->tables = tables;
	ps->where = where_clause;

	ps->options = new IDB::Options();
	

	// object's limit & offset applied here but can be overridden by other searchmods
	if ( limit() )
		ps->options->limit = limit();
	if ( offset() )
		ps->options->offset = offset();

	// generic order_by support (can be overridden below)
	if ( !_order_by.empty() )
		ps->options->order_by = _order_by;

	if (options && options != IDB_NO_OPTIONS) {
		if (options->limit) {
			ps->options->limit = options->limit;
		}
		if (options->offset) {
			ps->options->offset = options->offset;
		}
		if (options->having) {
			ps->options->having = options->having;
		}
		if (!options->group_by.empty()) {
			ps->options->group_by = options->group_by;
		}
		if (!options->order_by.empty()) {
			ps->options->order_by = options->order_by;
		}
	}

	return ps;
}


// method to do heavy lifting unique to this object for real save() method
void Share::_save() {
	std::vector<IDB::Where *>	updates;
	unsigned int				n_updates = 0;

	
		/* keys dealt with later on */
		
		/* keys dealt with later on */
		
		/* keys dealt with later on */
		

		/* add share_fraction to record if exists */
		#ifdef MINIMAL_SAVE
			if (_share_fraction_changed) {
		#endif
				if (_share_fraction_exists) {
					if (_share_fraction_defined) {
						
							updates.push_back( new IDB::sqlEqDouble( "share_fraction", _share_fraction ) );
								
					} else {
						updates.push_back( new IDB::sqlEqNull( "share_fraction" ) );
					}
				}
		#ifdef MINIMAL_SAVE
			}
		#endif				
	
		/* keys dealt with later on */
		

		/* add deadline to record if exists */
		#ifdef MINIMAL_SAVE
			if (_deadline_changed) {
		#endif
				if (_deadline_exists) {
					if (_deadline_defined) {
						
							updates.push_back( new IDB::sqlEqUInt64( "deadline", _deadline ) );
								
					} else {
						updates.push_back( new IDB::sqlEqNull( "deadline" ) );
					}
				}
		#ifdef MINIMAL_SAVE
			}
		#endif				
	
		/* keys dealt with later on */
		

		/* add deadline_string to record if exists */
		#ifdef MINIMAL_SAVE
			if (_deadline_string_changed) {
		#endif
				if (_deadline_string_exists) {
					if (_deadline_string_defined) {
						
							updates.push_back( new IDB::sqlEqString( "deadline_string", _deadline_string ) );
								
					} else {
						updates.push_back( new IDB::sqlEqNull( "deadline_string" ) );
					}
				}
		#ifdef MINIMAL_SAVE
			}
		#endif				
	
		/* keys dealt with later on */
		

		/* add miner to record if exists */
		#ifdef MINIMAL_SAVE
			if (_miner_changed) {
		#endif
				if (_miner_exists) {
					if (_miner_defined) {
						
							updates.push_back( new IDB::sqlEqString( "miner", _miner ) );
								
					} else {
						updates.push_back( new IDB::sqlEqNull( "miner" ) );
					}
				}
		#ifdef MINIMAL_SAVE
			}
		#endif				
	

	/* keys: blockID accountID */
	
		

		if (_blockID_exists) {
			if (_blockID_defined) {
				/* add blockID to updates */
				updates.push_back( new IDB::sqlEqUInt64( "blockID", _blockID ) );
			}
		}
	
		

		if (_accountID_exists) {
			if (_accountID_defined) {
				/* add accountID to updates */
				updates.push_back( new IDB::sqlEqUInt64( "accountID", _accountID ) );
			}
		}
	
		
		
		
		

	/* do save */
	idbe()->writerow("Shares", updates);

	/* clean updates */
	for(int i = 0; i < updates.size(); i++) {
		IDB::Where	*where = updates[i];
		delete where;
	}

	/* reset changed-ness */
	
		_blockID_changed = false;
	
		_accountID_changed = false;
	
		_share_fraction_changed = false;
	
		_deadline_changed = false;
	
		_deadline_string_changed = false;
	
		_miner_changed = false;
		

	/* autoinc support */
	
};


// special private constructor for internal use that doesn't clean column values
Share::Share( IDB::ResultSet *res ): IO::Object() {
	this->_init();
	this->_copy_from_res( res );
};


// PUBLIC METHODS
const std::string Share::Share_column_names[] = {
	
		"blockID",
	
		"accountID",
	
		"share_fraction",
	
		"deadline",
	
		"deadline_string",
	
		"miner",
	
};

// our table
std::string Share::_table() {
	return "Shares";
}


// generic constructor
Share::Share() {
	this->_init_columns();
	this->_init();
};


// constructor that uses columns from another object (must be key field in other object)
Share::Share(IO::Object *other_obj): IO::Object() {
	this->_init();

	
		if ( other_obj->is_key_by_name("blockID") )
			if ( other_obj->exists_by_name("blockID") )
				if ( other_obj->defined_by_name("blockID") )
					this->blockID( other_obj->get_UInt64_by_name("blockID") );
				else
					this->remove_blockID();
			else
				this->remove_blockID();
		else
			this->remove_blockID();
	
		if ( other_obj->is_key_by_name("accountID") )
			if ( other_obj->exists_by_name("accountID") )
				if ( other_obj->defined_by_name("accountID") )
					this->accountID( other_obj->get_UInt64_by_name("accountID") );
				else
					this->remove_accountID();
			else
				this->remove_accountID();
		else
			this->remove_accountID();
	
		if ( other_obj->is_key_by_name("share_fraction") )
			if ( other_obj->exists_by_name("share_fraction") )
				if ( other_obj->defined_by_name("share_fraction") )
					this->share_fraction( other_obj->get_Double_by_name("share_fraction") );
				else
					this->remove_share_fraction();
			else
				this->remove_share_fraction();
		else
			this->remove_share_fraction();
	
		if ( other_obj->is_key_by_name("deadline") )
			if ( other_obj->exists_by_name("deadline") )
				if ( other_obj->defined_by_name("deadline") )
					this->deadline( other_obj->get_UInt64_by_name("deadline") );
				else
					this->remove_deadline();
			else
				this->remove_deadline();
		else
			this->remove_deadline();
	
		if ( other_obj->is_key_by_name("deadline_string") )
			if ( other_obj->exists_by_name("deadline_string") )
				if ( other_obj->defined_by_name("deadline_string") )
					this->deadline_string( other_obj->get_String_by_name("deadline_string") );
				else
					this->remove_deadline_string();
			else
				this->remove_deadline_string();
		else
			this->remove_deadline_string();
	
		if ( other_obj->is_key_by_name("miner") )
			if ( other_obj->exists_by_name("miner") )
				if ( other_obj->defined_by_name("miner") )
					this->miner( other_obj->get_String_by_name("miner") );
				else
					this->remove_miner();
			else
				this->remove_miner();
		else
			this->remove_miner();
	
};


// destructor
Share::~Share() {
	if (results)
		delete results;
}


// column accessor methods

	void Share::blockID(unsigned long long int new_value) {
		_blockID_exists = true;
		_blockID_defined = true;
		_blockID_changed = true;
		_blockID = new_value;
	}
	
	// inlined: moved to .hxx file
	// unsigned long long int blockID()
	 
	void Share::remove_blockID() {
		_blockID_exists = false;
		_blockID_defined = false;
		_blockID_changed = true;
		_blockID = (unsigned long long int)0;
	}
	
	void Share::undef_blockID() {
		_blockID_exists = true;
		_blockID_defined = false;
		_blockID_changed = true;
		_blockID = (unsigned long long int)0;
	}
	
	bool Share::defined_blockID() {
		return _blockID_defined;
	}
	
	bool Share::exists_blockID() {
		return _blockID_exists;
	}
	
	bool Share::changed_blockID() {
		return _blockID_changed;
	}

	void Share::accountID(unsigned long long int new_value) {
		_accountID_exists = true;
		_accountID_defined = true;
		_accountID_changed = true;
		_accountID = new_value;
	}
	
	// inlined: moved to .hxx file
	// unsigned long long int accountID()
	 
	void Share::remove_accountID() {
		_accountID_exists = false;
		_accountID_defined = false;
		_accountID_changed = true;
		_accountID = (unsigned long long int)0;
	}
	
	void Share::undef_accountID() {
		_accountID_exists = true;
		_accountID_defined = false;
		_accountID_changed = true;
		_accountID = (unsigned long long int)0;
	}
	
	bool Share::defined_accountID() {
		return _accountID_defined;
	}
	
	bool Share::exists_accountID() {
		return _accountID_exists;
	}
	
	bool Share::changed_accountID() {
		return _accountID_changed;
	}

	void Share::share_fraction(double new_value) {
		_share_fraction_exists = true;
		_share_fraction_defined = true;
		_share_fraction_changed = true;
		_share_fraction = new_value;
	}
	
	// inlined: moved to .hxx file
	// double share_fraction()
	 
	void Share::remove_share_fraction() {
		_share_fraction_exists = false;
		_share_fraction_defined = false;
		_share_fraction_changed = true;
		_share_fraction = (double)0.0;
	}
	
	void Share::undef_share_fraction() {
		_share_fraction_exists = true;
		_share_fraction_defined = false;
		_share_fraction_changed = true;
		_share_fraction = (double)0.0;
	}
	
	bool Share::defined_share_fraction() {
		return _share_fraction_defined;
	}
	
	bool Share::exists_share_fraction() {
		return _share_fraction_exists;
	}
	
	bool Share::changed_share_fraction() {
		return _share_fraction_changed;
	}

	void Share::deadline(unsigned long long int new_value) {
		_deadline_exists = true;
		_deadline_defined = true;
		_deadline_changed = true;
		_deadline = new_value;
	}
	
	// inlined: moved to .hxx file
	// unsigned long long int deadline()
	 
	void Share::remove_deadline() {
		_deadline_exists = false;
		_deadline_defined = false;
		_deadline_changed = true;
		_deadline = (unsigned long long int)0;
	}
	
	void Share::undef_deadline() {
		_deadline_exists = true;
		_deadline_defined = false;
		_deadline_changed = true;
		_deadline = (unsigned long long int)0;
	}
	
	bool Share::defined_deadline() {
		return _deadline_defined;
	}
	
	bool Share::exists_deadline() {
		return _deadline_exists;
	}
	
	bool Share::changed_deadline() {
		return _deadline_changed;
	}

	void Share::deadline_string(std::string new_value) {
		_deadline_string_exists = true;
		_deadline_string_defined = true;
		_deadline_string_changed = true;
		_deadline_string = new_value;
	}
	
	// inlined: moved to .hxx file
	// std::string deadline_string()
	 
	void Share::remove_deadline_string() {
		_deadline_string_exists = false;
		_deadline_string_defined = false;
		_deadline_string_changed = true;
		_deadline_string = "";
	}
	
	void Share::undef_deadline_string() {
		_deadline_string_exists = true;
		_deadline_string_defined = false;
		_deadline_string_changed = true;
		_deadline_string = "";
	}
	
	bool Share::defined_deadline_string() {
		return _deadline_string_defined;
	}
	
	bool Share::exists_deadline_string() {
		return _deadline_string_exists;
	}
	
	bool Share::changed_deadline_string() {
		return _deadline_string_changed;
	}

	void Share::miner(std::string new_value) {
		_miner_exists = true;
		_miner_defined = true;
		_miner_changed = true;
		_miner = new_value;
	}
	
	// inlined: moved to .hxx file
	// std::string miner()
	 
	void Share::remove_miner() {
		_miner_exists = false;
		_miner_defined = false;
		_miner_changed = true;
		_miner = "";
	}
	
	void Share::undef_miner() {
		_miner_exists = true;
		_miner_defined = false;
		_miner_changed = true;
		_miner = "";
	}
	
	bool Share::defined_miner() {
		return _miner_defined;
	}
	
	bool Share::exists_miner() {
		return _miner_exists;
	}
	
	bool Share::changed_miner() {
		return _miner_changed;
	}



// navigator methods

	Block *Share::block() {
		
		
			return Block::load( new IDB::sqlEqUInt64( "blockID", _blockID ) );
		
	}

	Account *Share::account() {
		
		
			return Account::load( new IDB::sqlEqUInt64( "accountID", _accountID ) );
		
	}





// run-time safe!
bool Share::has_field(std::string field) {
	
		if (!field.compare("blockID")) {
			return true;
		}
	
		if (!field.compare("accountID")) {
			return true;
		}
	
		if (!field.compare("share_fraction")) {
			return true;
		}
	
		if (!field.compare("deadline")) {
			return true;
		}
	
		if (!field.compare("deadline_string")) {
			return true;
		}
	
		if (!field.compare("miner")) {
			return true;
		}
	

	return false;
}


// run-time safe!
bool Share::exists_by_name(std::string field) {
	
		if (!field.compare("blockID")) {
			return _blockID_exists;
		}
	
		if (!field.compare("accountID")) {
			return _accountID_exists;
		}
	
		if (!field.compare("share_fraction")) {
			return _share_fraction_exists;
		}
	
		if (!field.compare("deadline")) {
			return _deadline_exists;
		}
	
		if (!field.compare("deadline_string")) {
			return _deadline_string_exists;
		}
	
		if (!field.compare("miner")) {
			return _miner_exists;
		}
	

	return false;
}


bool Share::defined_by_name(std::string field) {
	
		if (!field.compare("blockID")) {
			return _blockID_defined;
		}
	
		if (!field.compare("accountID")) {
			return _accountID_defined;
		}
	
		if (!field.compare("share_fraction")) {
			return _share_fraction_defined;
		}
	
		if (!field.compare("deadline")) {
			return _deadline_defined;
		}
	
		if (!field.compare("deadline_string")) {
			return _deadline_string_defined;
		}
	
		if (!field.compare("miner")) {
			return _miner_defined;
		}
	

	return false;
}


bool Share::is_key_by_name(std::string field) {
	
		if (!field.compare("blockID"))
			return true;
	
		if (!field.compare("accountID"))
			return true;
	

	return false;
}	





	bool Share::get_Boolean_by_name(std::string field) {
		
			
			
			
			
			
			

		std::cerr << "Unimplemented getBoolean_by_name() call for " << field << std::endl;
		return (bool)false;
	}

	std::string Share::get_String_by_name(std::string field) {
		
			
			
			
			
			

			if (!field.compare("deadline_string")) {
				return _deadline_string;
			}
		
			

			if (!field.compare("miner")) {
				return _miner;
			}
		

		std::cerr << "Unimplemented getString_by_name() call for " << field << std::endl;
		return "";
	}

	double Share::get_Double_by_name(std::string field) {
		
			
			
			

			if (!field.compare("share_fraction")) {
				return _share_fraction;
			}
		
			
			
			

		std::cerr << "Unimplemented getDouble_by_name() call for " << field << std::endl;
		return (double)0.0;
	}

	int Share::get_Int_by_name(std::string field) {
		
			
			
			
			
			
			

		std::cerr << "Unimplemented getInt_by_name() call for " << field << std::endl;
		return (int)0;
	}

	time_t Share::get_Timestamp_by_name(std::string field) {
		
			
			
			
			
			
			

		std::cerr << "Unimplemented getTimestamp_by_name() call for " << field << std::endl;
		return (time_t)0;
	}

	unsigned char * Share::get_Blob_by_name(std::string field) {
		
			
			
			
			
			
			

		std::cerr << "Unimplemented getBlob_by_name() call for " << field << std::endl;
		return NULL;
	}

	unsigned int Share::get_UInt_by_name(std::string field) {
		
			
			
			
			
			
			

		std::cerr << "Unimplemented getUInt_by_name() call for " << field << std::endl;
		return (unsigned int)0;
	}

	unsigned long long int Share::get_UInt64_by_name(std::string field) {
		
			

			if (!field.compare("blockID")) {
				return _blockID;
			}
		
			

			if (!field.compare("accountID")) {
				return _accountID;
			}
		
			
			

			if (!field.compare("deadline")) {
				return _deadline;
			}
		
			
			

		std::cerr << "Unimplemented getUInt64_by_name() call for " << field << std::endl;
		return (unsigned long long int)0;
	}



void Share::clear() {
	if (results)
		delete results;
		
	_init();
	_init_columns();
}


Share *Share::clone() {
	Share *c = new Share();
	
	
		if ( _blockID_defined )
			c->blockID( _blockID );
	
		if ( _accountID_defined )
			c->accountID( _accountID );
	
		if ( _share_fraction_defined )
			c->share_fraction( _share_fraction );
	
		if ( _deadline_defined )
			c->deadline( _deadline );
	
		if ( _deadline_string_defined )
			c->deadline_string( _deadline_string );
	
		if ( _miner_defined )
			c->miner( _miner );
	

	return c;
}


Share *Share::skeleton() {
	Share *skel = new Share();
	
	
		
		skel->blockID( _blockID );
	
		
		skel->accountID( _accountID );
	
		
		
		
		

	return skel;
}


Share *Share::load( unsigned long long int blockID, unsigned long long int accountID ) {
	IDB::Where *where_clause = NULL;
	
	
		 
		 	where_clause = new IDB::sqlEqUInt64( "blockID", blockID );
		 
	
		 
		 	where_clause = new IDB::sqlAnd( where_clause, new IDB::sqlEqUInt64( "accountID", accountID ) );
		 
	
	
	return load( where_clause );
};


Share *Share::load(IDB::Where *where_clause) {
	std::vector<std::string>		cols;
	IDB::Tables						*tables = new IDB::Tables("Shares");
	IDB::ResultSet					*res;

	cols.push_back("*");

	/* select * from table where_clause */
	res = idbe()->select(&cols, tables, where_clause, IDB_NO_OPTIONS);
	delete tables;
	// Watch out! Don't forget this little line is in place!
	delete where_clause;

	if (res->next()) {
		/* copy columns */
		// use special private constructor
		Share *loaded_obj = new Share( res );
		delete res;
		return loaded_obj;
	}

	delete res;
	return (Share *)0;
};

/* OLD BUT WORKING VERSION:
Share *Share::load(IO::Object *other_obj) {
	Share *search_obj = new Share(other_obj);
	Share *loaded_obj;

	loaded_obj = search_obj->present();
	delete search_obj;

	return loaded_obj;
};
*/

/* NEW, FASTER VERSION: */
Share *Share::load(IO::Object *other_obj) {
	// all key columns must exist and be defined (i.e. not undef/null)
	
		if ( ! other_obj->defined_by_name( "blockID" ) )
			return NULL;
	
		if ( ! other_obj->defined_by_name( "accountID" ) )
			return NULL;
	
	
	return load( other_obj->get_UInt64_by_name( "blockID" ), other_obj->get_UInt64_by_name( "accountID" ) );
};


std::vector<Share *> Share::load_all_vector() {
	std::vector<Share *> results;

	Share me;
	me.search();
	
	while( Share *result = me.result() ) {
		results.push_back( result );	
	}

	return results;
};



void Share::refresh() {
	std::vector<std::string>		cols;
	IDB::Tables						*tables = new IDB::Tables("Shares");
	IDB::Where						*where_clause = IDB_NO_WHERE;
	IDB::Where						*new_clause;
	IDB::ResultSet					*res;
	
	cols.push_back("*");

	
		

		
			new_clause = new IDB::sqlEqUInt64( "blockID", _blockID );
		

		if (where_clause == IDB_NO_WHERE) {
			where_clause = new_clause;
		} else {
			where_clause = new IDB::sqlAnd( where_clause, new_clause );
		}
	
		

		
			new_clause = new IDB::sqlEqUInt64( "accountID", _accountID );
		

		if (where_clause == IDB_NO_WHERE) {
			where_clause = new_clause;
		} else {
			where_clause = new IDB::sqlAnd( where_clause, new_clause );
		}
	
		
		
		
		

	res = idbe()->select(&cols, tables, where_clause, IDB_NO_OPTIONS);
	delete tables;
	delete where_clause;

	if (res->next()) {
		this->_copy_from_res(res);
	}

	delete res;
};



// heavy lifting for delete_obj()
void Share::_delete_obj() {
	
	
	IDB::Where			*where_clause = IDB_NO_WHERE;
	IDB::Where			*new_clause;

	
		

		// ignore undefined keys - allows a more crude version of search-and-destroy 
		// where objects DON'T have ->delete_obj() called on them but are simply
		// deleted by database
		
		if ( _blockID_defined ) {
			
				new_clause = new IDB::sqlEqUInt64( "blockID", _blockID );
			
	
			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		

		// ignore undefined keys - allows a more crude version of search-and-destroy 
		// where objects DON'T have ->delete_obj() called on them but are simply
		// deleted by database
		
		if ( _accountID_defined ) {
			
				new_clause = new IDB::sqlEqUInt64( "accountID", _accountID );
			
	
			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		
		
		
		

	idbe()->deleterow("Shares", where_clause);
	delete where_clause;
};


Share *Share::present() { return this->present(IDB_NO_OPTIONS, (std::vector<IO::Object *> *) NULL ); }

Share *Share::present(IDB::Options *options, std::vector<IO::Object *> *additional) {
	IO::PreppedSearch		*ps;
	IDB::ResultSet			*res;
	IDB::Options			*tmpOptions = IDB_NO_OPTIONS;

	ps = this->search_prep(options, additional);

	if (!ps->options || ps->options == IDB_NO_OPTIONS) {
		tmpOptions = new IDB::Options();
		ps->options = tmpOptions;
	}

	ps->options->limit = 1;

	res = idbe()->select(ps->cols, ps->tables, ps->where, ps->options);

	if (tmpOptions) {
		delete tmpOptions;
	}

	delete ps;

	if (res->next()) {
		Share *loaded_obj = new Share( res );
		delete res;
		return loaded_obj;
	}

	delete res;
	return (Share *)0;
}


Share *Share::present_or_self() { 
	Share *found = this->present(IDB_NO_OPTIONS, 0);
	
	if (found)
		return found;
	else
		return this;
}


Share *Share::result() {
	if (results) {
		if (results->next()) {
			return new Share( results );
		}
		
		delete results;
		results = NULL;
	}
	
	return (Share *)0;
}


std::vector<Share *> Share::results_vector() {
	std::vector<Share *> output_vector;

	while( Share *vector_entry = result() ) {
		output_vector.push_back( vector_entry );	
	}

	return output_vector;
}

		
// search modifiers

	void Share::before_blockID(uint64_t v) { _SM_before_blockID_p = true; _SM_before_blockID = v; }

	void Share::after_blockID(uint64_t v) { _SM_after_blockID_p = true; _SM_after_blockID = v; }

	void Share::historic_average(bool v) { _SM_historic_average_p = true; _SM_historic_average = v; }

	void Share::mean_weighted_deadline(bool v) { _SM_mean_weighted_deadline_p = true; _SM_mean_weighted_deadline = v; }



// order by
void Share::order_by( Share_columns_t col, order_direction_t dir ) {
	_order_by = Share_column_names[col] + " " + order_direction_names[dir];
}


// check database shape matches code
bool Share::check_db_shape() {
	bool shape_OK = true;

	std::vector<std::string> cols;
	cols.push_back("*");

	IDB::Tables *tables = new IDB::Tables( "INFORMATION_SCHEMA.COLUMNS" );

	IDB::Where *where_schema = new IDB::sqlEqCol( "table_schema", "database()" );
	IDB::Where *where_table = new IDB::sqlEqString( "table_name", "Shares" );
	
	IDB::Where *where = new IDB::sqlAnd( where_schema, where_table );

	IDB::ResultSet *res = idbe()->select(&cols, tables, where, IDB_NO_OPTIONS);

	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "blockID" ) {
				std::cerr << "Shares column #1 should be 'blockID' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Shares column #1 should be 'blockID' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "accountID" ) {
				std::cerr << "Shares column #2 should be 'accountID' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Shares column #2 should be 'accountID' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "share_fraction" ) {
				std::cerr << "Shares column #3 should be 'share_fraction' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Shares column #3 should be 'share_fraction' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "deadline" ) {
				std::cerr << "Shares column #4 should be 'deadline' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Shares column #4 should be 'deadline' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "deadline_string" ) {
				std::cerr << "Shares column #5 should be 'deadline_string' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Shares column #5 should be 'deadline_string' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "miner" ) {
				std::cerr << "Shares column #6 should be 'miner' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Shares column #6 should be 'miner' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	

	return shape_OK;
}


// lock this database record
void Share::lock_record() {
	// SELECT true FROM <table> WHERE <keys> FOR UPDATE
	std::vector<std::string> cols;
	cols.push_back("true");

	IDB::Tables *tables = new IDB::Tables("Shares");

	IDB::Where *where_clause = NULL;
	
	
		 
		 	where_clause = new IDB::sqlEqUInt64( "blockID", _blockID );
		 
	
		 
		 	where_clause = new IDB::sqlAnd( where_clause, new IDB::sqlEqUInt64( "accountID", _accountID ) );
		 
	

	IDB::Options *options = new IDB::Options;
	options->for_update = true;
	
	IDB::ResultSet *res = idbe()->select(&cols, tables, where_clause, options);
	
	delete res;

	delete options;
	delete where_clause;
	delete tables;
}

