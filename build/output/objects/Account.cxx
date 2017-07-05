
// object .cxx include file template

#include "Account.hpp"

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif

#define FULLTEXT_FIELD(field)

#define SEARCHMOD(name, type)
#define SEARCHMOD_IS_SET(name) _SM_ ## name ## _p
#define SEARCHMOD_VALUE(name) _SM_ ## name
#define SEARCHPREP IO::PreppedSearch *Account::search_prep(IDB::Options *options, std::vector<IO::Object *> *additional)
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

const std::string Account::_my_table = "Accounts";


// PRIVATE METHODS


// common method to initialize a new object
void Account::_init() {
	// init results to null
	results = NULL;

	// initialize search modifiers
	
		_SM_needs_updating_p = false;
	
		_SM_sum_capacities_p = false;
	
}


void Account::_init_columns() {
	// initialize columns
	
		_accountID_exists = false;
		_accountID_defined = false;
		_accountID_changed = false;
		_accountID = (unsigned long long int)0;
	
		_first_seen_when_exists = false;
		_first_seen_when_defined = false;
		_first_seen_when_changed = false;
		_first_seen_when = (time_t)0;
	
		_reward_recipient_exists = false;
		_reward_recipient_defined = false;
		_reward_recipient_changed = false;
		_reward_recipient = (unsigned long long int)0;
	
		_last_updated_when_exists = false;
		_last_updated_when_defined = false;
		_last_updated_when_changed = false;
		_last_updated_when = (time_t)0;
	
		_last_nonce_exists = false;
		_last_nonce_defined = false;
		_last_nonce_changed = false;
		_last_nonce = (unsigned long long int)0;
	
		_last_nonce_when_exists = false;
		_last_nonce_when_defined = false;
		_last_nonce_when_changed = false;
		_last_nonce_when = (time_t)0;
	
		_account_name_exists = false;
		_account_name_defined = false;
		_account_name_changed = false;
		_account_name = "";
	
		_estimated_capacity_exists = false;
		_estimated_capacity_defined = false;
		_estimated_capacity_changed = false;
		_estimated_capacity = (unsigned long long int)0;
	
		_account_RS_string_exists = false;
		_account_RS_string_defined = false;
		_account_RS_string_changed = false;
		_account_RS_string = "";
	
		_has_used_this_pool_exists = false;
		_has_used_this_pool_defined = false;
		_has_used_this_pool_changed = false;
		_has_used_this_pool = (bool)false;
	
}


// common method to copy data from an SQL result set into our object
void Account::_copy_from_res(IDB::ResultSet *res) {
	
		try {
			
			if ( res->isNull( 1 ) ) {
				this->undef_accountID();
			} else {
				this->accountID( res->getUInt64( 1 ) );
			}
			_accountID_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Account column index 0" << std::endl;
			throw(e);
		}
	
		try {
			
			if ( res->isNull( 2 ) ) {
				this->undef_first_seen_when();
			} else {
				this->first_seen_when( res->getTimestamp( 2 ) );
			}
			_first_seen_when_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Account column index 1" << std::endl;
			throw(e);
		}
	
		try {
			
			if ( res->isNull( 3 ) ) {
				this->undef_reward_recipient();
			} else {
				this->reward_recipient( res->getUInt64( 3 ) );
			}
			_reward_recipient_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Account column index 2" << std::endl;
			throw(e);
		}
	
		try {
			
			if ( res->isNull( 4 ) ) {
				this->undef_last_updated_when();
			} else {
				this->last_updated_when( res->getTimestamp( 4 ) );
			}
			_last_updated_when_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Account column index 3" << std::endl;
			throw(e);
		}
	
		try {
			
			if ( res->isNull( 5 ) ) {
				this->undef_last_nonce();
			} else {
				this->last_nonce( res->getUInt64( 5 ) );
			}
			_last_nonce_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Account column index 4" << std::endl;
			throw(e);
		}
	
		try {
			
			if ( res->isNull( 6 ) ) {
				this->undef_last_nonce_when();
			} else {
				this->last_nonce_when( res->getTimestamp( 6 ) );
			}
			_last_nonce_when_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Account column index 5" << std::endl;
			throw(e);
		}
	
		try {
			
			if ( res->isNull( 7 ) ) {
				this->undef_account_name();
			} else {
				this->account_name( res->getString( 7 ) );
			}
			_account_name_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Account column index 6" << std::endl;
			throw(e);
		}
	
		try {
			
			if ( res->isNull( 8 ) ) {
				this->undef_estimated_capacity();
			} else {
				this->estimated_capacity( res->getUInt64( 8 ) );
			}
			_estimated_capacity_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Account column index 7" << std::endl;
			throw(e);
		}
	
		try {
			
			if ( res->isNull( 9 ) ) {
				this->undef_account_RS_string();
			} else {
				this->account_RS_string( res->getString( 9 ) );
			}
			_account_RS_string_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Account column index 8" << std::endl;
			throw(e);
		}
	
		try {
			
			if ( res->isNull( 10 ) ) {
				this->undef_has_used_this_pool();
			} else {
				this->has_used_this_pool( res->getBoolean( 10 ) );
			}
			_has_used_this_pool_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Account column index 9" << std::endl;
			throw(e);
		}
	
}


// method to generate generic search WHERE criteria based on columns with values
IDB::Where *Account::_search_prep_columns() {
	IDB::Where					*where_clause = IDB_NO_WHERE;
	IDB::Where					*new_clause;

	
		if (_accountID_exists) {
			if (_accountID_defined) {
				
					new_clause = new IDB::sqlEqUInt64( "Accounts.accountID", _accountID );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Accounts.accountID" );
			}

			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		if (_first_seen_when_exists) {
			if (_first_seen_when_defined) {
				
					new_clause = new IDB::sqlEqString( "Accounts.first_seen_when", IDB::Engine::from_unixtime(_first_seen_when) );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Accounts.first_seen_when" );
			}

			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		if (_reward_recipient_exists) {
			if (_reward_recipient_defined) {
				
					new_clause = new IDB::sqlEqUInt64( "Accounts.reward_recipient", _reward_recipient );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Accounts.reward_recipient" );
			}

			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		if (_last_updated_when_exists) {
			if (_last_updated_when_defined) {
				
					new_clause = new IDB::sqlEqString( "Accounts.last_updated_when", IDB::Engine::from_unixtime(_last_updated_when) );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Accounts.last_updated_when" );
			}

			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		if (_last_nonce_exists) {
			if (_last_nonce_defined) {
				
					new_clause = new IDB::sqlEqUInt64( "Accounts.last_nonce", _last_nonce );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Accounts.last_nonce" );
			}

			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		if (_last_nonce_when_exists) {
			if (_last_nonce_when_defined) {
				
					new_clause = new IDB::sqlEqString( "Accounts.last_nonce_when", IDB::Engine::from_unixtime(_last_nonce_when) );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Accounts.last_nonce_when" );
			}

			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		if (_account_name_exists) {
			if (_account_name_defined) {
				
					new_clause = new IDB::sqlEqString( "Accounts.account_name", _account_name );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Accounts.account_name" );
			}

			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		if (_estimated_capacity_exists) {
			if (_estimated_capacity_defined) {
				
					new_clause = new IDB::sqlEqUInt64( "Accounts.estimated_capacity", _estimated_capacity );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Accounts.estimated_capacity" );
			}

			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		if (_account_RS_string_exists) {
			if (_account_RS_string_defined) {
				
					new_clause = new IDB::sqlEqString( "Accounts.account_RS_string", _account_RS_string );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Accounts.account_RS_string" );
			}

			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		if (_has_used_this_pool_exists) {
			if (_has_used_this_pool_defined) {
				
					new_clause = new IDB::sqlEqBoolean( "Accounts.has_used_this_pool", _has_used_this_pool );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Accounts.has_used_this_pool" );
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
IDB::Where *Account::_search_prep_join(std::map<std::string, std::string> *col_to_table) {
	IDB::Where									*on_clause = IDB_NO_WHERE;
	std::map<std::string, std::string>::iterator	it;

	
		

		it = col_to_table->find("accountID");
		if (it != col_to_table->end()) {
			std::string col_name = it->second;
			col_name += ".accountID";
			IDB::Where *new_clause = new IDB::sqlEqCol( col_name, "Accounts.accountID" );

			if (on_clause == IDB_NO_WHERE) {
				on_clause = new_clause;
			} else {
				on_clause = new IDB::sqlAnd( on_clause, new_clause );
			}
		}
	
		
		
		
		
		
		
		
		
		

	return on_clause;
}


// method to do heavy lifting unique to this object for real search_prep() method
IO::PreppedSearch *Account::_search_prep(IDB::Options *options, std::vector<IO::Object *> *additional) {
	IO::PreppedSearch							*ps = new IO::PreppedSearch();
	IDB::Tables									*tables = new IDB::Tables("Accounts");
	IDB::Where									*where_clause = IDB_NO_WHERE;
	IDB::Where									*new_clause;
	std::map<std::string, std::string>			col_to_table;

	where_clause = this->_search_prep_columns();

	
		col_to_table["accountID"] = "Accounts";
	
		col_to_table["first_seen_when"] = "Accounts";
	
		col_to_table["reward_recipient"] = "Accounts";
	
		col_to_table["last_updated_when"] = "Accounts";
	
		col_to_table["last_nonce"] = "Accounts";
	
		col_to_table["last_nonce_when"] = "Accounts";
	
		col_to_table["account_name"] = "Accounts";
	
		col_to_table["estimated_capacity"] = "Accounts";
	
		col_to_table["account_RS_string"] = "Accounts";
	
		col_to_table["has_used_this_pool"] = "Accounts";
	
	
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
	ps->cols->push_back("distinct Accounts.*");

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
void Account::_save() {
	std::vector<IDB::Where *>	updates;
	unsigned int				n_updates = 0;

	
		/* keys dealt with later on */
		
		/* keys dealt with later on */
		

		/* add first_seen_when to record if exists */
		#ifdef MINIMAL_SAVE
			if (_first_seen_when_changed) {
		#endif
				if (_first_seen_when_exists) {
					if (_first_seen_when_defined) {
						
							updates.push_back( new IDB::sqlEqString( "first_seen_when", IDB::Engine::from_unixtime(_first_seen_when) ) );
								
					} else {
						updates.push_back( new IDB::sqlEqNull( "first_seen_when" ) );
					}
				}
		#ifdef MINIMAL_SAVE
			}
		#endif				
	
		/* keys dealt with later on */
		

		/* add reward_recipient to record if exists */
		#ifdef MINIMAL_SAVE
			if (_reward_recipient_changed) {
		#endif
				if (_reward_recipient_exists) {
					if (_reward_recipient_defined) {
						
							updates.push_back( new IDB::sqlEqUInt64( "reward_recipient", _reward_recipient ) );
								
					} else {
						updates.push_back( new IDB::sqlEqNull( "reward_recipient" ) );
					}
				}
		#ifdef MINIMAL_SAVE
			}
		#endif				
	
		/* keys dealt with later on */
		

		/* add last_updated_when to record if exists */
		#ifdef MINIMAL_SAVE
			if (_last_updated_when_changed) {
		#endif
				if (_last_updated_when_exists) {
					if (_last_updated_when_defined) {
						
							updates.push_back( new IDB::sqlEqString( "last_updated_when", IDB::Engine::from_unixtime(_last_updated_when) ) );
								
					} else {
						updates.push_back( new IDB::sqlEqNull( "last_updated_when" ) );
					}
				}
		#ifdef MINIMAL_SAVE
			}
		#endif				
	
		/* keys dealt with later on */
		

		/* add last_nonce to record if exists */
		#ifdef MINIMAL_SAVE
			if (_last_nonce_changed) {
		#endif
				if (_last_nonce_exists) {
					if (_last_nonce_defined) {
						
							updates.push_back( new IDB::sqlEqUInt64( "last_nonce", _last_nonce ) );
								
					} else {
						updates.push_back( new IDB::sqlEqNull( "last_nonce" ) );
					}
				}
		#ifdef MINIMAL_SAVE
			}
		#endif				
	
		/* keys dealt with later on */
		

		/* add last_nonce_when to record if exists */
		#ifdef MINIMAL_SAVE
			if (_last_nonce_when_changed) {
		#endif
				if (_last_nonce_when_exists) {
					if (_last_nonce_when_defined) {
						
							updates.push_back( new IDB::sqlEqString( "last_nonce_when", IDB::Engine::from_unixtime(_last_nonce_when) ) );
								
					} else {
						updates.push_back( new IDB::sqlEqNull( "last_nonce_when" ) );
					}
				}
		#ifdef MINIMAL_SAVE
			}
		#endif				
	
		/* keys dealt with later on */
		

		/* add account_name to record if exists */
		#ifdef MINIMAL_SAVE
			if (_account_name_changed) {
		#endif
				if (_account_name_exists) {
					if (_account_name_defined) {
						
							updates.push_back( new IDB::sqlEqString( "account_name", _account_name ) );
								
					} else {
						updates.push_back( new IDB::sqlEqNull( "account_name" ) );
					}
				}
		#ifdef MINIMAL_SAVE
			}
		#endif				
	
		/* keys dealt with later on */
		

		/* add estimated_capacity to record if exists */
		#ifdef MINIMAL_SAVE
			if (_estimated_capacity_changed) {
		#endif
				if (_estimated_capacity_exists) {
					if (_estimated_capacity_defined) {
						
							updates.push_back( new IDB::sqlEqUInt64( "estimated_capacity", _estimated_capacity ) );
								
					} else {
						updates.push_back( new IDB::sqlEqNull( "estimated_capacity" ) );
					}
				}
		#ifdef MINIMAL_SAVE
			}
		#endif				
	
		/* keys dealt with later on */
		

		/* add account_RS_string to record if exists */
		#ifdef MINIMAL_SAVE
			if (_account_RS_string_changed) {
		#endif
				if (_account_RS_string_exists) {
					if (_account_RS_string_defined) {
						
							updates.push_back( new IDB::sqlEqString( "account_RS_string", _account_RS_string ) );
								
					} else {
						updates.push_back( new IDB::sqlEqNull( "account_RS_string" ) );
					}
				}
		#ifdef MINIMAL_SAVE
			}
		#endif				
	
		/* keys dealt with later on */
		

		/* add has_used_this_pool to record if exists */
		#ifdef MINIMAL_SAVE
			if (_has_used_this_pool_changed) {
		#endif
				if (_has_used_this_pool_exists) {
					if (_has_used_this_pool_defined) {
						
							updates.push_back( new IDB::sqlEqBoolean( "has_used_this_pool", _has_used_this_pool ) );
								
					} else {
						updates.push_back( new IDB::sqlEqNull( "has_used_this_pool" ) );
					}
				}
		#ifdef MINIMAL_SAVE
			}
		#endif				
	

	/* keys: accountID */
	
		

		if (_accountID_exists) {
			if (_accountID_defined) {
				/* add accountID to updates */
				updates.push_back( new IDB::sqlEqUInt64( "accountID", _accountID ) );
			}
		}
	
		
		
		
		
		
		
		
		
		

	/* do save */
	idbe()->writerow("Accounts", updates);

	/* clean updates */
	for(int i = 0; i < updates.size(); i++) {
		IDB::Where	*where = updates[i];
		delete where;
	}

	/* reset changed-ness */
	
		_accountID_changed = false;
	
		_first_seen_when_changed = false;
	
		_reward_recipient_changed = false;
	
		_last_updated_when_changed = false;
	
		_last_nonce_changed = false;
	
		_last_nonce_when_changed = false;
	
		_account_name_changed = false;
	
		_estimated_capacity_changed = false;
	
		_account_RS_string_changed = false;
	
		_has_used_this_pool_changed = false;
		

	/* autoinc support */
	
};


// special private constructor for internal use that doesn't clean column values
Account::Account( IDB::ResultSet *res ): IO::Object() {
	this->_init();
	this->_copy_from_res( res );
};


// PUBLIC METHODS
const std::string Account::Account_column_names[] = {
	
		"accountID",
	
		"first_seen_when",
	
		"reward_recipient",
	
		"last_updated_when",
	
		"last_nonce",
	
		"last_nonce_when",
	
		"account_name",
	
		"estimated_capacity",
	
		"account_RS_string",
	
		"has_used_this_pool",
	
};

// our table
std::string Account::_table() {
	return "Accounts";
}


// generic constructor
Account::Account() {
	this->_init_columns();
	this->_init();
};


// constructor that uses columns from another object (must be key field in other object)
Account::Account(IO::Object *other_obj): IO::Object() {
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
	
		if ( other_obj->is_key_by_name("first_seen_when") )
			if ( other_obj->exists_by_name("first_seen_when") )
				if ( other_obj->defined_by_name("first_seen_when") )
					this->first_seen_when( other_obj->get_Timestamp_by_name("first_seen_when") );
				else
					this->remove_first_seen_when();
			else
				this->remove_first_seen_when();
		else
			this->remove_first_seen_when();
	
		if ( other_obj->is_key_by_name("reward_recipient") )
			if ( other_obj->exists_by_name("reward_recipient") )
				if ( other_obj->defined_by_name("reward_recipient") )
					this->reward_recipient( other_obj->get_UInt64_by_name("reward_recipient") );
				else
					this->remove_reward_recipient();
			else
				this->remove_reward_recipient();
		else
			this->remove_reward_recipient();
	
		if ( other_obj->is_key_by_name("last_updated_when") )
			if ( other_obj->exists_by_name("last_updated_when") )
				if ( other_obj->defined_by_name("last_updated_when") )
					this->last_updated_when( other_obj->get_Timestamp_by_name("last_updated_when") );
				else
					this->remove_last_updated_when();
			else
				this->remove_last_updated_when();
		else
			this->remove_last_updated_when();
	
		if ( other_obj->is_key_by_name("last_nonce") )
			if ( other_obj->exists_by_name("last_nonce") )
				if ( other_obj->defined_by_name("last_nonce") )
					this->last_nonce( other_obj->get_UInt64_by_name("last_nonce") );
				else
					this->remove_last_nonce();
			else
				this->remove_last_nonce();
		else
			this->remove_last_nonce();
	
		if ( other_obj->is_key_by_name("last_nonce_when") )
			if ( other_obj->exists_by_name("last_nonce_when") )
				if ( other_obj->defined_by_name("last_nonce_when") )
					this->last_nonce_when( other_obj->get_Timestamp_by_name("last_nonce_when") );
				else
					this->remove_last_nonce_when();
			else
				this->remove_last_nonce_when();
		else
			this->remove_last_nonce_when();
	
		if ( other_obj->is_key_by_name("account_name") )
			if ( other_obj->exists_by_name("account_name") )
				if ( other_obj->defined_by_name("account_name") )
					this->account_name( other_obj->get_String_by_name("account_name") );
				else
					this->remove_account_name();
			else
				this->remove_account_name();
		else
			this->remove_account_name();
	
		if ( other_obj->is_key_by_name("estimated_capacity") )
			if ( other_obj->exists_by_name("estimated_capacity") )
				if ( other_obj->defined_by_name("estimated_capacity") )
					this->estimated_capacity( other_obj->get_UInt64_by_name("estimated_capacity") );
				else
					this->remove_estimated_capacity();
			else
				this->remove_estimated_capacity();
		else
			this->remove_estimated_capacity();
	
		if ( other_obj->is_key_by_name("account_RS_string") )
			if ( other_obj->exists_by_name("account_RS_string") )
				if ( other_obj->defined_by_name("account_RS_string") )
					this->account_RS_string( other_obj->get_String_by_name("account_RS_string") );
				else
					this->remove_account_RS_string();
			else
				this->remove_account_RS_string();
		else
			this->remove_account_RS_string();
	
		if ( other_obj->is_key_by_name("has_used_this_pool") )
			if ( other_obj->exists_by_name("has_used_this_pool") )
				if ( other_obj->defined_by_name("has_used_this_pool") )
					this->has_used_this_pool( other_obj->get_Boolean_by_name("has_used_this_pool") );
				else
					this->remove_has_used_this_pool();
			else
				this->remove_has_used_this_pool();
		else
			this->remove_has_used_this_pool();
	
};


// destructor
Account::~Account() {
	if (results)
		delete results;
}


// column accessor methods

	void Account::accountID(unsigned long long int new_value) {
		_accountID_exists = true;
		_accountID_defined = true;
		_accountID_changed = true;
		_accountID = new_value;
	}
	
	// inlined: moved to .hxx file
	// unsigned long long int accountID()
	 
	void Account::remove_accountID() {
		_accountID_exists = false;
		_accountID_defined = false;
		_accountID_changed = true;
		_accountID = (unsigned long long int)0;
	}
	
	void Account::undef_accountID() {
		_accountID_exists = true;
		_accountID_defined = false;
		_accountID_changed = true;
		_accountID = (unsigned long long int)0;
	}
	
	bool Account::defined_accountID() {
		return _accountID_defined;
	}
	
	bool Account::exists_accountID() {
		return _accountID_exists;
	}
	
	bool Account::changed_accountID() {
		return _accountID_changed;
	}

	void Account::first_seen_when(time_t new_value) {
		_first_seen_when_exists = true;
		_first_seen_when_defined = true;
		_first_seen_when_changed = true;
		_first_seen_when = new_value;
	}
	
	// inlined: moved to .hxx file
	// time_t first_seen_when()
	 
	void Account::remove_first_seen_when() {
		_first_seen_when_exists = false;
		_first_seen_when_defined = false;
		_first_seen_when_changed = true;
		_first_seen_when = (time_t)0;
	}
	
	void Account::undef_first_seen_when() {
		_first_seen_when_exists = true;
		_first_seen_when_defined = false;
		_first_seen_when_changed = true;
		_first_seen_when = (time_t)0;
	}
	
	bool Account::defined_first_seen_when() {
		return _first_seen_when_defined;
	}
	
	bool Account::exists_first_seen_when() {
		return _first_seen_when_exists;
	}
	
	bool Account::changed_first_seen_when() {
		return _first_seen_when_changed;
	}

	void Account::reward_recipient(unsigned long long int new_value) {
		_reward_recipient_exists = true;
		_reward_recipient_defined = true;
		_reward_recipient_changed = true;
		_reward_recipient = new_value;
	}
	
	// inlined: moved to .hxx file
	// unsigned long long int reward_recipient()
	 
	void Account::remove_reward_recipient() {
		_reward_recipient_exists = false;
		_reward_recipient_defined = false;
		_reward_recipient_changed = true;
		_reward_recipient = (unsigned long long int)0;
	}
	
	void Account::undef_reward_recipient() {
		_reward_recipient_exists = true;
		_reward_recipient_defined = false;
		_reward_recipient_changed = true;
		_reward_recipient = (unsigned long long int)0;
	}
	
	bool Account::defined_reward_recipient() {
		return _reward_recipient_defined;
	}
	
	bool Account::exists_reward_recipient() {
		return _reward_recipient_exists;
	}
	
	bool Account::changed_reward_recipient() {
		return _reward_recipient_changed;
	}

	void Account::last_updated_when(time_t new_value) {
		_last_updated_when_exists = true;
		_last_updated_when_defined = true;
		_last_updated_when_changed = true;
		_last_updated_when = new_value;
	}
	
	// inlined: moved to .hxx file
	// time_t last_updated_when()
	 
	void Account::remove_last_updated_when() {
		_last_updated_when_exists = false;
		_last_updated_when_defined = false;
		_last_updated_when_changed = true;
		_last_updated_when = (time_t)0;
	}
	
	void Account::undef_last_updated_when() {
		_last_updated_when_exists = true;
		_last_updated_when_defined = false;
		_last_updated_when_changed = true;
		_last_updated_when = (time_t)0;
	}
	
	bool Account::defined_last_updated_when() {
		return _last_updated_when_defined;
	}
	
	bool Account::exists_last_updated_when() {
		return _last_updated_when_exists;
	}
	
	bool Account::changed_last_updated_when() {
		return _last_updated_when_changed;
	}

	void Account::last_nonce(unsigned long long int new_value) {
		_last_nonce_exists = true;
		_last_nonce_defined = true;
		_last_nonce_changed = true;
		_last_nonce = new_value;
	}
	
	// inlined: moved to .hxx file
	// unsigned long long int last_nonce()
	 
	void Account::remove_last_nonce() {
		_last_nonce_exists = false;
		_last_nonce_defined = false;
		_last_nonce_changed = true;
		_last_nonce = (unsigned long long int)0;
	}
	
	void Account::undef_last_nonce() {
		_last_nonce_exists = true;
		_last_nonce_defined = false;
		_last_nonce_changed = true;
		_last_nonce = (unsigned long long int)0;
	}
	
	bool Account::defined_last_nonce() {
		return _last_nonce_defined;
	}
	
	bool Account::exists_last_nonce() {
		return _last_nonce_exists;
	}
	
	bool Account::changed_last_nonce() {
		return _last_nonce_changed;
	}

	void Account::last_nonce_when(time_t new_value) {
		_last_nonce_when_exists = true;
		_last_nonce_when_defined = true;
		_last_nonce_when_changed = true;
		_last_nonce_when = new_value;
	}
	
	// inlined: moved to .hxx file
	// time_t last_nonce_when()
	 
	void Account::remove_last_nonce_when() {
		_last_nonce_when_exists = false;
		_last_nonce_when_defined = false;
		_last_nonce_when_changed = true;
		_last_nonce_when = (time_t)0;
	}
	
	void Account::undef_last_nonce_when() {
		_last_nonce_when_exists = true;
		_last_nonce_when_defined = false;
		_last_nonce_when_changed = true;
		_last_nonce_when = (time_t)0;
	}
	
	bool Account::defined_last_nonce_when() {
		return _last_nonce_when_defined;
	}
	
	bool Account::exists_last_nonce_when() {
		return _last_nonce_when_exists;
	}
	
	bool Account::changed_last_nonce_when() {
		return _last_nonce_when_changed;
	}

	void Account::account_name(std::string new_value) {
		_account_name_exists = true;
		_account_name_defined = true;
		_account_name_changed = true;
		_account_name = new_value;
	}
	
	// inlined: moved to .hxx file
	// std::string account_name()
	 
	void Account::remove_account_name() {
		_account_name_exists = false;
		_account_name_defined = false;
		_account_name_changed = true;
		_account_name = "";
	}
	
	void Account::undef_account_name() {
		_account_name_exists = true;
		_account_name_defined = false;
		_account_name_changed = true;
		_account_name = "";
	}
	
	bool Account::defined_account_name() {
		return _account_name_defined;
	}
	
	bool Account::exists_account_name() {
		return _account_name_exists;
	}
	
	bool Account::changed_account_name() {
		return _account_name_changed;
	}

	void Account::estimated_capacity(unsigned long long int new_value) {
		_estimated_capacity_exists = true;
		_estimated_capacity_defined = true;
		_estimated_capacity_changed = true;
		_estimated_capacity = new_value;
	}
	
	// inlined: moved to .hxx file
	// unsigned long long int estimated_capacity()
	 
	void Account::remove_estimated_capacity() {
		_estimated_capacity_exists = false;
		_estimated_capacity_defined = false;
		_estimated_capacity_changed = true;
		_estimated_capacity = (unsigned long long int)0;
	}
	
	void Account::undef_estimated_capacity() {
		_estimated_capacity_exists = true;
		_estimated_capacity_defined = false;
		_estimated_capacity_changed = true;
		_estimated_capacity = (unsigned long long int)0;
	}
	
	bool Account::defined_estimated_capacity() {
		return _estimated_capacity_defined;
	}
	
	bool Account::exists_estimated_capacity() {
		return _estimated_capacity_exists;
	}
	
	bool Account::changed_estimated_capacity() {
		return _estimated_capacity_changed;
	}

	void Account::account_RS_string(std::string new_value) {
		_account_RS_string_exists = true;
		_account_RS_string_defined = true;
		_account_RS_string_changed = true;
		_account_RS_string = new_value;
	}
	
	// inlined: moved to .hxx file
	// std::string account_RS_string()
	 
	void Account::remove_account_RS_string() {
		_account_RS_string_exists = false;
		_account_RS_string_defined = false;
		_account_RS_string_changed = true;
		_account_RS_string = "";
	}
	
	void Account::undef_account_RS_string() {
		_account_RS_string_exists = true;
		_account_RS_string_defined = false;
		_account_RS_string_changed = true;
		_account_RS_string = "";
	}
	
	bool Account::defined_account_RS_string() {
		return _account_RS_string_defined;
	}
	
	bool Account::exists_account_RS_string() {
		return _account_RS_string_exists;
	}
	
	bool Account::changed_account_RS_string() {
		return _account_RS_string_changed;
	}

	void Account::has_used_this_pool(bool new_value) {
		_has_used_this_pool_exists = true;
		_has_used_this_pool_defined = true;
		_has_used_this_pool_changed = true;
		_has_used_this_pool = new_value;
	}
	
	// inlined: moved to .hxx file
	// bool has_used_this_pool()
	 
	void Account::remove_has_used_this_pool() {
		_has_used_this_pool_exists = false;
		_has_used_this_pool_defined = false;
		_has_used_this_pool_changed = true;
		_has_used_this_pool = (bool)false;
	}
	
	void Account::undef_has_used_this_pool() {
		_has_used_this_pool_exists = true;
		_has_used_this_pool_defined = false;
		_has_used_this_pool_changed = true;
		_has_used_this_pool = (bool)false;
	}
	
	bool Account::defined_has_used_this_pool() {
		return _has_used_this_pool_defined;
	}
	
	bool Account::exists_has_used_this_pool() {
		return _has_used_this_pool_exists;
	}
	
	bool Account::changed_has_used_this_pool() {
		return _has_used_this_pool_changed;
	}



// navigator methods





// run-time safe!
bool Account::has_field(std::string field) {
	
		if (!field.compare("accountID")) {
			return true;
		}
	
		if (!field.compare("first_seen_when")) {
			return true;
		}
	
		if (!field.compare("reward_recipient")) {
			return true;
		}
	
		if (!field.compare("last_updated_when")) {
			return true;
		}
	
		if (!field.compare("last_nonce")) {
			return true;
		}
	
		if (!field.compare("last_nonce_when")) {
			return true;
		}
	
		if (!field.compare("account_name")) {
			return true;
		}
	
		if (!field.compare("estimated_capacity")) {
			return true;
		}
	
		if (!field.compare("account_RS_string")) {
			return true;
		}
	
		if (!field.compare("has_used_this_pool")) {
			return true;
		}
	

	return false;
}


// run-time safe!
bool Account::exists_by_name(std::string field) {
	
		if (!field.compare("accountID")) {
			return _accountID_exists;
		}
	
		if (!field.compare("first_seen_when")) {
			return _first_seen_when_exists;
		}
	
		if (!field.compare("reward_recipient")) {
			return _reward_recipient_exists;
		}
	
		if (!field.compare("last_updated_when")) {
			return _last_updated_when_exists;
		}
	
		if (!field.compare("last_nonce")) {
			return _last_nonce_exists;
		}
	
		if (!field.compare("last_nonce_when")) {
			return _last_nonce_when_exists;
		}
	
		if (!field.compare("account_name")) {
			return _account_name_exists;
		}
	
		if (!field.compare("estimated_capacity")) {
			return _estimated_capacity_exists;
		}
	
		if (!field.compare("account_RS_string")) {
			return _account_RS_string_exists;
		}
	
		if (!field.compare("has_used_this_pool")) {
			return _has_used_this_pool_exists;
		}
	

	return false;
}


bool Account::defined_by_name(std::string field) {
	
		if (!field.compare("accountID")) {
			return _accountID_defined;
		}
	
		if (!field.compare("first_seen_when")) {
			return _first_seen_when_defined;
		}
	
		if (!field.compare("reward_recipient")) {
			return _reward_recipient_defined;
		}
	
		if (!field.compare("last_updated_when")) {
			return _last_updated_when_defined;
		}
	
		if (!field.compare("last_nonce")) {
			return _last_nonce_defined;
		}
	
		if (!field.compare("last_nonce_when")) {
			return _last_nonce_when_defined;
		}
	
		if (!field.compare("account_name")) {
			return _account_name_defined;
		}
	
		if (!field.compare("estimated_capacity")) {
			return _estimated_capacity_defined;
		}
	
		if (!field.compare("account_RS_string")) {
			return _account_RS_string_defined;
		}
	
		if (!field.compare("has_used_this_pool")) {
			return _has_used_this_pool_defined;
		}
	

	return false;
}


bool Account::is_key_by_name(std::string field) {
	
		if (!field.compare("accountID"))
			return true;
	

	return false;
}	





	bool Account::get_Boolean_by_name(std::string field) {
		
			
			
			
			
			
			
			
			
			
			

			if (!field.compare("has_used_this_pool")) {
				return _has_used_this_pool;
			}
		

		std::cerr << "Unimplemented getBoolean_by_name() call for " << field << std::endl;
		return (bool)false;
	}

	std::string Account::get_String_by_name(std::string field) {
		
			
			
			
			
			
			
			

			if (!field.compare("account_name")) {
				return _account_name;
			}
		
			
			

			if (!field.compare("account_RS_string")) {
				return _account_RS_string;
			}
		
			

		std::cerr << "Unimplemented getString_by_name() call for " << field << std::endl;
		return "";
	}

	double Account::get_Double_by_name(std::string field) {
		
			
			
			
			
			
			
			
			
			
			

		std::cerr << "Unimplemented getDouble_by_name() call for " << field << std::endl;
		return (double)0.0;
	}

	int Account::get_Int_by_name(std::string field) {
		
			
			
			
			
			
			
			
			
			
			

		std::cerr << "Unimplemented getInt_by_name() call for " << field << std::endl;
		return (int)0;
	}

	time_t Account::get_Timestamp_by_name(std::string field) {
		
			
			

			if (!field.compare("first_seen_when")) {
				return _first_seen_when;
			}
		
			
			

			if (!field.compare("last_updated_when")) {
				return _last_updated_when;
			}
		
			
			

			if (!field.compare("last_nonce_when")) {
				return _last_nonce_when;
			}
		
			
			
			
			

		std::cerr << "Unimplemented getTimestamp_by_name() call for " << field << std::endl;
		return (time_t)0;
	}

	unsigned char * Account::get_Blob_by_name(std::string field) {
		
			
			
			
			
			
			
			
			
			
			

		std::cerr << "Unimplemented getBlob_by_name() call for " << field << std::endl;
		return NULL;
	}

	unsigned int Account::get_UInt_by_name(std::string field) {
		
			
			
			
			
			
			
			
			
			
			

		std::cerr << "Unimplemented getUInt_by_name() call for " << field << std::endl;
		return (unsigned int)0;
	}

	unsigned long long int Account::get_UInt64_by_name(std::string field) {
		
			

			if (!field.compare("accountID")) {
				return _accountID;
			}
		
			
			

			if (!field.compare("reward_recipient")) {
				return _reward_recipient;
			}
		
			
			

			if (!field.compare("last_nonce")) {
				return _last_nonce;
			}
		
			
			
			

			if (!field.compare("estimated_capacity")) {
				return _estimated_capacity;
			}
		
			
			

		std::cerr << "Unimplemented getUInt64_by_name() call for " << field << std::endl;
		return (unsigned long long int)0;
	}



void Account::clear() {
	if (results)
		delete results;
		
	_init();
	_init_columns();
}


Account *Account::clone() {
	Account *c = new Account();
	
	
		if ( _accountID_defined )
			c->accountID( _accountID );
	
		if ( _first_seen_when_defined )
			c->first_seen_when( _first_seen_when );
	
		if ( _reward_recipient_defined )
			c->reward_recipient( _reward_recipient );
	
		if ( _last_updated_when_defined )
			c->last_updated_when( _last_updated_when );
	
		if ( _last_nonce_defined )
			c->last_nonce( _last_nonce );
	
		if ( _last_nonce_when_defined )
			c->last_nonce_when( _last_nonce_when );
	
		if ( _account_name_defined )
			c->account_name( _account_name );
	
		if ( _estimated_capacity_defined )
			c->estimated_capacity( _estimated_capacity );
	
		if ( _account_RS_string_defined )
			c->account_RS_string( _account_RS_string );
	
		if ( _has_used_this_pool_defined )
			c->has_used_this_pool( _has_used_this_pool );
	

	return c;
}


Account *Account::skeleton() {
	Account *skel = new Account();
	
	
		
		skel->accountID( _accountID );
	
		
		
		
		
		
		
		
		
		

	return skel;
}


Account *Account::load( unsigned long long int accountID ) {
	IDB::Where *where_clause = NULL;
	
	
		 
		 	where_clause = new IDB::sqlEqUInt64( "accountID", accountID );
		 
	
	
	return load( where_clause );
};


Account *Account::load(IDB::Where *where_clause) {
	std::vector<std::string>		cols;
	IDB::Tables						*tables = new IDB::Tables("Accounts");
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
		Account *loaded_obj = new Account( res );
		delete res;
		return loaded_obj;
	}

	delete res;
	return (Account *)0;
};

/* OLD BUT WORKING VERSION:
Account *Account::load(IO::Object *other_obj) {
	Account *search_obj = new Account(other_obj);
	Account *loaded_obj;

	loaded_obj = search_obj->present();
	delete search_obj;

	return loaded_obj;
};
*/

/* NEW, FASTER VERSION: */
Account *Account::load(IO::Object *other_obj) {
	// all key columns must exist and be defined (i.e. not undef/null)
	
		if ( ! other_obj->defined_by_name( "accountID" ) )
			return NULL;
	
	
	return load( other_obj->get_UInt64_by_name( "accountID" ) );
};


std::vector<Account *> Account::load_all_vector() {
	std::vector<Account *> results;

	Account me;
	me.search();
	
	while( Account *result = me.result() ) {
		results.push_back( result );	
	}

	return results;
};



void Account::refresh() {
	std::vector<std::string>		cols;
	IDB::Tables						*tables = new IDB::Tables("Accounts");
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
	
		
		
		
		
		
		
		
		
		

	res = idbe()->select(&cols, tables, where_clause, IDB_NO_OPTIONS);
	delete tables;
	delete where_clause;

	if (res->next()) {
		this->_copy_from_res(res);
	}

	delete res;
};



// heavy lifting for delete_obj()
void Account::_delete_obj() {
	
	
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
	
		
		
		
		
		
		
		
		
		

	idbe()->deleterow("Accounts", where_clause);
	delete where_clause;
};


Account *Account::present() { return this->present(IDB_NO_OPTIONS, (std::vector<IO::Object *> *) NULL ); }

Account *Account::present(IDB::Options *options, std::vector<IO::Object *> *additional) {
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
		Account *loaded_obj = new Account( res );
		delete res;
		return loaded_obj;
	}

	delete res;
	return (Account *)0;
}


Account *Account::present_or_self() { 
	Account *found = this->present(IDB_NO_OPTIONS, 0);
	
	if (found)
		return found;
	else
		return this;
}


Account *Account::result() {
	if (results) {
		if (results->next()) {
			return new Account( results );
		}
		
		delete results;
		results = NULL;
	}
	
	return (Account *)0;
}


std::vector<Account *> Account::results_vector() {
	std::vector<Account *> output_vector;

	while( Account *vector_entry = result() ) {
		output_vector.push_back( vector_entry );	
	}

	return output_vector;
}

		
// search modifiers

	void Account::needs_updating(bool v) { _SM_needs_updating_p = true; _SM_needs_updating = v; }

	void Account::sum_capacities(bool v) { _SM_sum_capacities_p = true; _SM_sum_capacities = v; }



// order by
void Account::order_by( Account_columns_t col, order_direction_t dir ) {
	_order_by = Account_column_names[col] + " " + order_direction_names[dir];
}


// check database shape matches code
bool Account::check_db_shape() {
	bool shape_OK = true;

	std::vector<std::string> cols;
	cols.push_back("*");

	IDB::Tables *tables = new IDB::Tables( "INFORMATION_SCHEMA.COLUMNS" );

	IDB::Where *where_schema = new IDB::sqlEqCol( "table_schema", "database()" );
	IDB::Where *where_table = new IDB::sqlEqString( "table_name", "Accounts" );
	
	IDB::Where *where = new IDB::sqlAnd( where_schema, where_table );

	IDB::ResultSet *res = idbe()->select(&cols, tables, where, IDB_NO_OPTIONS);

	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "accountID" ) {
				std::cerr << "Accounts column #1 should be 'accountID' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Accounts column #1 should be 'accountID' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "first_seen_when" ) {
				std::cerr << "Accounts column #2 should be 'first_seen_when' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Accounts column #2 should be 'first_seen_when' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "reward_recipient" ) {
				std::cerr << "Accounts column #3 should be 'reward_recipient' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Accounts column #3 should be 'reward_recipient' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "last_updated_when" ) {
				std::cerr << "Accounts column #4 should be 'last_updated_when' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Accounts column #4 should be 'last_updated_when' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "last_nonce" ) {
				std::cerr << "Accounts column #5 should be 'last_nonce' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Accounts column #5 should be 'last_nonce' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "last_nonce_when" ) {
				std::cerr << "Accounts column #6 should be 'last_nonce_when' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Accounts column #6 should be 'last_nonce_when' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "account_name" ) {
				std::cerr << "Accounts column #7 should be 'account_name' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Accounts column #7 should be 'account_name' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "estimated_capacity" ) {
				std::cerr << "Accounts column #8 should be 'estimated_capacity' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Accounts column #8 should be 'estimated_capacity' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "account_RS_string" ) {
				std::cerr << "Accounts column #9 should be 'account_RS_string' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Accounts column #9 should be 'account_RS_string' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "has_used_this_pool" ) {
				std::cerr << "Accounts column #10 should be 'has_used_this_pool' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Accounts column #10 should be 'has_used_this_pool' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	

	return shape_OK;
}


// lock this database record
void Account::lock_record() {
	// SELECT true FROM <table> WHERE <keys> FOR UPDATE
	std::vector<std::string> cols;
	cols.push_back("true");

	IDB::Tables *tables = new IDB::Tables("Accounts");

	IDB::Where *where_clause = NULL;
	
	
		 
		 	where_clause = new IDB::sqlEqUInt64( "accountID", _accountID );
		 
	

	IDB::Options *options = new IDB::Options;
	options->for_update = true;
	
	IDB::ResultSet *res = idbe()->select(&cols, tables, where_clause, options);
	
	delete res;

	delete options;
	delete where_clause;
	delete tables;
}

