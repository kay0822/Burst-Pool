
// object .cxx include file template

#include "Reward.hpp"

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif

#define FULLTEXT_FIELD(field)

#define SEARCHMOD(name, type)
#define SEARCHMOD_IS_SET(name) _SM_ ## name ## _p
#define SEARCHMOD_VALUE(name) _SM_ ## name
#define SEARCHPREP IO::PreppedSearch *Reward::search_prep(IDB::Options *options, std::vector<IO::Object *> *additional)
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

const std::string Reward::_my_table = "Rewards";


// PRIVATE METHODS


// common method to initialize a new object
void Reward::_init() {
	// init results to null
	results = NULL;

	// initialize search modifiers
	
		_SM_before_blockID_p = false;
	
		_SM_below_amount_p = false;
	
		_SM_paid_before_block_id_p = false;
	
		_SM_sum_amount_p = false;
	
}


void Reward::_init_columns() {
	// initialize columns
	
		_blockID_exists = false;
		_blockID_defined = false;
		_blockID_changed = false;
		_blockID = (unsigned long long int)0;
	
		_accountID_exists = false;
		_accountID_defined = false;
		_accountID_changed = false;
		_accountID = (unsigned long long int)0;
	
		_amount_exists = false;
		_amount_defined = false;
		_amount_changed = false;
		_amount = (unsigned long long int)0;
	
		_is_paid_exists = false;
		_is_paid_defined = false;
		_is_paid_changed = false;
		_is_paid = (bool)false;
	
		_tx_id_exists = false;
		_tx_id_defined = false;
		_tx_id_changed = false;
		_tx_id = (unsigned long long int)0;
	
		_is_confirmed_exists = false;
		_is_confirmed_defined = false;
		_is_confirmed_changed = false;
		_is_confirmed = (bool)false;
	
		_paid_at_block_id_exists = false;
		_paid_at_block_id_defined = false;
		_paid_at_block_id_changed = false;
		_paid_at_block_id = (unsigned long long int)0;
	
}


// common method to copy data from an SQL result set into our object
void Reward::_copy_from_res(IDB::ResultSet *res) {
	
		try {
			
			if ( res->isNull( 1 ) ) {
				this->undef_blockID();
			} else {
				this->blockID( res->getUInt64( 1 ) );
			}
			_blockID_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Reward column index 0" << std::endl;
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
			std::cerr << "[IDB] Reward column index 1" << std::endl;
			throw(e);
		}
	
		try {
			
			if ( res->isNull( 3 ) ) {
				this->undef_amount();
			} else {
				this->amount( res->getUInt64( 3 ) );
			}
			_amount_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Reward column index 2" << std::endl;
			throw(e);
		}
	
		try {
			
			if ( res->isNull( 4 ) ) {
				this->undef_is_paid();
			} else {
				this->is_paid( res->getBoolean( 4 ) );
			}
			_is_paid_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Reward column index 3" << std::endl;
			throw(e);
		}
	
		try {
			
			if ( res->isNull( 5 ) ) {
				this->undef_tx_id();
			} else {
				this->tx_id( res->getUInt64( 5 ) );
			}
			_tx_id_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Reward column index 4" << std::endl;
			throw(e);
		}
	
		try {
			
			if ( res->isNull( 6 ) ) {
				this->undef_is_confirmed();
			} else {
				this->is_confirmed( res->getBoolean( 6 ) );
			}
			_is_confirmed_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Reward column index 5" << std::endl;
			throw(e);
		}
	
		try {
			
			if ( res->isNull( 7 ) ) {
				this->undef_paid_at_block_id();
			} else {
				this->paid_at_block_id( res->getUInt64( 7 ) );
			}
			_paid_at_block_id_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Reward column index 6" << std::endl;
			throw(e);
		}
	
}


// method to generate generic search WHERE criteria based on columns with values
IDB::Where *Reward::_search_prep_columns() {
	IDB::Where					*where_clause = IDB_NO_WHERE;
	IDB::Where					*new_clause;

	
		if (_blockID_exists) {
			if (_blockID_defined) {
				
					new_clause = new IDB::sqlEqUInt64( "Rewards.blockID", _blockID );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Rewards.blockID" );
			}

			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		if (_accountID_exists) {
			if (_accountID_defined) {
				
					new_clause = new IDB::sqlEqUInt64( "Rewards.accountID", _accountID );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Rewards.accountID" );
			}

			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		if (_amount_exists) {
			if (_amount_defined) {
				
					new_clause = new IDB::sqlEqUInt64( "Rewards.amount", _amount );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Rewards.amount" );
			}

			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		if (_is_paid_exists) {
			if (_is_paid_defined) {
				
					new_clause = new IDB::sqlEqBoolean( "Rewards.is_paid", _is_paid );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Rewards.is_paid" );
			}

			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		if (_tx_id_exists) {
			if (_tx_id_defined) {
				
					new_clause = new IDB::sqlEqUInt64( "Rewards.tx_id", _tx_id );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Rewards.tx_id" );
			}

			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		if (_is_confirmed_exists) {
			if (_is_confirmed_defined) {
				
					new_clause = new IDB::sqlEqBoolean( "Rewards.is_confirmed", _is_confirmed );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Rewards.is_confirmed" );
			}

			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		if (_paid_at_block_id_exists) {
			if (_paid_at_block_id_defined) {
				
					new_clause = new IDB::sqlEqUInt64( "Rewards.paid_at_block_id", _paid_at_block_id );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Rewards.paid_at_block_id" );
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
IDB::Where *Reward::_search_prep_join(std::map<std::string, std::string> *col_to_table) {
	IDB::Where									*on_clause = IDB_NO_WHERE;
	std::map<std::string, std::string>::iterator	it;

	
		

		it = col_to_table->find("blockID");
		if (it != col_to_table->end()) {
			std::string col_name = it->second;
			col_name += ".blockID";
			IDB::Where *new_clause = new IDB::sqlEqCol( col_name, "Rewards.blockID" );

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
			IDB::Where *new_clause = new IDB::sqlEqCol( col_name, "Rewards.accountID" );

			if (on_clause == IDB_NO_WHERE) {
				on_clause = new_clause;
			} else {
				on_clause = new IDB::sqlAnd( on_clause, new_clause );
			}
		}
	
		
		
		
		
		

	return on_clause;
}


// method to do heavy lifting unique to this object for real search_prep() method
IO::PreppedSearch *Reward::_search_prep(IDB::Options *options, std::vector<IO::Object *> *additional) {
	IO::PreppedSearch							*ps = new IO::PreppedSearch();
	IDB::Tables									*tables = new IDB::Tables("Rewards");
	IDB::Where									*where_clause = IDB_NO_WHERE;
	IDB::Where									*new_clause;
	std::map<std::string, std::string>			col_to_table;

	where_clause = this->_search_prep_columns();

	
		col_to_table["blockID"] = "Rewards";
	
		col_to_table["accountID"] = "Rewards";
	
		col_to_table["amount"] = "Rewards";
	
		col_to_table["is_paid"] = "Rewards";
	
		col_to_table["tx_id"] = "Rewards";
	
		col_to_table["is_confirmed"] = "Rewards";
	
		col_to_table["paid_at_block_id"] = "Rewards";
	
	
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
	ps->cols->push_back("distinct Rewards.*");

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
void Reward::_save() {
	std::vector<IDB::Where *>	updates;
	unsigned int				n_updates = 0;

	
		/* keys dealt with later on */
		
		/* keys dealt with later on */
		
		/* keys dealt with later on */
		

		/* add amount to record if exists */
		#ifdef MINIMAL_SAVE
			if (_amount_changed) {
		#endif
				if (_amount_exists) {
					if (_amount_defined) {
						
							updates.push_back( new IDB::sqlEqUInt64( "amount", _amount ) );
								
					} else {
						updates.push_back( new IDB::sqlEqNull( "amount" ) );
					}
				}
		#ifdef MINIMAL_SAVE
			}
		#endif				
	
		/* keys dealt with later on */
		

		/* add is_paid to record if exists */
		#ifdef MINIMAL_SAVE
			if (_is_paid_changed) {
		#endif
				if (_is_paid_exists) {
					if (_is_paid_defined) {
						
							updates.push_back( new IDB::sqlEqBoolean( "is_paid", _is_paid ) );
								
					} else {
						updates.push_back( new IDB::sqlEqNull( "is_paid" ) );
					}
				}
		#ifdef MINIMAL_SAVE
			}
		#endif				
	
		/* keys dealt with later on */
		

		/* add tx_id to record if exists */
		#ifdef MINIMAL_SAVE
			if (_tx_id_changed) {
		#endif
				if (_tx_id_exists) {
					if (_tx_id_defined) {
						
							updates.push_back( new IDB::sqlEqUInt64( "tx_id", _tx_id ) );
								
					} else {
						updates.push_back( new IDB::sqlEqNull( "tx_id" ) );
					}
				}
		#ifdef MINIMAL_SAVE
			}
		#endif				
	
		/* keys dealt with later on */
		

		/* add is_confirmed to record if exists */
		#ifdef MINIMAL_SAVE
			if (_is_confirmed_changed) {
		#endif
				if (_is_confirmed_exists) {
					if (_is_confirmed_defined) {
						
							updates.push_back( new IDB::sqlEqBoolean( "is_confirmed", _is_confirmed ) );
								
					} else {
						updates.push_back( new IDB::sqlEqNull( "is_confirmed" ) );
					}
				}
		#ifdef MINIMAL_SAVE
			}
		#endif				
	
		/* keys dealt with later on */
		

		/* add paid_at_block_id to record if exists */
		#ifdef MINIMAL_SAVE
			if (_paid_at_block_id_changed) {
		#endif
				if (_paid_at_block_id_exists) {
					if (_paid_at_block_id_defined) {
						
							updates.push_back( new IDB::sqlEqUInt64( "paid_at_block_id", _paid_at_block_id ) );
								
					} else {
						updates.push_back( new IDB::sqlEqNull( "paid_at_block_id" ) );
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
	idbe()->writerow("Rewards", updates);

	/* clean updates */
	for(int i = 0; i < updates.size(); i++) {
		IDB::Where	*where = updates[i];
		delete where;
	}

	/* reset changed-ness */
	
		_blockID_changed = false;
	
		_accountID_changed = false;
	
		_amount_changed = false;
	
		_is_paid_changed = false;
	
		_tx_id_changed = false;
	
		_is_confirmed_changed = false;
	
		_paid_at_block_id_changed = false;
		

	/* autoinc support */
	
};


// special private constructor for internal use that doesn't clean column values
Reward::Reward( IDB::ResultSet *res ): IO::Object() {
	this->_init();
	this->_copy_from_res( res );
};


// PUBLIC METHODS
const std::string Reward::Reward_column_names[] = {
	
		"blockID",
	
		"accountID",
	
		"amount",
	
		"is_paid",
	
		"tx_id",
	
		"is_confirmed",
	
		"paid_at_block_id",
	
};

// our table
std::string Reward::_table() {
	return "Rewards";
}


// generic constructor
Reward::Reward() {
	this->_init_columns();
	this->_init();
};


// constructor that uses columns from another object (must be key field in other object)
Reward::Reward(IO::Object *other_obj): IO::Object() {
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
	
		if ( other_obj->is_key_by_name("amount") )
			if ( other_obj->exists_by_name("amount") )
				if ( other_obj->defined_by_name("amount") )
					this->amount( other_obj->get_UInt64_by_name("amount") );
				else
					this->remove_amount();
			else
				this->remove_amount();
		else
			this->remove_amount();
	
		if ( other_obj->is_key_by_name("is_paid") )
			if ( other_obj->exists_by_name("is_paid") )
				if ( other_obj->defined_by_name("is_paid") )
					this->is_paid( other_obj->get_Boolean_by_name("is_paid") );
				else
					this->remove_is_paid();
			else
				this->remove_is_paid();
		else
			this->remove_is_paid();
	
		if ( other_obj->is_key_by_name("tx_id") )
			if ( other_obj->exists_by_name("tx_id") )
				if ( other_obj->defined_by_name("tx_id") )
					this->tx_id( other_obj->get_UInt64_by_name("tx_id") );
				else
					this->remove_tx_id();
			else
				this->remove_tx_id();
		else
			this->remove_tx_id();
	
		if ( other_obj->is_key_by_name("is_confirmed") )
			if ( other_obj->exists_by_name("is_confirmed") )
				if ( other_obj->defined_by_name("is_confirmed") )
					this->is_confirmed( other_obj->get_Boolean_by_name("is_confirmed") );
				else
					this->remove_is_confirmed();
			else
				this->remove_is_confirmed();
		else
			this->remove_is_confirmed();
	
		if ( other_obj->is_key_by_name("paid_at_block_id") )
			if ( other_obj->exists_by_name("paid_at_block_id") )
				if ( other_obj->defined_by_name("paid_at_block_id") )
					this->paid_at_block_id( other_obj->get_UInt64_by_name("paid_at_block_id") );
				else
					this->remove_paid_at_block_id();
			else
				this->remove_paid_at_block_id();
		else
			this->remove_paid_at_block_id();
	
};


// destructor
Reward::~Reward() {
	if (results)
		delete results;
}


// column accessor methods

	void Reward::blockID(unsigned long long int new_value) {
		_blockID_exists = true;
		_blockID_defined = true;
		_blockID_changed = true;
		_blockID = new_value;
	}
	
	// inlined: moved to .hxx file
	// unsigned long long int blockID()
	 
	void Reward::remove_blockID() {
		_blockID_exists = false;
		_blockID_defined = false;
		_blockID_changed = true;
		_blockID = (unsigned long long int)0;
	}
	
	void Reward::undef_blockID() {
		_blockID_exists = true;
		_blockID_defined = false;
		_blockID_changed = true;
		_blockID = (unsigned long long int)0;
	}
	
	bool Reward::defined_blockID() {
		return _blockID_defined;
	}
	
	bool Reward::exists_blockID() {
		return _blockID_exists;
	}
	
	bool Reward::changed_blockID() {
		return _blockID_changed;
	}

	void Reward::accountID(unsigned long long int new_value) {
		_accountID_exists = true;
		_accountID_defined = true;
		_accountID_changed = true;
		_accountID = new_value;
	}
	
	// inlined: moved to .hxx file
	// unsigned long long int accountID()
	 
	void Reward::remove_accountID() {
		_accountID_exists = false;
		_accountID_defined = false;
		_accountID_changed = true;
		_accountID = (unsigned long long int)0;
	}
	
	void Reward::undef_accountID() {
		_accountID_exists = true;
		_accountID_defined = false;
		_accountID_changed = true;
		_accountID = (unsigned long long int)0;
	}
	
	bool Reward::defined_accountID() {
		return _accountID_defined;
	}
	
	bool Reward::exists_accountID() {
		return _accountID_exists;
	}
	
	bool Reward::changed_accountID() {
		return _accountID_changed;
	}

	void Reward::amount(unsigned long long int new_value) {
		_amount_exists = true;
		_amount_defined = true;
		_amount_changed = true;
		_amount = new_value;
	}
	
	// inlined: moved to .hxx file
	// unsigned long long int amount()
	 
	void Reward::remove_amount() {
		_amount_exists = false;
		_amount_defined = false;
		_amount_changed = true;
		_amount = (unsigned long long int)0;
	}
	
	void Reward::undef_amount() {
		_amount_exists = true;
		_amount_defined = false;
		_amount_changed = true;
		_amount = (unsigned long long int)0;
	}
	
	bool Reward::defined_amount() {
		return _amount_defined;
	}
	
	bool Reward::exists_amount() {
		return _amount_exists;
	}
	
	bool Reward::changed_amount() {
		return _amount_changed;
	}

	void Reward::is_paid(bool new_value) {
		_is_paid_exists = true;
		_is_paid_defined = true;
		_is_paid_changed = true;
		_is_paid = new_value;
	}
	
	// inlined: moved to .hxx file
	// bool is_paid()
	 
	void Reward::remove_is_paid() {
		_is_paid_exists = false;
		_is_paid_defined = false;
		_is_paid_changed = true;
		_is_paid = (bool)false;
	}
	
	void Reward::undef_is_paid() {
		_is_paid_exists = true;
		_is_paid_defined = false;
		_is_paid_changed = true;
		_is_paid = (bool)false;
	}
	
	bool Reward::defined_is_paid() {
		return _is_paid_defined;
	}
	
	bool Reward::exists_is_paid() {
		return _is_paid_exists;
	}
	
	bool Reward::changed_is_paid() {
		return _is_paid_changed;
	}

	void Reward::tx_id(unsigned long long int new_value) {
		_tx_id_exists = true;
		_tx_id_defined = true;
		_tx_id_changed = true;
		_tx_id = new_value;
	}
	
	// inlined: moved to .hxx file
	// unsigned long long int tx_id()
	 
	void Reward::remove_tx_id() {
		_tx_id_exists = false;
		_tx_id_defined = false;
		_tx_id_changed = true;
		_tx_id = (unsigned long long int)0;
	}
	
	void Reward::undef_tx_id() {
		_tx_id_exists = true;
		_tx_id_defined = false;
		_tx_id_changed = true;
		_tx_id = (unsigned long long int)0;
	}
	
	bool Reward::defined_tx_id() {
		return _tx_id_defined;
	}
	
	bool Reward::exists_tx_id() {
		return _tx_id_exists;
	}
	
	bool Reward::changed_tx_id() {
		return _tx_id_changed;
	}

	void Reward::is_confirmed(bool new_value) {
		_is_confirmed_exists = true;
		_is_confirmed_defined = true;
		_is_confirmed_changed = true;
		_is_confirmed = new_value;
	}
	
	// inlined: moved to .hxx file
	// bool is_confirmed()
	 
	void Reward::remove_is_confirmed() {
		_is_confirmed_exists = false;
		_is_confirmed_defined = false;
		_is_confirmed_changed = true;
		_is_confirmed = (bool)false;
	}
	
	void Reward::undef_is_confirmed() {
		_is_confirmed_exists = true;
		_is_confirmed_defined = false;
		_is_confirmed_changed = true;
		_is_confirmed = (bool)false;
	}
	
	bool Reward::defined_is_confirmed() {
		return _is_confirmed_defined;
	}
	
	bool Reward::exists_is_confirmed() {
		return _is_confirmed_exists;
	}
	
	bool Reward::changed_is_confirmed() {
		return _is_confirmed_changed;
	}

	void Reward::paid_at_block_id(unsigned long long int new_value) {
		_paid_at_block_id_exists = true;
		_paid_at_block_id_defined = true;
		_paid_at_block_id_changed = true;
		_paid_at_block_id = new_value;
	}
	
	// inlined: moved to .hxx file
	// unsigned long long int paid_at_block_id()
	 
	void Reward::remove_paid_at_block_id() {
		_paid_at_block_id_exists = false;
		_paid_at_block_id_defined = false;
		_paid_at_block_id_changed = true;
		_paid_at_block_id = (unsigned long long int)0;
	}
	
	void Reward::undef_paid_at_block_id() {
		_paid_at_block_id_exists = true;
		_paid_at_block_id_defined = false;
		_paid_at_block_id_changed = true;
		_paid_at_block_id = (unsigned long long int)0;
	}
	
	bool Reward::defined_paid_at_block_id() {
		return _paid_at_block_id_defined;
	}
	
	bool Reward::exists_paid_at_block_id() {
		return _paid_at_block_id_exists;
	}
	
	bool Reward::changed_paid_at_block_id() {
		return _paid_at_block_id_changed;
	}



// navigator methods

	Block *Reward::block() {
		
		
			return Block::load( new IDB::sqlEqUInt64( "blockID", _blockID ) );
		
	}

	Account *Reward::account() {
		
		
			return Account::load( new IDB::sqlEqUInt64( "accountID", _accountID ) );
		
	}





// run-time safe!
bool Reward::has_field(std::string field) {
	
		if (!field.compare("blockID")) {
			return true;
		}
	
		if (!field.compare("accountID")) {
			return true;
		}
	
		if (!field.compare("amount")) {
			return true;
		}
	
		if (!field.compare("is_paid")) {
			return true;
		}
	
		if (!field.compare("tx_id")) {
			return true;
		}
	
		if (!field.compare("is_confirmed")) {
			return true;
		}
	
		if (!field.compare("paid_at_block_id")) {
			return true;
		}
	

	return false;
}


// run-time safe!
bool Reward::exists_by_name(std::string field) {
	
		if (!field.compare("blockID")) {
			return _blockID_exists;
		}
	
		if (!field.compare("accountID")) {
			return _accountID_exists;
		}
	
		if (!field.compare("amount")) {
			return _amount_exists;
		}
	
		if (!field.compare("is_paid")) {
			return _is_paid_exists;
		}
	
		if (!field.compare("tx_id")) {
			return _tx_id_exists;
		}
	
		if (!field.compare("is_confirmed")) {
			return _is_confirmed_exists;
		}
	
		if (!field.compare("paid_at_block_id")) {
			return _paid_at_block_id_exists;
		}
	

	return false;
}


bool Reward::defined_by_name(std::string field) {
	
		if (!field.compare("blockID")) {
			return _blockID_defined;
		}
	
		if (!field.compare("accountID")) {
			return _accountID_defined;
		}
	
		if (!field.compare("amount")) {
			return _amount_defined;
		}
	
		if (!field.compare("is_paid")) {
			return _is_paid_defined;
		}
	
		if (!field.compare("tx_id")) {
			return _tx_id_defined;
		}
	
		if (!field.compare("is_confirmed")) {
			return _is_confirmed_defined;
		}
	
		if (!field.compare("paid_at_block_id")) {
			return _paid_at_block_id_defined;
		}
	

	return false;
}


bool Reward::is_key_by_name(std::string field) {
	
		if (!field.compare("blockID"))
			return true;
	
		if (!field.compare("accountID"))
			return true;
	

	return false;
}	





	bool Reward::get_Boolean_by_name(std::string field) {
		
			
			
			
			

			if (!field.compare("is_paid")) {
				return _is_paid;
			}
		
			
			

			if (!field.compare("is_confirmed")) {
				return _is_confirmed;
			}
		
			

		std::cerr << "Unimplemented getBoolean_by_name() call for " << field << std::endl;
		return (bool)false;
	}

	std::string Reward::get_String_by_name(std::string field) {
		
			
			
			
			
			
			
			

		std::cerr << "Unimplemented getString_by_name() call for " << field << std::endl;
		return "";
	}

	double Reward::get_Double_by_name(std::string field) {
		
			
			
			
			
			
			
			

		std::cerr << "Unimplemented getDouble_by_name() call for " << field << std::endl;
		return (double)0.0;
	}

	int Reward::get_Int_by_name(std::string field) {
		
			
			
			
			
			
			
			

		std::cerr << "Unimplemented getInt_by_name() call for " << field << std::endl;
		return (int)0;
	}

	time_t Reward::get_Timestamp_by_name(std::string field) {
		
			
			
			
			
			
			
			

		std::cerr << "Unimplemented getTimestamp_by_name() call for " << field << std::endl;
		return (time_t)0;
	}

	unsigned char * Reward::get_Blob_by_name(std::string field) {
		
			
			
			
			
			
			
			

		std::cerr << "Unimplemented getBlob_by_name() call for " << field << std::endl;
		return NULL;
	}

	unsigned int Reward::get_UInt_by_name(std::string field) {
		
			
			
			
			
			
			
			

		std::cerr << "Unimplemented getUInt_by_name() call for " << field << std::endl;
		return (unsigned int)0;
	}

	unsigned long long int Reward::get_UInt64_by_name(std::string field) {
		
			

			if (!field.compare("blockID")) {
				return _blockID;
			}
		
			

			if (!field.compare("accountID")) {
				return _accountID;
			}
		
			

			if (!field.compare("amount")) {
				return _amount;
			}
		
			
			

			if (!field.compare("tx_id")) {
				return _tx_id;
			}
		
			
			

			if (!field.compare("paid_at_block_id")) {
				return _paid_at_block_id;
			}
		

		std::cerr << "Unimplemented getUInt64_by_name() call for " << field << std::endl;
		return (unsigned long long int)0;
	}



void Reward::clear() {
	if (results)
		delete results;
		
	_init();
	_init_columns();
}


Reward *Reward::clone() {
	Reward *c = new Reward();
	
	
		if ( _blockID_defined )
			c->blockID( _blockID );
	
		if ( _accountID_defined )
			c->accountID( _accountID );
	
		if ( _amount_defined )
			c->amount( _amount );
	
		if ( _is_paid_defined )
			c->is_paid( _is_paid );
	
		if ( _tx_id_defined )
			c->tx_id( _tx_id );
	
		if ( _is_confirmed_defined )
			c->is_confirmed( _is_confirmed );
	
		if ( _paid_at_block_id_defined )
			c->paid_at_block_id( _paid_at_block_id );
	

	return c;
}


Reward *Reward::skeleton() {
	Reward *skel = new Reward();
	
	
		
		skel->blockID( _blockID );
	
		
		skel->accountID( _accountID );
	
		
		
		
		
		

	return skel;
}


Reward *Reward::load( unsigned long long int blockID, unsigned long long int accountID ) {
	IDB::Where *where_clause = NULL;
	
	
		 
		 	where_clause = new IDB::sqlEqUInt64( "blockID", blockID );
		 
	
		 
		 	where_clause = new IDB::sqlAnd( where_clause, new IDB::sqlEqUInt64( "accountID", accountID ) );
		 
	
	
	return load( where_clause );
};


Reward *Reward::load(IDB::Where *where_clause) {
	std::vector<std::string>		cols;
	IDB::Tables						*tables = new IDB::Tables("Rewards");
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
		Reward *loaded_obj = new Reward( res );
		delete res;
		return loaded_obj;
	}

	delete res;
	return (Reward *)0;
};

/* OLD BUT WORKING VERSION:
Reward *Reward::load(IO::Object *other_obj) {
	Reward *search_obj = new Reward(other_obj);
	Reward *loaded_obj;

	loaded_obj = search_obj->present();
	delete search_obj;

	return loaded_obj;
};
*/

/* NEW, FASTER VERSION: */
Reward *Reward::load(IO::Object *other_obj) {
	// all key columns must exist and be defined (i.e. not undef/null)
	
		if ( ! other_obj->defined_by_name( "blockID" ) )
			return NULL;
	
		if ( ! other_obj->defined_by_name( "accountID" ) )
			return NULL;
	
	
	return load( other_obj->get_UInt64_by_name( "blockID" ), other_obj->get_UInt64_by_name( "accountID" ) );
};


std::vector<Reward *> Reward::load_all_vector() {
	std::vector<Reward *> results;

	Reward me;
	me.search();
	
	while( Reward *result = me.result() ) {
		results.push_back( result );	
	}

	return results;
};



void Reward::refresh() {
	std::vector<std::string>		cols;
	IDB::Tables						*tables = new IDB::Tables("Rewards");
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
void Reward::_delete_obj() {
	
	
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
	
		
		
		
		
		

	idbe()->deleterow("Rewards", where_clause);
	delete where_clause;
};


Reward *Reward::present() { return this->present(IDB_NO_OPTIONS, (std::vector<IO::Object *> *) NULL ); }

Reward *Reward::present(IDB::Options *options, std::vector<IO::Object *> *additional) {
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
		Reward *loaded_obj = new Reward( res );
		delete res;
		return loaded_obj;
	}

	delete res;
	return (Reward *)0;
}


Reward *Reward::present_or_self() { 
	Reward *found = this->present(IDB_NO_OPTIONS, 0);
	
	if (found)
		return found;
	else
		return this;
}


Reward *Reward::result() {
	if (results) {
		if (results->next()) {
			return new Reward( results );
		}
		
		delete results;
		results = NULL;
	}
	
	return (Reward *)0;
}


std::vector<Reward *> Reward::results_vector() {
	std::vector<Reward *> output_vector;

	while( Reward *vector_entry = result() ) {
		output_vector.push_back( vector_entry );	
	}

	return output_vector;
}

		
// search modifiers

	void Reward::before_blockID(uint64_t v) { _SM_before_blockID_p = true; _SM_before_blockID = v; }

	void Reward::below_amount(uint64_t v) { _SM_below_amount_p = true; _SM_below_amount = v; }

	void Reward::paid_before_block_id(uint64_t v) { _SM_paid_before_block_id_p = true; _SM_paid_before_block_id = v; }

	void Reward::sum_amount(bool v) { _SM_sum_amount_p = true; _SM_sum_amount = v; }



// order by
void Reward::order_by( Reward_columns_t col, order_direction_t dir ) {
	_order_by = Reward_column_names[col] + " " + order_direction_names[dir];
}


// check database shape matches code
bool Reward::check_db_shape() {
	bool shape_OK = true;

	std::vector<std::string> cols;
	cols.push_back("*");

	IDB::Tables *tables = new IDB::Tables( "INFORMATION_SCHEMA.COLUMNS" );

	IDB::Where *where_schema = new IDB::sqlEqCol( "table_schema", "database()" );
	IDB::Where *where_table = new IDB::sqlEqString( "table_name", "Rewards" );
	
	IDB::Where *where = new IDB::sqlAnd( where_schema, where_table );

	IDB::ResultSet *res = idbe()->select(&cols, tables, where, IDB_NO_OPTIONS);

	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "blockID" ) {
				std::cerr << "Rewards column #1 should be 'blockID' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Rewards column #1 should be 'blockID' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "accountID" ) {
				std::cerr << "Rewards column #2 should be 'accountID' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Rewards column #2 should be 'accountID' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "amount" ) {
				std::cerr << "Rewards column #3 should be 'amount' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Rewards column #3 should be 'amount' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "is_paid" ) {
				std::cerr << "Rewards column #4 should be 'is_paid' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Rewards column #4 should be 'is_paid' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "tx_id" ) {
				std::cerr << "Rewards column #5 should be 'tx_id' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Rewards column #5 should be 'tx_id' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "is_confirmed" ) {
				std::cerr << "Rewards column #6 should be 'is_confirmed' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Rewards column #6 should be 'is_confirmed' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "paid_at_block_id" ) {
				std::cerr << "Rewards column #7 should be 'paid_at_block_id' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Rewards column #7 should be 'paid_at_block_id' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	

	return shape_OK;
}


// lock this database record
void Reward::lock_record() {
	// SELECT true FROM <table> WHERE <keys> FOR UPDATE
	std::vector<std::string> cols;
	cols.push_back("true");

	IDB::Tables *tables = new IDB::Tables("Rewards");

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

