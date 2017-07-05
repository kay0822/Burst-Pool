
// object .cxx include file template

#include "Nonce.hpp"

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif

#define FULLTEXT_FIELD(field)

#define SEARCHMOD(name, type)
#define SEARCHMOD_IS_SET(name) _SM_ ## name ## _p
#define SEARCHMOD_VALUE(name) _SM_ ## name
#define SEARCHPREP IO::PreppedSearch *Nonce::search_prep(IDB::Options *options, std::vector<IO::Object *> *additional)
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

const std::string Nonce::_my_table = "Nonces";


// PRIVATE METHODS


// common method to initialize a new object
void Nonce::_init() {
	// init results to null
	results = NULL;

	// initialize search modifiers
	
}


void Nonce::_init_columns() {
	// initialize columns
	
		_accountID_exists = false;
		_accountID_defined = false;
		_accountID_changed = false;
		_accountID = (unsigned long long int)0;
	
		_blockID_exists = false;
		_blockID_defined = false;
		_blockID_changed = false;
		_blockID = (unsigned long long int)0;
	
		_nonce_exists = false;
		_nonce_defined = false;
		_nonce_changed = false;
		_nonce = (unsigned long long int)0;
	
		_submitted_when_exists = false;
		_submitted_when_defined = false;
		_submitted_when_changed = false;
		_submitted_when = (time_t)0;
	
		_deadline_exists = false;
		_deadline_defined = false;
		_deadline_changed = false;
		_deadline = (unsigned long long int)0;
	
		_deadline_string_exists = false;
		_deadline_string_defined = false;
		_deadline_string_changed = false;
		_deadline_string = "";
	
		_forge_when_exists = false;
		_forge_when_defined = false;
		_forge_when_changed = false;
		_forge_when = (time_t)0;
	
		_is_blocks_best_deadline_exists = false;
		_is_blocks_best_deadline_defined = false;
		_is_blocks_best_deadline_changed = false;
		_is_blocks_best_deadline = (bool)false;
	
		_is_accounts_best_deadline_exists = false;
		_is_accounts_best_deadline_defined = false;
		_is_accounts_best_deadline_changed = false;
		_is_accounts_best_deadline = (bool)false;
	
		_miner_exists = false;
		_miner_defined = false;
		_miner_changed = false;
		_miner = "";
	
}


// common method to copy data from an SQL result set into our object
void Nonce::_copy_from_res(IDB::ResultSet *res) {
	
		try {
			
			if ( res->isNull( 1 ) ) {
				this->undef_accountID();
			} else {
				this->accountID( res->getUInt64( 1 ) );
			}
			_accountID_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Nonce column index 0" << std::endl;
			throw(e);
		}
	
		try {
			
			if ( res->isNull( 2 ) ) {
				this->undef_blockID();
			} else {
				this->blockID( res->getUInt64( 2 ) );
			}
			_blockID_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Nonce column index 1" << std::endl;
			throw(e);
		}
	
		try {
			
			if ( res->isNull( 3 ) ) {
				this->undef_nonce();
			} else {
				this->nonce( res->getUInt64( 3 ) );
			}
			_nonce_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Nonce column index 2" << std::endl;
			throw(e);
		}
	
		try {
			
			if ( res->isNull( 4 ) ) {
				this->undef_submitted_when();
			} else {
				this->submitted_when( res->getTimestamp( 4 ) );
			}
			_submitted_when_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Nonce column index 3" << std::endl;
			throw(e);
		}
	
		try {
			
			if ( res->isNull( 5 ) ) {
				this->undef_deadline();
			} else {
				this->deadline( res->getUInt64( 5 ) );
			}
			_deadline_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Nonce column index 4" << std::endl;
			throw(e);
		}
	
		try {
			
			if ( res->isNull( 6 ) ) {
				this->undef_deadline_string();
			} else {
				this->deadline_string( res->getString( 6 ) );
			}
			_deadline_string_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Nonce column index 5" << std::endl;
			throw(e);
		}
	
		try {
			
			if ( res->isNull( 7 ) ) {
				this->undef_forge_when();
			} else {
				this->forge_when( res->getTimestamp( 7 ) );
			}
			_forge_when_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Nonce column index 6" << std::endl;
			throw(e);
		}
	
		try {
			
			if ( res->isNull( 8 ) ) {
				this->undef_is_blocks_best_deadline();
			} else {
				this->is_blocks_best_deadline( res->getBoolean( 8 ) );
			}
			_is_blocks_best_deadline_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Nonce column index 7" << std::endl;
			throw(e);
		}
	
		try {
			
			if ( res->isNull( 9 ) ) {
				this->undef_is_accounts_best_deadline();
			} else {
				this->is_accounts_best_deadline( res->getBoolean( 9 ) );
			}
			_is_accounts_best_deadline_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Nonce column index 8" << std::endl;
			throw(e);
		}
	
		try {
			
			if ( res->isNull( 10 ) ) {
				this->undef_miner();
			} else {
				this->miner( res->getString( 10 ) );
			}
			_miner_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Nonce column index 9" << std::endl;
			throw(e);
		}
	
}


// method to generate generic search WHERE criteria based on columns with values
IDB::Where *Nonce::_search_prep_columns() {
	IDB::Where					*where_clause = IDB_NO_WHERE;
	IDB::Where					*new_clause;

	
		if (_accountID_exists) {
			if (_accountID_defined) {
				
					new_clause = new IDB::sqlEqUInt64( "Nonces.accountID", _accountID );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Nonces.accountID" );
			}

			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		if (_blockID_exists) {
			if (_blockID_defined) {
				
					new_clause = new IDB::sqlEqUInt64( "Nonces.blockID", _blockID );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Nonces.blockID" );
			}

			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		if (_nonce_exists) {
			if (_nonce_defined) {
				
					new_clause = new IDB::sqlEqUInt64( "Nonces.nonce", _nonce );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Nonces.nonce" );
			}

			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		if (_submitted_when_exists) {
			if (_submitted_when_defined) {
				
					new_clause = new IDB::sqlEqString( "Nonces.submitted_when", IDB::Engine::from_unixtime(_submitted_when) );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Nonces.submitted_when" );
			}

			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		if (_deadline_exists) {
			if (_deadline_defined) {
				
					new_clause = new IDB::sqlEqUInt64( "Nonces.deadline", _deadline );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Nonces.deadline" );
			}

			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		if (_deadline_string_exists) {
			if (_deadline_string_defined) {
				
					new_clause = new IDB::sqlEqString( "Nonces.deadline_string", _deadline_string );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Nonces.deadline_string" );
			}

			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		if (_forge_when_exists) {
			if (_forge_when_defined) {
				
					new_clause = new IDB::sqlEqString( "Nonces.forge_when", IDB::Engine::from_unixtime(_forge_when) );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Nonces.forge_when" );
			}

			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		if (_is_blocks_best_deadline_exists) {
			if (_is_blocks_best_deadline_defined) {
				
					new_clause = new IDB::sqlEqBoolean( "Nonces.is_blocks_best_deadline", _is_blocks_best_deadline );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Nonces.is_blocks_best_deadline" );
			}

			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		if (_is_accounts_best_deadline_exists) {
			if (_is_accounts_best_deadline_defined) {
				
					new_clause = new IDB::sqlEqBoolean( "Nonces.is_accounts_best_deadline", _is_accounts_best_deadline );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Nonces.is_accounts_best_deadline" );
			}

			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		if (_miner_exists) {
			if (_miner_defined) {
				
					new_clause = new IDB::sqlEqString( "Nonces.miner", _miner );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Nonces.miner" );
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
IDB::Where *Nonce::_search_prep_join(std::map<std::string, std::string> *col_to_table) {
	IDB::Where									*on_clause = IDB_NO_WHERE;
	std::map<std::string, std::string>::iterator	it;

	
		

		it = col_to_table->find("accountID");
		if (it != col_to_table->end()) {
			std::string col_name = it->second;
			col_name += ".accountID";
			IDB::Where *new_clause = new IDB::sqlEqCol( col_name, "Nonces.accountID" );

			if (on_clause == IDB_NO_WHERE) {
				on_clause = new_clause;
			} else {
				on_clause = new IDB::sqlAnd( on_clause, new_clause );
			}
		}
	
		

		it = col_to_table->find("blockID");
		if (it != col_to_table->end()) {
			std::string col_name = it->second;
			col_name += ".blockID";
			IDB::Where *new_clause = new IDB::sqlEqCol( col_name, "Nonces.blockID" );

			if (on_clause == IDB_NO_WHERE) {
				on_clause = new_clause;
			} else {
				on_clause = new IDB::sqlAnd( on_clause, new_clause );
			}
		}
	
		

		it = col_to_table->find("nonce");
		if (it != col_to_table->end()) {
			std::string col_name = it->second;
			col_name += ".nonce";
			IDB::Where *new_clause = new IDB::sqlEqCol( col_name, "Nonces.nonce" );

			if (on_clause == IDB_NO_WHERE) {
				on_clause = new_clause;
			} else {
				on_clause = new IDB::sqlAnd( on_clause, new_clause );
			}
		}
	
		
		
		
		
		
		
		

	return on_clause;
}


// method to do heavy lifting unique to this object for real search_prep() method
IO::PreppedSearch *Nonce::_search_prep(IDB::Options *options, std::vector<IO::Object *> *additional) {
	IO::PreppedSearch							*ps = new IO::PreppedSearch();
	IDB::Tables									*tables = new IDB::Tables("Nonces");
	IDB::Where									*where_clause = IDB_NO_WHERE;
	IDB::Where									*new_clause;
	std::map<std::string, std::string>			col_to_table;

	where_clause = this->_search_prep_columns();

	
		col_to_table["accountID"] = "Nonces";
	
		col_to_table["blockID"] = "Nonces";
	
		col_to_table["nonce"] = "Nonces";
	
		col_to_table["submitted_when"] = "Nonces";
	
		col_to_table["deadline"] = "Nonces";
	
		col_to_table["deadline_string"] = "Nonces";
	
		col_to_table["forge_when"] = "Nonces";
	
		col_to_table["is_blocks_best_deadline"] = "Nonces";
	
		col_to_table["is_accounts_best_deadline"] = "Nonces";
	
		col_to_table["miner"] = "Nonces";
	
	
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
	ps->cols->push_back("distinct Nonces.*");

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
void Nonce::_save() {
	std::vector<IDB::Where *>	updates;
	unsigned int				n_updates = 0;

	
		/* keys dealt with later on */
		
		/* keys dealt with later on */
		
		/* keys dealt with later on */
		
		/* keys dealt with later on */
		

		/* add submitted_when to record if exists */
		#ifdef MINIMAL_SAVE
			if (_submitted_when_changed) {
		#endif
				if (_submitted_when_exists) {
					if (_submitted_when_defined) {
						
							updates.push_back( new IDB::sqlEqString( "submitted_when", IDB::Engine::from_unixtime(_submitted_when) ) );
								
					} else {
						updates.push_back( new IDB::sqlEqNull( "submitted_when" ) );
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
		

		/* add forge_when to record if exists */
		#ifdef MINIMAL_SAVE
			if (_forge_when_changed) {
		#endif
				if (_forge_when_exists) {
					if (_forge_when_defined) {
						
							updates.push_back( new IDB::sqlEqString( "forge_when", IDB::Engine::from_unixtime(_forge_when) ) );
								
					} else {
						updates.push_back( new IDB::sqlEqNull( "forge_when" ) );
					}
				}
		#ifdef MINIMAL_SAVE
			}
		#endif				
	
		/* keys dealt with later on */
		

		/* add is_blocks_best_deadline to record if exists */
		#ifdef MINIMAL_SAVE
			if (_is_blocks_best_deadline_changed) {
		#endif
				if (_is_blocks_best_deadline_exists) {
					if (_is_blocks_best_deadline_defined) {
						
							updates.push_back( new IDB::sqlEqBoolean( "is_blocks_best_deadline", _is_blocks_best_deadline ) );
								
					} else {
						updates.push_back( new IDB::sqlEqNull( "is_blocks_best_deadline" ) );
					}
				}
		#ifdef MINIMAL_SAVE
			}
		#endif				
	
		/* keys dealt with later on */
		

		/* add is_accounts_best_deadline to record if exists */
		#ifdef MINIMAL_SAVE
			if (_is_accounts_best_deadline_changed) {
		#endif
				if (_is_accounts_best_deadline_exists) {
					if (_is_accounts_best_deadline_defined) {
						
							updates.push_back( new IDB::sqlEqBoolean( "is_accounts_best_deadline", _is_accounts_best_deadline ) );
								
					} else {
						updates.push_back( new IDB::sqlEqNull( "is_accounts_best_deadline" ) );
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
	

	/* keys: accountID blockID nonce */
	
		

		if (_accountID_exists) {
			if (_accountID_defined) {
				/* add accountID to updates */
				updates.push_back( new IDB::sqlEqUInt64( "accountID", _accountID ) );
			}
		}
	
		

		if (_blockID_exists) {
			if (_blockID_defined) {
				/* add blockID to updates */
				updates.push_back( new IDB::sqlEqUInt64( "blockID", _blockID ) );
			}
		}
	
		

		if (_nonce_exists) {
			if (_nonce_defined) {
				/* add nonce to updates */
				updates.push_back( new IDB::sqlEqUInt64( "nonce", _nonce ) );
			}
		}
	
		
		
		
		
		
		
		

	/* do save */
	idbe()->writerow("Nonces", updates);

	/* clean updates */
	for(int i = 0; i < updates.size(); i++) {
		IDB::Where	*where = updates[i];
		delete where;
	}

	/* reset changed-ness */
	
		_accountID_changed = false;
	
		_blockID_changed = false;
	
		_nonce_changed = false;
	
		_submitted_when_changed = false;
	
		_deadline_changed = false;
	
		_deadline_string_changed = false;
	
		_forge_when_changed = false;
	
		_is_blocks_best_deadline_changed = false;
	
		_is_accounts_best_deadline_changed = false;
	
		_miner_changed = false;
		

	/* autoinc support */
	
};


// special private constructor for internal use that doesn't clean column values
Nonce::Nonce( IDB::ResultSet *res ): IO::Object() {
	this->_init();
	this->_copy_from_res( res );
};


// PUBLIC METHODS
const std::string Nonce::Nonce_column_names[] = {
	
		"accountID",
	
		"blockID",
	
		"nonce",
	
		"submitted_when",
	
		"deadline",
	
		"deadline_string",
	
		"forge_when",
	
		"is_blocks_best_deadline",
	
		"is_accounts_best_deadline",
	
		"miner",
	
};

// our table
std::string Nonce::_table() {
	return "Nonces";
}


// generic constructor
Nonce::Nonce() {
	this->_init_columns();
	this->_init();
};


// constructor that uses columns from another object (must be key field in other object)
Nonce::Nonce(IO::Object *other_obj): IO::Object() {
	this->_init();

	
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
	
		if ( other_obj->is_key_by_name("nonce") )
			if ( other_obj->exists_by_name("nonce") )
				if ( other_obj->defined_by_name("nonce") )
					this->nonce( other_obj->get_UInt64_by_name("nonce") );
				else
					this->remove_nonce();
			else
				this->remove_nonce();
		else
			this->remove_nonce();
	
		if ( other_obj->is_key_by_name("submitted_when") )
			if ( other_obj->exists_by_name("submitted_when") )
				if ( other_obj->defined_by_name("submitted_when") )
					this->submitted_when( other_obj->get_Timestamp_by_name("submitted_when") );
				else
					this->remove_submitted_when();
			else
				this->remove_submitted_when();
		else
			this->remove_submitted_when();
	
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
	
		if ( other_obj->is_key_by_name("forge_when") )
			if ( other_obj->exists_by_name("forge_when") )
				if ( other_obj->defined_by_name("forge_when") )
					this->forge_when( other_obj->get_Timestamp_by_name("forge_when") );
				else
					this->remove_forge_when();
			else
				this->remove_forge_when();
		else
			this->remove_forge_when();
	
		if ( other_obj->is_key_by_name("is_blocks_best_deadline") )
			if ( other_obj->exists_by_name("is_blocks_best_deadline") )
				if ( other_obj->defined_by_name("is_blocks_best_deadline") )
					this->is_blocks_best_deadline( other_obj->get_Boolean_by_name("is_blocks_best_deadline") );
				else
					this->remove_is_blocks_best_deadline();
			else
				this->remove_is_blocks_best_deadline();
		else
			this->remove_is_blocks_best_deadline();
	
		if ( other_obj->is_key_by_name("is_accounts_best_deadline") )
			if ( other_obj->exists_by_name("is_accounts_best_deadline") )
				if ( other_obj->defined_by_name("is_accounts_best_deadline") )
					this->is_accounts_best_deadline( other_obj->get_Boolean_by_name("is_accounts_best_deadline") );
				else
					this->remove_is_accounts_best_deadline();
			else
				this->remove_is_accounts_best_deadline();
		else
			this->remove_is_accounts_best_deadline();
	
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
Nonce::~Nonce() {
	if (results)
		delete results;
}


// column accessor methods

	void Nonce::accountID(unsigned long long int new_value) {
		_accountID_exists = true;
		_accountID_defined = true;
		_accountID_changed = true;
		_accountID = new_value;
	}
	
	// inlined: moved to .hxx file
	// unsigned long long int accountID()
	 
	void Nonce::remove_accountID() {
		_accountID_exists = false;
		_accountID_defined = false;
		_accountID_changed = true;
		_accountID = (unsigned long long int)0;
	}
	
	void Nonce::undef_accountID() {
		_accountID_exists = true;
		_accountID_defined = false;
		_accountID_changed = true;
		_accountID = (unsigned long long int)0;
	}
	
	bool Nonce::defined_accountID() {
		return _accountID_defined;
	}
	
	bool Nonce::exists_accountID() {
		return _accountID_exists;
	}
	
	bool Nonce::changed_accountID() {
		return _accountID_changed;
	}

	void Nonce::blockID(unsigned long long int new_value) {
		_blockID_exists = true;
		_blockID_defined = true;
		_blockID_changed = true;
		_blockID = new_value;
	}
	
	// inlined: moved to .hxx file
	// unsigned long long int blockID()
	 
	void Nonce::remove_blockID() {
		_blockID_exists = false;
		_blockID_defined = false;
		_blockID_changed = true;
		_blockID = (unsigned long long int)0;
	}
	
	void Nonce::undef_blockID() {
		_blockID_exists = true;
		_blockID_defined = false;
		_blockID_changed = true;
		_blockID = (unsigned long long int)0;
	}
	
	bool Nonce::defined_blockID() {
		return _blockID_defined;
	}
	
	bool Nonce::exists_blockID() {
		return _blockID_exists;
	}
	
	bool Nonce::changed_blockID() {
		return _blockID_changed;
	}

	void Nonce::nonce(unsigned long long int new_value) {
		_nonce_exists = true;
		_nonce_defined = true;
		_nonce_changed = true;
		_nonce = new_value;
	}
	
	// inlined: moved to .hxx file
	// unsigned long long int nonce()
	 
	void Nonce::remove_nonce() {
		_nonce_exists = false;
		_nonce_defined = false;
		_nonce_changed = true;
		_nonce = (unsigned long long int)0;
	}
	
	void Nonce::undef_nonce() {
		_nonce_exists = true;
		_nonce_defined = false;
		_nonce_changed = true;
		_nonce = (unsigned long long int)0;
	}
	
	bool Nonce::defined_nonce() {
		return _nonce_defined;
	}
	
	bool Nonce::exists_nonce() {
		return _nonce_exists;
	}
	
	bool Nonce::changed_nonce() {
		return _nonce_changed;
	}

	void Nonce::submitted_when(time_t new_value) {
		_submitted_when_exists = true;
		_submitted_when_defined = true;
		_submitted_when_changed = true;
		_submitted_when = new_value;
	}
	
	// inlined: moved to .hxx file
	// time_t submitted_when()
	 
	void Nonce::remove_submitted_when() {
		_submitted_when_exists = false;
		_submitted_when_defined = false;
		_submitted_when_changed = true;
		_submitted_when = (time_t)0;
	}
	
	void Nonce::undef_submitted_when() {
		_submitted_when_exists = true;
		_submitted_when_defined = false;
		_submitted_when_changed = true;
		_submitted_when = (time_t)0;
	}
	
	bool Nonce::defined_submitted_when() {
		return _submitted_when_defined;
	}
	
	bool Nonce::exists_submitted_when() {
		return _submitted_when_exists;
	}
	
	bool Nonce::changed_submitted_when() {
		return _submitted_when_changed;
	}

	void Nonce::deadline(unsigned long long int new_value) {
		_deadline_exists = true;
		_deadline_defined = true;
		_deadline_changed = true;
		_deadline = new_value;
	}
	
	// inlined: moved to .hxx file
	// unsigned long long int deadline()
	 
	void Nonce::remove_deadline() {
		_deadline_exists = false;
		_deadline_defined = false;
		_deadline_changed = true;
		_deadline = (unsigned long long int)0;
	}
	
	void Nonce::undef_deadline() {
		_deadline_exists = true;
		_deadline_defined = false;
		_deadline_changed = true;
		_deadline = (unsigned long long int)0;
	}
	
	bool Nonce::defined_deadline() {
		return _deadline_defined;
	}
	
	bool Nonce::exists_deadline() {
		return _deadline_exists;
	}
	
	bool Nonce::changed_deadline() {
		return _deadline_changed;
	}

	void Nonce::deadline_string(std::string new_value) {
		_deadline_string_exists = true;
		_deadline_string_defined = true;
		_deadline_string_changed = true;
		_deadline_string = new_value;
	}
	
	// inlined: moved to .hxx file
	// std::string deadline_string()
	 
	void Nonce::remove_deadline_string() {
		_deadline_string_exists = false;
		_deadline_string_defined = false;
		_deadline_string_changed = true;
		_deadline_string = "";
	}
	
	void Nonce::undef_deadline_string() {
		_deadline_string_exists = true;
		_deadline_string_defined = false;
		_deadline_string_changed = true;
		_deadline_string = "";
	}
	
	bool Nonce::defined_deadline_string() {
		return _deadline_string_defined;
	}
	
	bool Nonce::exists_deadline_string() {
		return _deadline_string_exists;
	}
	
	bool Nonce::changed_deadline_string() {
		return _deadline_string_changed;
	}

	void Nonce::forge_when(time_t new_value) {
		_forge_when_exists = true;
		_forge_when_defined = true;
		_forge_when_changed = true;
		_forge_when = new_value;
	}
	
	// inlined: moved to .hxx file
	// time_t forge_when()
	 
	void Nonce::remove_forge_when() {
		_forge_when_exists = false;
		_forge_when_defined = false;
		_forge_when_changed = true;
		_forge_when = (time_t)0;
	}
	
	void Nonce::undef_forge_when() {
		_forge_when_exists = true;
		_forge_when_defined = false;
		_forge_when_changed = true;
		_forge_when = (time_t)0;
	}
	
	bool Nonce::defined_forge_when() {
		return _forge_when_defined;
	}
	
	bool Nonce::exists_forge_when() {
		return _forge_when_exists;
	}
	
	bool Nonce::changed_forge_when() {
		return _forge_when_changed;
	}

	void Nonce::is_blocks_best_deadline(bool new_value) {
		_is_blocks_best_deadline_exists = true;
		_is_blocks_best_deadline_defined = true;
		_is_blocks_best_deadline_changed = true;
		_is_blocks_best_deadline = new_value;
	}
	
	// inlined: moved to .hxx file
	// bool is_blocks_best_deadline()
	 
	void Nonce::remove_is_blocks_best_deadline() {
		_is_blocks_best_deadline_exists = false;
		_is_blocks_best_deadline_defined = false;
		_is_blocks_best_deadline_changed = true;
		_is_blocks_best_deadline = (bool)false;
	}
	
	void Nonce::undef_is_blocks_best_deadline() {
		_is_blocks_best_deadline_exists = true;
		_is_blocks_best_deadline_defined = false;
		_is_blocks_best_deadline_changed = true;
		_is_blocks_best_deadline = (bool)false;
	}
	
	bool Nonce::defined_is_blocks_best_deadline() {
		return _is_blocks_best_deadline_defined;
	}
	
	bool Nonce::exists_is_blocks_best_deadline() {
		return _is_blocks_best_deadline_exists;
	}
	
	bool Nonce::changed_is_blocks_best_deadline() {
		return _is_blocks_best_deadline_changed;
	}

	void Nonce::is_accounts_best_deadline(bool new_value) {
		_is_accounts_best_deadline_exists = true;
		_is_accounts_best_deadline_defined = true;
		_is_accounts_best_deadline_changed = true;
		_is_accounts_best_deadline = new_value;
	}
	
	// inlined: moved to .hxx file
	// bool is_accounts_best_deadline()
	 
	void Nonce::remove_is_accounts_best_deadline() {
		_is_accounts_best_deadline_exists = false;
		_is_accounts_best_deadline_defined = false;
		_is_accounts_best_deadline_changed = true;
		_is_accounts_best_deadline = (bool)false;
	}
	
	void Nonce::undef_is_accounts_best_deadline() {
		_is_accounts_best_deadline_exists = true;
		_is_accounts_best_deadline_defined = false;
		_is_accounts_best_deadline_changed = true;
		_is_accounts_best_deadline = (bool)false;
	}
	
	bool Nonce::defined_is_accounts_best_deadline() {
		return _is_accounts_best_deadline_defined;
	}
	
	bool Nonce::exists_is_accounts_best_deadline() {
		return _is_accounts_best_deadline_exists;
	}
	
	bool Nonce::changed_is_accounts_best_deadline() {
		return _is_accounts_best_deadline_changed;
	}

	void Nonce::miner(std::string new_value) {
		_miner_exists = true;
		_miner_defined = true;
		_miner_changed = true;
		_miner = new_value;
	}
	
	// inlined: moved to .hxx file
	// std::string miner()
	 
	void Nonce::remove_miner() {
		_miner_exists = false;
		_miner_defined = false;
		_miner_changed = true;
		_miner = "";
	}
	
	void Nonce::undef_miner() {
		_miner_exists = true;
		_miner_defined = false;
		_miner_changed = true;
		_miner = "";
	}
	
	bool Nonce::defined_miner() {
		return _miner_defined;
	}
	
	bool Nonce::exists_miner() {
		return _miner_exists;
	}
	
	bool Nonce::changed_miner() {
		return _miner_changed;
	}



// navigator methods

	Account *Nonce::account() {
		
		
			return Account::load( new IDB::sqlEqUInt64( "accountID", _accountID ) );
		
	}

	Block *Nonce::block() {
		
		
			return Block::load( new IDB::sqlEqUInt64( "blockID", _blockID ) );
		
	}





// run-time safe!
bool Nonce::has_field(std::string field) {
	
		if (!field.compare("accountID")) {
			return true;
		}
	
		if (!field.compare("blockID")) {
			return true;
		}
	
		if (!field.compare("nonce")) {
			return true;
		}
	
		if (!field.compare("submitted_when")) {
			return true;
		}
	
		if (!field.compare("deadline")) {
			return true;
		}
	
		if (!field.compare("deadline_string")) {
			return true;
		}
	
		if (!field.compare("forge_when")) {
			return true;
		}
	
		if (!field.compare("is_blocks_best_deadline")) {
			return true;
		}
	
		if (!field.compare("is_accounts_best_deadline")) {
			return true;
		}
	
		if (!field.compare("miner")) {
			return true;
		}
	

	return false;
}


// run-time safe!
bool Nonce::exists_by_name(std::string field) {
	
		if (!field.compare("accountID")) {
			return _accountID_exists;
		}
	
		if (!field.compare("blockID")) {
			return _blockID_exists;
		}
	
		if (!field.compare("nonce")) {
			return _nonce_exists;
		}
	
		if (!field.compare("submitted_when")) {
			return _submitted_when_exists;
		}
	
		if (!field.compare("deadline")) {
			return _deadline_exists;
		}
	
		if (!field.compare("deadline_string")) {
			return _deadline_string_exists;
		}
	
		if (!field.compare("forge_when")) {
			return _forge_when_exists;
		}
	
		if (!field.compare("is_blocks_best_deadline")) {
			return _is_blocks_best_deadline_exists;
		}
	
		if (!field.compare("is_accounts_best_deadline")) {
			return _is_accounts_best_deadline_exists;
		}
	
		if (!field.compare("miner")) {
			return _miner_exists;
		}
	

	return false;
}


bool Nonce::defined_by_name(std::string field) {
	
		if (!field.compare("accountID")) {
			return _accountID_defined;
		}
	
		if (!field.compare("blockID")) {
			return _blockID_defined;
		}
	
		if (!field.compare("nonce")) {
			return _nonce_defined;
		}
	
		if (!field.compare("submitted_when")) {
			return _submitted_when_defined;
		}
	
		if (!field.compare("deadline")) {
			return _deadline_defined;
		}
	
		if (!field.compare("deadline_string")) {
			return _deadline_string_defined;
		}
	
		if (!field.compare("forge_when")) {
			return _forge_when_defined;
		}
	
		if (!field.compare("is_blocks_best_deadline")) {
			return _is_blocks_best_deadline_defined;
		}
	
		if (!field.compare("is_accounts_best_deadline")) {
			return _is_accounts_best_deadline_defined;
		}
	
		if (!field.compare("miner")) {
			return _miner_defined;
		}
	

	return false;
}


bool Nonce::is_key_by_name(std::string field) {
	
		if (!field.compare("accountID"))
			return true;
	
		if (!field.compare("blockID"))
			return true;
	
		if (!field.compare("nonce"))
			return true;
	

	return false;
}	





	bool Nonce::get_Boolean_by_name(std::string field) {
		
			
			
			
			
			
			
			
			

			if (!field.compare("is_blocks_best_deadline")) {
				return _is_blocks_best_deadline;
			}
		
			

			if (!field.compare("is_accounts_best_deadline")) {
				return _is_accounts_best_deadline;
			}
		
			

		std::cerr << "Unimplemented getBoolean_by_name() call for " << field << std::endl;
		return (bool)false;
	}

	std::string Nonce::get_String_by_name(std::string field) {
		
			
			
			
			
			
			

			if (!field.compare("deadline_string")) {
				return _deadline_string;
			}
		
			
			
			
			

			if (!field.compare("miner")) {
				return _miner;
			}
		

		std::cerr << "Unimplemented getString_by_name() call for " << field << std::endl;
		return "";
	}

	double Nonce::get_Double_by_name(std::string field) {
		
			
			
			
			
			
			
			
			
			
			

		std::cerr << "Unimplemented getDouble_by_name() call for " << field << std::endl;
		return (double)0.0;
	}

	int Nonce::get_Int_by_name(std::string field) {
		
			
			
			
			
			
			
			
			
			
			

		std::cerr << "Unimplemented getInt_by_name() call for " << field << std::endl;
		return (int)0;
	}

	time_t Nonce::get_Timestamp_by_name(std::string field) {
		
			
			
			
			

			if (!field.compare("submitted_when")) {
				return _submitted_when;
			}
		
			
			
			

			if (!field.compare("forge_when")) {
				return _forge_when;
			}
		
			
			
			

		std::cerr << "Unimplemented getTimestamp_by_name() call for " << field << std::endl;
		return (time_t)0;
	}

	unsigned char * Nonce::get_Blob_by_name(std::string field) {
		
			
			
			
			
			
			
			
			
			
			

		std::cerr << "Unimplemented getBlob_by_name() call for " << field << std::endl;
		return NULL;
	}

	unsigned int Nonce::get_UInt_by_name(std::string field) {
		
			
			
			
			
			
			
			
			
			
			

		std::cerr << "Unimplemented getUInt_by_name() call for " << field << std::endl;
		return (unsigned int)0;
	}

	unsigned long long int Nonce::get_UInt64_by_name(std::string field) {
		
			

			if (!field.compare("accountID")) {
				return _accountID;
			}
		
			

			if (!field.compare("blockID")) {
				return _blockID;
			}
		
			

			if (!field.compare("nonce")) {
				return _nonce;
			}
		
			
			

			if (!field.compare("deadline")) {
				return _deadline;
			}
		
			
			
			
			
			

		std::cerr << "Unimplemented getUInt64_by_name() call for " << field << std::endl;
		return (unsigned long long int)0;
	}



void Nonce::clear() {
	if (results)
		delete results;
		
	_init();
	_init_columns();
}


Nonce *Nonce::clone() {
	Nonce *c = new Nonce();
	
	
		if ( _accountID_defined )
			c->accountID( _accountID );
	
		if ( _blockID_defined )
			c->blockID( _blockID );
	
		if ( _nonce_defined )
			c->nonce( _nonce );
	
		if ( _submitted_when_defined )
			c->submitted_when( _submitted_when );
	
		if ( _deadline_defined )
			c->deadline( _deadline );
	
		if ( _deadline_string_defined )
			c->deadline_string( _deadline_string );
	
		if ( _forge_when_defined )
			c->forge_when( _forge_when );
	
		if ( _is_blocks_best_deadline_defined )
			c->is_blocks_best_deadline( _is_blocks_best_deadline );
	
		if ( _is_accounts_best_deadline_defined )
			c->is_accounts_best_deadline( _is_accounts_best_deadline );
	
		if ( _miner_defined )
			c->miner( _miner );
	

	return c;
}


Nonce *Nonce::skeleton() {
	Nonce *skel = new Nonce();
	
	
		
		skel->accountID( _accountID );
	
		
		skel->blockID( _blockID );
	
		
		skel->nonce( _nonce );
	
		
		
		
		
		
		
		

	return skel;
}


Nonce *Nonce::load( unsigned long long int accountID, unsigned long long int blockID, unsigned long long int nonce ) {
	IDB::Where *where_clause = NULL;
	
	
		 
		 	where_clause = new IDB::sqlEqUInt64( "accountID", accountID );
		 
	
		 
		 	where_clause = new IDB::sqlAnd( where_clause, new IDB::sqlEqUInt64( "blockID", blockID ) );
		 
	
		 
		 	where_clause = new IDB::sqlAnd( where_clause, new IDB::sqlEqUInt64( "nonce", nonce ) );
		 
	
	
	return load( where_clause );
};


Nonce *Nonce::load(IDB::Where *where_clause) {
	std::vector<std::string>		cols;
	IDB::Tables						*tables = new IDB::Tables("Nonces");
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
		Nonce *loaded_obj = new Nonce( res );
		delete res;
		return loaded_obj;
	}

	delete res;
	return (Nonce *)0;
};

/* OLD BUT WORKING VERSION:
Nonce *Nonce::load(IO::Object *other_obj) {
	Nonce *search_obj = new Nonce(other_obj);
	Nonce *loaded_obj;

	loaded_obj = search_obj->present();
	delete search_obj;

	return loaded_obj;
};
*/

/* NEW, FASTER VERSION: */
Nonce *Nonce::load(IO::Object *other_obj) {
	// all key columns must exist and be defined (i.e. not undef/null)
	
		if ( ! other_obj->defined_by_name( "accountID" ) )
			return NULL;
	
		if ( ! other_obj->defined_by_name( "blockID" ) )
			return NULL;
	
		if ( ! other_obj->defined_by_name( "nonce" ) )
			return NULL;
	
	
	return load( other_obj->get_UInt64_by_name( "accountID" ), other_obj->get_UInt64_by_name( "blockID" ), other_obj->get_UInt64_by_name( "nonce" ) );
};


std::vector<Nonce *> Nonce::load_all_vector() {
	std::vector<Nonce *> results;

	Nonce me;
	me.search();
	
	while( Nonce *result = me.result() ) {
		results.push_back( result );	
	}

	return results;
};



void Nonce::refresh() {
	std::vector<std::string>		cols;
	IDB::Tables						*tables = new IDB::Tables("Nonces");
	IDB::Where						*where_clause = IDB_NO_WHERE;
	IDB::Where						*new_clause;
	IDB::ResultSet					*res;
	
	cols.push_back("*");

	
		

		
			new_clause = new IDB::sqlEqUInt64( "accountID", _accountID );
		

		if (where_clause == IDB_NO_WHERE) {
			where_clause = new_clause;
		} else {
			where_clause = new IDB::sqlAnd( where_clause, new_clause );
		}
	
		

		
			new_clause = new IDB::sqlEqUInt64( "blockID", _blockID );
		

		if (where_clause == IDB_NO_WHERE) {
			where_clause = new_clause;
		} else {
			where_clause = new IDB::sqlAnd( where_clause, new_clause );
		}
	
		

		
			new_clause = new IDB::sqlEqUInt64( "nonce", _nonce );
		

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
void Nonce::_delete_obj() {
	
	
	IDB::Where			*where_clause = IDB_NO_WHERE;
	IDB::Where			*new_clause;

	
		

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
		
		if ( _nonce_defined ) {
			
				new_clause = new IDB::sqlEqUInt64( "nonce", _nonce );
			
	
			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		
		
		
		
		
		
		

	idbe()->deleterow("Nonces", where_clause);
	delete where_clause;
};


Nonce *Nonce::present() { return this->present(IDB_NO_OPTIONS, (std::vector<IO::Object *> *) NULL ); }

Nonce *Nonce::present(IDB::Options *options, std::vector<IO::Object *> *additional) {
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
		Nonce *loaded_obj = new Nonce( res );
		delete res;
		return loaded_obj;
	}

	delete res;
	return (Nonce *)0;
}


Nonce *Nonce::present_or_self() { 
	Nonce *found = this->present(IDB_NO_OPTIONS, 0);
	
	if (found)
		return found;
	else
		return this;
}


Nonce *Nonce::result() {
	if (results) {
		if (results->next()) {
			return new Nonce( results );
		}
		
		delete results;
		results = NULL;
	}
	
	return (Nonce *)0;
}


std::vector<Nonce *> Nonce::results_vector() {
	std::vector<Nonce *> output_vector;

	while( Nonce *vector_entry = result() ) {
		output_vector.push_back( vector_entry );	
	}

	return output_vector;
}

		
// search modifiers



// order by
void Nonce::order_by( Nonce_columns_t col, order_direction_t dir ) {
	_order_by = Nonce_column_names[col] + " " + order_direction_names[dir];
}


// check database shape matches code
bool Nonce::check_db_shape() {
	bool shape_OK = true;

	std::vector<std::string> cols;
	cols.push_back("*");

	IDB::Tables *tables = new IDB::Tables( "INFORMATION_SCHEMA.COLUMNS" );

	IDB::Where *where_schema = new IDB::sqlEqCol( "table_schema", "database()" );
	IDB::Where *where_table = new IDB::sqlEqString( "table_name", "Nonces" );
	
	IDB::Where *where = new IDB::sqlAnd( where_schema, where_table );

	IDB::ResultSet *res = idbe()->select(&cols, tables, where, IDB_NO_OPTIONS);

	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "accountID" ) {
				std::cerr << "Nonces column #1 should be 'accountID' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Nonces column #1 should be 'accountID' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "blockID" ) {
				std::cerr << "Nonces column #2 should be 'blockID' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Nonces column #2 should be 'blockID' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "nonce" ) {
				std::cerr << "Nonces column #3 should be 'nonce' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Nonces column #3 should be 'nonce' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "submitted_when" ) {
				std::cerr << "Nonces column #4 should be 'submitted_when' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Nonces column #4 should be 'submitted_when' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "deadline" ) {
				std::cerr << "Nonces column #5 should be 'deadline' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Nonces column #5 should be 'deadline' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "deadline_string" ) {
				std::cerr << "Nonces column #6 should be 'deadline_string' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Nonces column #6 should be 'deadline_string' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "forge_when" ) {
				std::cerr << "Nonces column #7 should be 'forge_when' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Nonces column #7 should be 'forge_when' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "is_blocks_best_deadline" ) {
				std::cerr << "Nonces column #8 should be 'is_blocks_best_deadline' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Nonces column #8 should be 'is_blocks_best_deadline' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "is_accounts_best_deadline" ) {
				std::cerr << "Nonces column #9 should be 'is_accounts_best_deadline' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Nonces column #9 should be 'is_accounts_best_deadline' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "miner" ) {
				std::cerr << "Nonces column #10 should be 'miner' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Nonces column #10 should be 'miner' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	

	return shape_OK;
}


// lock this database record
void Nonce::lock_record() {
	// SELECT true FROM <table> WHERE <keys> FOR UPDATE
	std::vector<std::string> cols;
	cols.push_back("true");

	IDB::Tables *tables = new IDB::Tables("Nonces");

	IDB::Where *where_clause = NULL;
	
	
		 
		 	where_clause = new IDB::sqlEqUInt64( "accountID", _accountID );
		 
	
		 
		 	where_clause = new IDB::sqlAnd( where_clause, new IDB::sqlEqUInt64( "blockID", _blockID ) );
		 
	
		 
		 	where_clause = new IDB::sqlAnd( where_clause, new IDB::sqlEqUInt64( "nonce", _nonce ) );
		 
	

	IDB::Options *options = new IDB::Options;
	options->for_update = true;
	
	IDB::ResultSet *res = idbe()->select(&cols, tables, where_clause, options);
	
	delete res;

	delete options;
	delete where_clause;
	delete tables;
}

