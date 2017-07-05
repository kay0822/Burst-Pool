
// object .cxx include file template

#include "Block.hpp"

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif

#define FULLTEXT_FIELD(field)

#define SEARCHMOD(name, type)
#define SEARCHMOD_IS_SET(name) _SM_ ## name ## _p
#define SEARCHMOD_VALUE(name) _SM_ ## name
#define SEARCHPREP IO::PreppedSearch *Block::search_prep(IDB::Options *options, std::vector<IO::Object *> *additional)
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

const std::string Block::_my_table = "Blocks";


// PRIVATE METHODS


// common method to initialize a new object
void Block::_init() {
	// init results to null
	results = NULL;

	// initialize search modifiers
	
		_SM_after_blockID_p = false;
	
		_SM_before_blockID_p = false;
	
		_SM_has_reward_value_p = false;
	
}


void Block::_init_columns() {
	// initialize columns
	
		_blockID_exists = false;
		_blockID_defined = false;
		_blockID_changed = false;
		_blockID = (unsigned long long int)0;
	
		_first_seen_when_exists = false;
		_first_seen_when_defined = false;
		_first_seen_when_changed = false;
		_first_seen_when = (time_t)0;
	
		_best_nonce_account_id_exists = false;
		_best_nonce_account_id_defined = false;
		_best_nonce_account_id_changed = false;
		_best_nonce_account_id = (unsigned long long int)0;
	
		_generator_account_id_exists = false;
		_generator_account_id_defined = false;
		_generator_account_id_changed = false;
		_generator_account_id = (unsigned long long int)0;
	
		_block_reward_exists = false;
		_block_reward_defined = false;
		_block_reward_changed = false;
		_block_reward = (unsigned long long int)0;
	
		_is_our_block_exists = false;
		_is_our_block_defined = false;
		_is_our_block_changed = false;
		_is_our_block = (bool)false;
	
		_has_been_shared_exists = false;
		_has_been_shared_defined = false;
		_has_been_shared_changed = false;
		_has_been_shared = (bool)false;
	
		_base_target_exists = false;
		_base_target_defined = false;
		_base_target_changed = false;
		_base_target = (unsigned long long int)0;
	
		_forged_when_exists = false;
		_forged_when_defined = false;
		_forged_when_changed = false;
		_forged_when = (time_t)0;
	
		_scoop_exists = false;
		_scoop_defined = false;
		_scoop_changed = false;
		_scoop = (unsigned long long int)0;
	
		_nonce_exists = false;
		_nonce_defined = false;
		_nonce_changed = false;
		_nonce = (unsigned long long int)0;
	
		_gen_sig_str_exists = false;
		_gen_sig_str_defined = false;
		_gen_sig_str_changed = false;
		_gen_sig_str = "";
	
		_deadline_exists = false;
		_deadline_defined = false;
		_deadline_changed = false;
		_deadline = (unsigned long long int)0;
	
		_our_best_deadline_exists = false;
		_our_best_deadline_defined = false;
		_our_best_deadline_changed = false;
		_our_best_deadline = (unsigned long long int)0;
	
		_num_potential_miners_exists = false;
		_num_potential_miners_defined = false;
		_num_potential_miners_changed = false;
		_num_potential_miners = (unsigned long long int)0;
	
		_json_exists = false;
		_json_defined = false;
		_json_changed = false;
		_json = "";
	
}


// common method to copy data from an SQL result set into our object
void Block::_copy_from_res(IDB::ResultSet *res) {
	
		try {
			
			if ( res->isNull( 1 ) ) {
				this->undef_blockID();
			} else {
				this->blockID( res->getUInt64( 1 ) );
			}
			_blockID_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Block column index 0" << std::endl;
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
			std::cerr << "[IDB] Block column index 1" << std::endl;
			throw(e);
		}
	
		try {
			
			if ( res->isNull( 3 ) ) {
				this->undef_best_nonce_account_id();
			} else {
				this->best_nonce_account_id( res->getUInt64( 3 ) );
			}
			_best_nonce_account_id_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Block column index 2" << std::endl;
			throw(e);
		}
	
		try {
			
			if ( res->isNull( 4 ) ) {
				this->undef_generator_account_id();
			} else {
				this->generator_account_id( res->getUInt64( 4 ) );
			}
			_generator_account_id_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Block column index 3" << std::endl;
			throw(e);
		}
	
		try {
			
			if ( res->isNull( 5 ) ) {
				this->undef_block_reward();
			} else {
				this->block_reward( res->getUInt64( 5 ) );
			}
			_block_reward_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Block column index 4" << std::endl;
			throw(e);
		}
	
		try {
			
			if ( res->isNull( 6 ) ) {
				this->undef_is_our_block();
			} else {
				this->is_our_block( res->getBoolean( 6 ) );
			}
			_is_our_block_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Block column index 5" << std::endl;
			throw(e);
		}
	
		try {
			
			if ( res->isNull( 7 ) ) {
				this->undef_has_been_shared();
			} else {
				this->has_been_shared( res->getBoolean( 7 ) );
			}
			_has_been_shared_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Block column index 6" << std::endl;
			throw(e);
		}
	
		try {
			
			if ( res->isNull( 8 ) ) {
				this->undef_base_target();
			} else {
				this->base_target( res->getUInt64( 8 ) );
			}
			_base_target_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Block column index 7" << std::endl;
			throw(e);
		}
	
		try {
			
			if ( res->isNull( 9 ) ) {
				this->undef_forged_when();
			} else {
				this->forged_when( res->getTimestamp( 9 ) );
			}
			_forged_when_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Block column index 8" << std::endl;
			throw(e);
		}
	
		try {
			
			if ( res->isNull( 10 ) ) {
				this->undef_scoop();
			} else {
				this->scoop( res->getUInt64( 10 ) );
			}
			_scoop_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Block column index 9" << std::endl;
			throw(e);
		}
	
		try {
			
			if ( res->isNull( 11 ) ) {
				this->undef_nonce();
			} else {
				this->nonce( res->getUInt64( 11 ) );
			}
			_nonce_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Block column index 10" << std::endl;
			throw(e);
		}
	
		try {
			
			if ( res->isNull( 12 ) ) {
				this->undef_gen_sig_str();
			} else {
				this->gen_sig_str( res->getString( 12 ) );
			}
			_gen_sig_str_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Block column index 11" << std::endl;
			throw(e);
		}
	
		try {
			
			if ( res->isNull( 13 ) ) {
				this->undef_deadline();
			} else {
				this->deadline( res->getUInt64( 13 ) );
			}
			_deadline_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Block column index 12" << std::endl;
			throw(e);
		}
	
		try {
			
			if ( res->isNull( 14 ) ) {
				this->undef_our_best_deadline();
			} else {
				this->our_best_deadline( res->getUInt64( 14 ) );
			}
			_our_best_deadline_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Block column index 13" << std::endl;
			throw(e);
		}
	
		try {
			
			if ( res->isNull( 15 ) ) {
				this->undef_num_potential_miners();
			} else {
				this->num_potential_miners( res->getUInt64( 15 ) );
			}
			_num_potential_miners_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Block column index 14" << std::endl;
			throw(e);
		}
	
		try {
			
			if ( res->isNull( 16 ) ) {
				this->undef_json();
			} else {
				this->json( res->getString( 16 ) );
			}
			_json_changed = false;
		} catch (sql::SQLException &e) {
			std::cerr << "[IDB] " << e.getErrorCode() << ": " << e.what() << std::endl;
			std::cerr << "[IDB] Block column index 15" << std::endl;
			throw(e);
		}
	
}


// method to generate generic search WHERE criteria based on columns with values
IDB::Where *Block::_search_prep_columns() {
	IDB::Where					*where_clause = IDB_NO_WHERE;
	IDB::Where					*new_clause;

	
		if (_blockID_exists) {
			if (_blockID_defined) {
				
					new_clause = new IDB::sqlEqUInt64( "Blocks.blockID", _blockID );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Blocks.blockID" );
			}

			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		if (_first_seen_when_exists) {
			if (_first_seen_when_defined) {
				
					new_clause = new IDB::sqlEqString( "Blocks.first_seen_when", IDB::Engine::from_unixtime(_first_seen_when) );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Blocks.first_seen_when" );
			}

			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		if (_best_nonce_account_id_exists) {
			if (_best_nonce_account_id_defined) {
				
					new_clause = new IDB::sqlEqUInt64( "Blocks.best_nonce_account_id", _best_nonce_account_id );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Blocks.best_nonce_account_id" );
			}

			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		if (_generator_account_id_exists) {
			if (_generator_account_id_defined) {
				
					new_clause = new IDB::sqlEqUInt64( "Blocks.generator_account_id", _generator_account_id );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Blocks.generator_account_id" );
			}

			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		if (_block_reward_exists) {
			if (_block_reward_defined) {
				
					new_clause = new IDB::sqlEqUInt64( "Blocks.block_reward", _block_reward );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Blocks.block_reward" );
			}

			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		if (_is_our_block_exists) {
			if (_is_our_block_defined) {
				
					new_clause = new IDB::sqlEqBoolean( "Blocks.is_our_block", _is_our_block );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Blocks.is_our_block" );
			}

			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		if (_has_been_shared_exists) {
			if (_has_been_shared_defined) {
				
					new_clause = new IDB::sqlEqBoolean( "Blocks.has_been_shared", _has_been_shared );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Blocks.has_been_shared" );
			}

			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		if (_base_target_exists) {
			if (_base_target_defined) {
				
					new_clause = new IDB::sqlEqUInt64( "Blocks.base_target", _base_target );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Blocks.base_target" );
			}

			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		if (_forged_when_exists) {
			if (_forged_when_defined) {
				
					new_clause = new IDB::sqlEqString( "Blocks.forged_when", IDB::Engine::from_unixtime(_forged_when) );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Blocks.forged_when" );
			}

			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		if (_scoop_exists) {
			if (_scoop_defined) {
				
					new_clause = new IDB::sqlEqUInt64( "Blocks.scoop", _scoop );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Blocks.scoop" );
			}

			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		if (_nonce_exists) {
			if (_nonce_defined) {
				
					new_clause = new IDB::sqlEqUInt64( "Blocks.nonce", _nonce );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Blocks.nonce" );
			}

			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		if (_gen_sig_str_exists) {
			if (_gen_sig_str_defined) {
				
					new_clause = new IDB::sqlEqString( "Blocks.gen_sig_str", _gen_sig_str );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Blocks.gen_sig_str" );
			}

			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		if (_deadline_exists) {
			if (_deadline_defined) {
				
					new_clause = new IDB::sqlEqUInt64( "Blocks.deadline", _deadline );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Blocks.deadline" );
			}

			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		if (_our_best_deadline_exists) {
			if (_our_best_deadline_defined) {
				
					new_clause = new IDB::sqlEqUInt64( "Blocks.our_best_deadline", _our_best_deadline );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Blocks.our_best_deadline" );
			}

			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		if (_num_potential_miners_exists) {
			if (_num_potential_miners_defined) {
				
					new_clause = new IDB::sqlEqUInt64( "Blocks.num_potential_miners", _num_potential_miners );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Blocks.num_potential_miners" );
			}

			if (where_clause == IDB_NO_WHERE) {
				where_clause = new_clause;
			} else {
				where_clause = new IDB::sqlAnd( where_clause, new_clause );
			}
		}
	
		if (_json_exists) {
			if (_json_defined) {
				
					new_clause = new IDB::sqlEqString( "Blocks.json", _json );
						
			} else {
				new_clause = new IDB::sqlIsNull( "Blocks.json" );
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
IDB::Where *Block::_search_prep_join(std::map<std::string, std::string> *col_to_table) {
	IDB::Where									*on_clause = IDB_NO_WHERE;
	std::map<std::string, std::string>::iterator	it;

	
		

		it = col_to_table->find("blockID");
		if (it != col_to_table->end()) {
			std::string col_name = it->second;
			col_name += ".blockID";
			IDB::Where *new_clause = new IDB::sqlEqCol( col_name, "Blocks.blockID" );

			if (on_clause == IDB_NO_WHERE) {
				on_clause = new_clause;
			} else {
				on_clause = new IDB::sqlAnd( on_clause, new_clause );
			}
		}
	
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		

	return on_clause;
}


// method to do heavy lifting unique to this object for real search_prep() method
IO::PreppedSearch *Block::_search_prep(IDB::Options *options, std::vector<IO::Object *> *additional) {
	IO::PreppedSearch							*ps = new IO::PreppedSearch();
	IDB::Tables									*tables = new IDB::Tables("Blocks");
	IDB::Where									*where_clause = IDB_NO_WHERE;
	IDB::Where									*new_clause;
	std::map<std::string, std::string>			col_to_table;

	where_clause = this->_search_prep_columns();

	
		col_to_table["blockID"] = "Blocks";
	
		col_to_table["first_seen_when"] = "Blocks";
	
		col_to_table["best_nonce_account_id"] = "Blocks";
	
		col_to_table["generator_account_id"] = "Blocks";
	
		col_to_table["block_reward"] = "Blocks";
	
		col_to_table["is_our_block"] = "Blocks";
	
		col_to_table["has_been_shared"] = "Blocks";
	
		col_to_table["base_target"] = "Blocks";
	
		col_to_table["forged_when"] = "Blocks";
	
		col_to_table["scoop"] = "Blocks";
	
		col_to_table["nonce"] = "Blocks";
	
		col_to_table["gen_sig_str"] = "Blocks";
	
		col_to_table["deadline"] = "Blocks";
	
		col_to_table["our_best_deadline"] = "Blocks";
	
		col_to_table["num_potential_miners"] = "Blocks";
	
		col_to_table["json"] = "Blocks";
	
	
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
	ps->cols->push_back("distinct Blocks.*");

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
void Block::_save() {
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
		

		/* add best_nonce_account_id to record if exists */
		#ifdef MINIMAL_SAVE
			if (_best_nonce_account_id_changed) {
		#endif
				if (_best_nonce_account_id_exists) {
					if (_best_nonce_account_id_defined) {
						
							updates.push_back( new IDB::sqlEqUInt64( "best_nonce_account_id", _best_nonce_account_id ) );
								
					} else {
						updates.push_back( new IDB::sqlEqNull( "best_nonce_account_id" ) );
					}
				}
		#ifdef MINIMAL_SAVE
			}
		#endif				
	
		/* keys dealt with later on */
		

		/* add generator_account_id to record if exists */
		#ifdef MINIMAL_SAVE
			if (_generator_account_id_changed) {
		#endif
				if (_generator_account_id_exists) {
					if (_generator_account_id_defined) {
						
							updates.push_back( new IDB::sqlEqUInt64( "generator_account_id", _generator_account_id ) );
								
					} else {
						updates.push_back( new IDB::sqlEqNull( "generator_account_id" ) );
					}
				}
		#ifdef MINIMAL_SAVE
			}
		#endif				
	
		/* keys dealt with later on */
		

		/* add block_reward to record if exists */
		#ifdef MINIMAL_SAVE
			if (_block_reward_changed) {
		#endif
				if (_block_reward_exists) {
					if (_block_reward_defined) {
						
							updates.push_back( new IDB::sqlEqUInt64( "block_reward", _block_reward ) );
								
					} else {
						updates.push_back( new IDB::sqlEqNull( "block_reward" ) );
					}
				}
		#ifdef MINIMAL_SAVE
			}
		#endif				
	
		/* keys dealt with later on */
		

		/* add is_our_block to record if exists */
		#ifdef MINIMAL_SAVE
			if (_is_our_block_changed) {
		#endif
				if (_is_our_block_exists) {
					if (_is_our_block_defined) {
						
							updates.push_back( new IDB::sqlEqBoolean( "is_our_block", _is_our_block ) );
								
					} else {
						updates.push_back( new IDB::sqlEqNull( "is_our_block" ) );
					}
				}
		#ifdef MINIMAL_SAVE
			}
		#endif				
	
		/* keys dealt with later on */
		

		/* add has_been_shared to record if exists */
		#ifdef MINIMAL_SAVE
			if (_has_been_shared_changed) {
		#endif
				if (_has_been_shared_exists) {
					if (_has_been_shared_defined) {
						
							updates.push_back( new IDB::sqlEqBoolean( "has_been_shared", _has_been_shared ) );
								
					} else {
						updates.push_back( new IDB::sqlEqNull( "has_been_shared" ) );
					}
				}
		#ifdef MINIMAL_SAVE
			}
		#endif				
	
		/* keys dealt with later on */
		

		/* add base_target to record if exists */
		#ifdef MINIMAL_SAVE
			if (_base_target_changed) {
		#endif
				if (_base_target_exists) {
					if (_base_target_defined) {
						
							updates.push_back( new IDB::sqlEqUInt64( "base_target", _base_target ) );
								
					} else {
						updates.push_back( new IDB::sqlEqNull( "base_target" ) );
					}
				}
		#ifdef MINIMAL_SAVE
			}
		#endif				
	
		/* keys dealt with later on */
		

		/* add forged_when to record if exists */
		#ifdef MINIMAL_SAVE
			if (_forged_when_changed) {
		#endif
				if (_forged_when_exists) {
					if (_forged_when_defined) {
						
							updates.push_back( new IDB::sqlEqString( "forged_when", IDB::Engine::from_unixtime(_forged_when) ) );
								
					} else {
						updates.push_back( new IDB::sqlEqNull( "forged_when" ) );
					}
				}
		#ifdef MINIMAL_SAVE
			}
		#endif				
	
		/* keys dealt with later on */
		

		/* add scoop to record if exists */
		#ifdef MINIMAL_SAVE
			if (_scoop_changed) {
		#endif
				if (_scoop_exists) {
					if (_scoop_defined) {
						
							updates.push_back( new IDB::sqlEqUInt64( "scoop", _scoop ) );
								
					} else {
						updates.push_back( new IDB::sqlEqNull( "scoop" ) );
					}
				}
		#ifdef MINIMAL_SAVE
			}
		#endif				
	
		/* keys dealt with later on */
		

		/* add nonce to record if exists */
		#ifdef MINIMAL_SAVE
			if (_nonce_changed) {
		#endif
				if (_nonce_exists) {
					if (_nonce_defined) {
						
							updates.push_back( new IDB::sqlEqUInt64( "nonce", _nonce ) );
								
					} else {
						updates.push_back( new IDB::sqlEqNull( "nonce" ) );
					}
				}
		#ifdef MINIMAL_SAVE
			}
		#endif				
	
		/* keys dealt with later on */
		

		/* add gen_sig_str to record if exists */
		#ifdef MINIMAL_SAVE
			if (_gen_sig_str_changed) {
		#endif
				if (_gen_sig_str_exists) {
					if (_gen_sig_str_defined) {
						
							updates.push_back( new IDB::sqlEqString( "gen_sig_str", _gen_sig_str ) );
								
					} else {
						updates.push_back( new IDB::sqlEqNull( "gen_sig_str" ) );
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
		

		/* add our_best_deadline to record if exists */
		#ifdef MINIMAL_SAVE
			if (_our_best_deadline_changed) {
		#endif
				if (_our_best_deadline_exists) {
					if (_our_best_deadline_defined) {
						
							updates.push_back( new IDB::sqlEqUInt64( "our_best_deadline", _our_best_deadline ) );
								
					} else {
						updates.push_back( new IDB::sqlEqNull( "our_best_deadline" ) );
					}
				}
		#ifdef MINIMAL_SAVE
			}
		#endif				
	
		/* keys dealt with later on */
		

		/* add num_potential_miners to record if exists */
		#ifdef MINIMAL_SAVE
			if (_num_potential_miners_changed) {
		#endif
				if (_num_potential_miners_exists) {
					if (_num_potential_miners_defined) {
						
							updates.push_back( new IDB::sqlEqUInt64( "num_potential_miners", _num_potential_miners ) );
								
					} else {
						updates.push_back( new IDB::sqlEqNull( "num_potential_miners" ) );
					}
				}
		#ifdef MINIMAL_SAVE
			}
		#endif				
	
		/* keys dealt with later on */
		

		/* add json to record if exists */
		#ifdef MINIMAL_SAVE
			if (_json_changed) {
		#endif
				if (_json_exists) {
					if (_json_defined) {
						
							updates.push_back( new IDB::sqlEqString( "json", _json ) );
								
					} else {
						updates.push_back( new IDB::sqlEqNull( "json" ) );
					}
				}
		#ifdef MINIMAL_SAVE
			}
		#endif				
	

	/* keys: blockID */
	
		

		if (_blockID_exists) {
			if (_blockID_defined) {
				/* add blockID to updates */
				updates.push_back( new IDB::sqlEqUInt64( "blockID", _blockID ) );
			}
		}
	
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		

	/* do save */
	idbe()->writerow("Blocks", updates);

	/* clean updates */
	for(int i = 0; i < updates.size(); i++) {
		IDB::Where	*where = updates[i];
		delete where;
	}

	/* reset changed-ness */
	
		_blockID_changed = false;
	
		_first_seen_when_changed = false;
	
		_best_nonce_account_id_changed = false;
	
		_generator_account_id_changed = false;
	
		_block_reward_changed = false;
	
		_is_our_block_changed = false;
	
		_has_been_shared_changed = false;
	
		_base_target_changed = false;
	
		_forged_when_changed = false;
	
		_scoop_changed = false;
	
		_nonce_changed = false;
	
		_gen_sig_str_changed = false;
	
		_deadline_changed = false;
	
		_our_best_deadline_changed = false;
	
		_num_potential_miners_changed = false;
	
		_json_changed = false;
		

	/* autoinc support */
	
};


// special private constructor for internal use that doesn't clean column values
Block::Block( IDB::ResultSet *res ): IO::Object() {
	this->_init();
	this->_copy_from_res( res );
};


// PUBLIC METHODS
const std::string Block::Block_column_names[] = {
	
		"blockID",
	
		"first_seen_when",
	
		"best_nonce_account_id",
	
		"generator_account_id",
	
		"block_reward",
	
		"is_our_block",
	
		"has_been_shared",
	
		"base_target",
	
		"forged_when",
	
		"scoop",
	
		"nonce",
	
		"gen_sig_str",
	
		"deadline",
	
		"our_best_deadline",
	
		"num_potential_miners",
	
		"json",
	
};

// our table
std::string Block::_table() {
	return "Blocks";
}


// generic constructor
Block::Block() {
	this->_init_columns();
	this->_init();
};


// constructor that uses columns from another object (must be key field in other object)
Block::Block(IO::Object *other_obj): IO::Object() {
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
	
		if ( other_obj->is_key_by_name("best_nonce_account_id") )
			if ( other_obj->exists_by_name("best_nonce_account_id") )
				if ( other_obj->defined_by_name("best_nonce_account_id") )
					this->best_nonce_account_id( other_obj->get_UInt64_by_name("best_nonce_account_id") );
				else
					this->remove_best_nonce_account_id();
			else
				this->remove_best_nonce_account_id();
		else
			this->remove_best_nonce_account_id();
	
		if ( other_obj->is_key_by_name("generator_account_id") )
			if ( other_obj->exists_by_name("generator_account_id") )
				if ( other_obj->defined_by_name("generator_account_id") )
					this->generator_account_id( other_obj->get_UInt64_by_name("generator_account_id") );
				else
					this->remove_generator_account_id();
			else
				this->remove_generator_account_id();
		else
			this->remove_generator_account_id();
	
		if ( other_obj->is_key_by_name("block_reward") )
			if ( other_obj->exists_by_name("block_reward") )
				if ( other_obj->defined_by_name("block_reward") )
					this->block_reward( other_obj->get_UInt64_by_name("block_reward") );
				else
					this->remove_block_reward();
			else
				this->remove_block_reward();
		else
			this->remove_block_reward();
	
		if ( other_obj->is_key_by_name("is_our_block") )
			if ( other_obj->exists_by_name("is_our_block") )
				if ( other_obj->defined_by_name("is_our_block") )
					this->is_our_block( other_obj->get_Boolean_by_name("is_our_block") );
				else
					this->remove_is_our_block();
			else
				this->remove_is_our_block();
		else
			this->remove_is_our_block();
	
		if ( other_obj->is_key_by_name("has_been_shared") )
			if ( other_obj->exists_by_name("has_been_shared") )
				if ( other_obj->defined_by_name("has_been_shared") )
					this->has_been_shared( other_obj->get_Boolean_by_name("has_been_shared") );
				else
					this->remove_has_been_shared();
			else
				this->remove_has_been_shared();
		else
			this->remove_has_been_shared();
	
		if ( other_obj->is_key_by_name("base_target") )
			if ( other_obj->exists_by_name("base_target") )
				if ( other_obj->defined_by_name("base_target") )
					this->base_target( other_obj->get_UInt64_by_name("base_target") );
				else
					this->remove_base_target();
			else
				this->remove_base_target();
		else
			this->remove_base_target();
	
		if ( other_obj->is_key_by_name("forged_when") )
			if ( other_obj->exists_by_name("forged_when") )
				if ( other_obj->defined_by_name("forged_when") )
					this->forged_when( other_obj->get_Timestamp_by_name("forged_when") );
				else
					this->remove_forged_when();
			else
				this->remove_forged_when();
		else
			this->remove_forged_when();
	
		if ( other_obj->is_key_by_name("scoop") )
			if ( other_obj->exists_by_name("scoop") )
				if ( other_obj->defined_by_name("scoop") )
					this->scoop( other_obj->get_UInt64_by_name("scoop") );
				else
					this->remove_scoop();
			else
				this->remove_scoop();
		else
			this->remove_scoop();
	
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
	
		if ( other_obj->is_key_by_name("gen_sig_str") )
			if ( other_obj->exists_by_name("gen_sig_str") )
				if ( other_obj->defined_by_name("gen_sig_str") )
					this->gen_sig_str( other_obj->get_String_by_name("gen_sig_str") );
				else
					this->remove_gen_sig_str();
			else
				this->remove_gen_sig_str();
		else
			this->remove_gen_sig_str();
	
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
	
		if ( other_obj->is_key_by_name("our_best_deadline") )
			if ( other_obj->exists_by_name("our_best_deadline") )
				if ( other_obj->defined_by_name("our_best_deadline") )
					this->our_best_deadline( other_obj->get_UInt64_by_name("our_best_deadline") );
				else
					this->remove_our_best_deadline();
			else
				this->remove_our_best_deadline();
		else
			this->remove_our_best_deadline();
	
		if ( other_obj->is_key_by_name("num_potential_miners") )
			if ( other_obj->exists_by_name("num_potential_miners") )
				if ( other_obj->defined_by_name("num_potential_miners") )
					this->num_potential_miners( other_obj->get_UInt64_by_name("num_potential_miners") );
				else
					this->remove_num_potential_miners();
			else
				this->remove_num_potential_miners();
		else
			this->remove_num_potential_miners();
	
		if ( other_obj->is_key_by_name("json") )
			if ( other_obj->exists_by_name("json") )
				if ( other_obj->defined_by_name("json") )
					this->json( other_obj->get_String_by_name("json") );
				else
					this->remove_json();
			else
				this->remove_json();
		else
			this->remove_json();
	
};


// destructor
Block::~Block() {
	if (results)
		delete results;
}


// column accessor methods

	void Block::blockID(unsigned long long int new_value) {
		_blockID_exists = true;
		_blockID_defined = true;
		_blockID_changed = true;
		_blockID = new_value;
	}
	
	// inlined: moved to .hxx file
	// unsigned long long int blockID()
	 
	void Block::remove_blockID() {
		_blockID_exists = false;
		_blockID_defined = false;
		_blockID_changed = true;
		_blockID = (unsigned long long int)0;
	}
	
	void Block::undef_blockID() {
		_blockID_exists = true;
		_blockID_defined = false;
		_blockID_changed = true;
		_blockID = (unsigned long long int)0;
	}
	
	bool Block::defined_blockID() {
		return _blockID_defined;
	}
	
	bool Block::exists_blockID() {
		return _blockID_exists;
	}
	
	bool Block::changed_blockID() {
		return _blockID_changed;
	}

	void Block::first_seen_when(time_t new_value) {
		_first_seen_when_exists = true;
		_first_seen_when_defined = true;
		_first_seen_when_changed = true;
		_first_seen_when = new_value;
	}
	
	// inlined: moved to .hxx file
	// time_t first_seen_when()
	 
	void Block::remove_first_seen_when() {
		_first_seen_when_exists = false;
		_first_seen_when_defined = false;
		_first_seen_when_changed = true;
		_first_seen_when = (time_t)0;
	}
	
	void Block::undef_first_seen_when() {
		_first_seen_when_exists = true;
		_first_seen_when_defined = false;
		_first_seen_when_changed = true;
		_first_seen_when = (time_t)0;
	}
	
	bool Block::defined_first_seen_when() {
		return _first_seen_when_defined;
	}
	
	bool Block::exists_first_seen_when() {
		return _first_seen_when_exists;
	}
	
	bool Block::changed_first_seen_when() {
		return _first_seen_when_changed;
	}

	void Block::best_nonce_account_id(unsigned long long int new_value) {
		_best_nonce_account_id_exists = true;
		_best_nonce_account_id_defined = true;
		_best_nonce_account_id_changed = true;
		_best_nonce_account_id = new_value;
	}
	
	// inlined: moved to .hxx file
	// unsigned long long int best_nonce_account_id()
	 
	void Block::remove_best_nonce_account_id() {
		_best_nonce_account_id_exists = false;
		_best_nonce_account_id_defined = false;
		_best_nonce_account_id_changed = true;
		_best_nonce_account_id = (unsigned long long int)0;
	}
	
	void Block::undef_best_nonce_account_id() {
		_best_nonce_account_id_exists = true;
		_best_nonce_account_id_defined = false;
		_best_nonce_account_id_changed = true;
		_best_nonce_account_id = (unsigned long long int)0;
	}
	
	bool Block::defined_best_nonce_account_id() {
		return _best_nonce_account_id_defined;
	}
	
	bool Block::exists_best_nonce_account_id() {
		return _best_nonce_account_id_exists;
	}
	
	bool Block::changed_best_nonce_account_id() {
		return _best_nonce_account_id_changed;
	}

	void Block::generator_account_id(unsigned long long int new_value) {
		_generator_account_id_exists = true;
		_generator_account_id_defined = true;
		_generator_account_id_changed = true;
		_generator_account_id = new_value;
	}
	
	// inlined: moved to .hxx file
	// unsigned long long int generator_account_id()
	 
	void Block::remove_generator_account_id() {
		_generator_account_id_exists = false;
		_generator_account_id_defined = false;
		_generator_account_id_changed = true;
		_generator_account_id = (unsigned long long int)0;
	}
	
	void Block::undef_generator_account_id() {
		_generator_account_id_exists = true;
		_generator_account_id_defined = false;
		_generator_account_id_changed = true;
		_generator_account_id = (unsigned long long int)0;
	}
	
	bool Block::defined_generator_account_id() {
		return _generator_account_id_defined;
	}
	
	bool Block::exists_generator_account_id() {
		return _generator_account_id_exists;
	}
	
	bool Block::changed_generator_account_id() {
		return _generator_account_id_changed;
	}

	void Block::block_reward(unsigned long long int new_value) {
		_block_reward_exists = true;
		_block_reward_defined = true;
		_block_reward_changed = true;
		_block_reward = new_value;
	}
	
	// inlined: moved to .hxx file
	// unsigned long long int block_reward()
	 
	void Block::remove_block_reward() {
		_block_reward_exists = false;
		_block_reward_defined = false;
		_block_reward_changed = true;
		_block_reward = (unsigned long long int)0;
	}
	
	void Block::undef_block_reward() {
		_block_reward_exists = true;
		_block_reward_defined = false;
		_block_reward_changed = true;
		_block_reward = (unsigned long long int)0;
	}
	
	bool Block::defined_block_reward() {
		return _block_reward_defined;
	}
	
	bool Block::exists_block_reward() {
		return _block_reward_exists;
	}
	
	bool Block::changed_block_reward() {
		return _block_reward_changed;
	}

	void Block::is_our_block(bool new_value) {
		_is_our_block_exists = true;
		_is_our_block_defined = true;
		_is_our_block_changed = true;
		_is_our_block = new_value;
	}
	
	// inlined: moved to .hxx file
	// bool is_our_block()
	 
	void Block::remove_is_our_block() {
		_is_our_block_exists = false;
		_is_our_block_defined = false;
		_is_our_block_changed = true;
		_is_our_block = (bool)false;
	}
	
	void Block::undef_is_our_block() {
		_is_our_block_exists = true;
		_is_our_block_defined = false;
		_is_our_block_changed = true;
		_is_our_block = (bool)false;
	}
	
	bool Block::defined_is_our_block() {
		return _is_our_block_defined;
	}
	
	bool Block::exists_is_our_block() {
		return _is_our_block_exists;
	}
	
	bool Block::changed_is_our_block() {
		return _is_our_block_changed;
	}

	void Block::has_been_shared(bool new_value) {
		_has_been_shared_exists = true;
		_has_been_shared_defined = true;
		_has_been_shared_changed = true;
		_has_been_shared = new_value;
	}
	
	// inlined: moved to .hxx file
	// bool has_been_shared()
	 
	void Block::remove_has_been_shared() {
		_has_been_shared_exists = false;
		_has_been_shared_defined = false;
		_has_been_shared_changed = true;
		_has_been_shared = (bool)false;
	}
	
	void Block::undef_has_been_shared() {
		_has_been_shared_exists = true;
		_has_been_shared_defined = false;
		_has_been_shared_changed = true;
		_has_been_shared = (bool)false;
	}
	
	bool Block::defined_has_been_shared() {
		return _has_been_shared_defined;
	}
	
	bool Block::exists_has_been_shared() {
		return _has_been_shared_exists;
	}
	
	bool Block::changed_has_been_shared() {
		return _has_been_shared_changed;
	}

	void Block::base_target(unsigned long long int new_value) {
		_base_target_exists = true;
		_base_target_defined = true;
		_base_target_changed = true;
		_base_target = new_value;
	}
	
	// inlined: moved to .hxx file
	// unsigned long long int base_target()
	 
	void Block::remove_base_target() {
		_base_target_exists = false;
		_base_target_defined = false;
		_base_target_changed = true;
		_base_target = (unsigned long long int)0;
	}
	
	void Block::undef_base_target() {
		_base_target_exists = true;
		_base_target_defined = false;
		_base_target_changed = true;
		_base_target = (unsigned long long int)0;
	}
	
	bool Block::defined_base_target() {
		return _base_target_defined;
	}
	
	bool Block::exists_base_target() {
		return _base_target_exists;
	}
	
	bool Block::changed_base_target() {
		return _base_target_changed;
	}

	void Block::forged_when(time_t new_value) {
		_forged_when_exists = true;
		_forged_when_defined = true;
		_forged_when_changed = true;
		_forged_when = new_value;
	}
	
	// inlined: moved to .hxx file
	// time_t forged_when()
	 
	void Block::remove_forged_when() {
		_forged_when_exists = false;
		_forged_when_defined = false;
		_forged_when_changed = true;
		_forged_when = (time_t)0;
	}
	
	void Block::undef_forged_when() {
		_forged_when_exists = true;
		_forged_when_defined = false;
		_forged_when_changed = true;
		_forged_when = (time_t)0;
	}
	
	bool Block::defined_forged_when() {
		return _forged_when_defined;
	}
	
	bool Block::exists_forged_when() {
		return _forged_when_exists;
	}
	
	bool Block::changed_forged_when() {
		return _forged_when_changed;
	}

	void Block::scoop(unsigned long long int new_value) {
		_scoop_exists = true;
		_scoop_defined = true;
		_scoop_changed = true;
		_scoop = new_value;
	}
	
	// inlined: moved to .hxx file
	// unsigned long long int scoop()
	 
	void Block::remove_scoop() {
		_scoop_exists = false;
		_scoop_defined = false;
		_scoop_changed = true;
		_scoop = (unsigned long long int)0;
	}
	
	void Block::undef_scoop() {
		_scoop_exists = true;
		_scoop_defined = false;
		_scoop_changed = true;
		_scoop = (unsigned long long int)0;
	}
	
	bool Block::defined_scoop() {
		return _scoop_defined;
	}
	
	bool Block::exists_scoop() {
		return _scoop_exists;
	}
	
	bool Block::changed_scoop() {
		return _scoop_changed;
	}

	void Block::nonce(unsigned long long int new_value) {
		_nonce_exists = true;
		_nonce_defined = true;
		_nonce_changed = true;
		_nonce = new_value;
	}
	
	// inlined: moved to .hxx file
	// unsigned long long int nonce()
	 
	void Block::remove_nonce() {
		_nonce_exists = false;
		_nonce_defined = false;
		_nonce_changed = true;
		_nonce = (unsigned long long int)0;
	}
	
	void Block::undef_nonce() {
		_nonce_exists = true;
		_nonce_defined = false;
		_nonce_changed = true;
		_nonce = (unsigned long long int)0;
	}
	
	bool Block::defined_nonce() {
		return _nonce_defined;
	}
	
	bool Block::exists_nonce() {
		return _nonce_exists;
	}
	
	bool Block::changed_nonce() {
		return _nonce_changed;
	}

	void Block::gen_sig_str(std::string new_value) {
		_gen_sig_str_exists = true;
		_gen_sig_str_defined = true;
		_gen_sig_str_changed = true;
		_gen_sig_str = new_value;
	}
	
	// inlined: moved to .hxx file
	// std::string gen_sig_str()
	 
	void Block::remove_gen_sig_str() {
		_gen_sig_str_exists = false;
		_gen_sig_str_defined = false;
		_gen_sig_str_changed = true;
		_gen_sig_str = "";
	}
	
	void Block::undef_gen_sig_str() {
		_gen_sig_str_exists = true;
		_gen_sig_str_defined = false;
		_gen_sig_str_changed = true;
		_gen_sig_str = "";
	}
	
	bool Block::defined_gen_sig_str() {
		return _gen_sig_str_defined;
	}
	
	bool Block::exists_gen_sig_str() {
		return _gen_sig_str_exists;
	}
	
	bool Block::changed_gen_sig_str() {
		return _gen_sig_str_changed;
	}

	void Block::deadline(unsigned long long int new_value) {
		_deadline_exists = true;
		_deadline_defined = true;
		_deadline_changed = true;
		_deadline = new_value;
	}
	
	// inlined: moved to .hxx file
	// unsigned long long int deadline()
	 
	void Block::remove_deadline() {
		_deadline_exists = false;
		_deadline_defined = false;
		_deadline_changed = true;
		_deadline = (unsigned long long int)0;
	}
	
	void Block::undef_deadline() {
		_deadline_exists = true;
		_deadline_defined = false;
		_deadline_changed = true;
		_deadline = (unsigned long long int)0;
	}
	
	bool Block::defined_deadline() {
		return _deadline_defined;
	}
	
	bool Block::exists_deadline() {
		return _deadline_exists;
	}
	
	bool Block::changed_deadline() {
		return _deadline_changed;
	}

	void Block::our_best_deadline(unsigned long long int new_value) {
		_our_best_deadline_exists = true;
		_our_best_deadline_defined = true;
		_our_best_deadline_changed = true;
		_our_best_deadline = new_value;
	}
	
	// inlined: moved to .hxx file
	// unsigned long long int our_best_deadline()
	 
	void Block::remove_our_best_deadline() {
		_our_best_deadline_exists = false;
		_our_best_deadline_defined = false;
		_our_best_deadline_changed = true;
		_our_best_deadline = (unsigned long long int)0;
	}
	
	void Block::undef_our_best_deadline() {
		_our_best_deadline_exists = true;
		_our_best_deadline_defined = false;
		_our_best_deadline_changed = true;
		_our_best_deadline = (unsigned long long int)0;
	}
	
	bool Block::defined_our_best_deadline() {
		return _our_best_deadline_defined;
	}
	
	bool Block::exists_our_best_deadline() {
		return _our_best_deadline_exists;
	}
	
	bool Block::changed_our_best_deadline() {
		return _our_best_deadline_changed;
	}

	void Block::num_potential_miners(unsigned long long int new_value) {
		_num_potential_miners_exists = true;
		_num_potential_miners_defined = true;
		_num_potential_miners_changed = true;
		_num_potential_miners = new_value;
	}
	
	// inlined: moved to .hxx file
	// unsigned long long int num_potential_miners()
	 
	void Block::remove_num_potential_miners() {
		_num_potential_miners_exists = false;
		_num_potential_miners_defined = false;
		_num_potential_miners_changed = true;
		_num_potential_miners = (unsigned long long int)0;
	}
	
	void Block::undef_num_potential_miners() {
		_num_potential_miners_exists = true;
		_num_potential_miners_defined = false;
		_num_potential_miners_changed = true;
		_num_potential_miners = (unsigned long long int)0;
	}
	
	bool Block::defined_num_potential_miners() {
		return _num_potential_miners_defined;
	}
	
	bool Block::exists_num_potential_miners() {
		return _num_potential_miners_exists;
	}
	
	bool Block::changed_num_potential_miners() {
		return _num_potential_miners_changed;
	}

	void Block::json(std::string new_value) {
		_json_exists = true;
		_json_defined = true;
		_json_changed = true;
		_json = new_value;
	}
	
	// inlined: moved to .hxx file
	// std::string json()
	 
	void Block::remove_json() {
		_json_exists = false;
		_json_defined = false;
		_json_changed = true;
		_json = "";
	}
	
	void Block::undef_json() {
		_json_exists = true;
		_json_defined = false;
		_json_changed = true;
		_json = "";
	}
	
	bool Block::defined_json() {
		return _json_defined;
	}
	
	bool Block::exists_json() {
		return _json_exists;
	}
	
	bool Block::changed_json() {
		return _json_changed;
	}



// navigator methods



	Nonce *Block::block_nonces() {
		
			return new Nonce( this );
		
	}

	Share *Block::block_shares() {
		
			return new Share( this );
		
	}

	Reward *Block::block_rewards() {
		
			return new Reward( this );
		
	}



// run-time safe!
bool Block::has_field(std::string field) {
	
		if (!field.compare("blockID")) {
			return true;
		}
	
		if (!field.compare("first_seen_when")) {
			return true;
		}
	
		if (!field.compare("best_nonce_account_id")) {
			return true;
		}
	
		if (!field.compare("generator_account_id")) {
			return true;
		}
	
		if (!field.compare("block_reward")) {
			return true;
		}
	
		if (!field.compare("is_our_block")) {
			return true;
		}
	
		if (!field.compare("has_been_shared")) {
			return true;
		}
	
		if (!field.compare("base_target")) {
			return true;
		}
	
		if (!field.compare("forged_when")) {
			return true;
		}
	
		if (!field.compare("scoop")) {
			return true;
		}
	
		if (!field.compare("nonce")) {
			return true;
		}
	
		if (!field.compare("gen_sig_str")) {
			return true;
		}
	
		if (!field.compare("deadline")) {
			return true;
		}
	
		if (!field.compare("our_best_deadline")) {
			return true;
		}
	
		if (!field.compare("num_potential_miners")) {
			return true;
		}
	
		if (!field.compare("json")) {
			return true;
		}
	

	return false;
}


// run-time safe!
bool Block::exists_by_name(std::string field) {
	
		if (!field.compare("blockID")) {
			return _blockID_exists;
		}
	
		if (!field.compare("first_seen_when")) {
			return _first_seen_when_exists;
		}
	
		if (!field.compare("best_nonce_account_id")) {
			return _best_nonce_account_id_exists;
		}
	
		if (!field.compare("generator_account_id")) {
			return _generator_account_id_exists;
		}
	
		if (!field.compare("block_reward")) {
			return _block_reward_exists;
		}
	
		if (!field.compare("is_our_block")) {
			return _is_our_block_exists;
		}
	
		if (!field.compare("has_been_shared")) {
			return _has_been_shared_exists;
		}
	
		if (!field.compare("base_target")) {
			return _base_target_exists;
		}
	
		if (!field.compare("forged_when")) {
			return _forged_when_exists;
		}
	
		if (!field.compare("scoop")) {
			return _scoop_exists;
		}
	
		if (!field.compare("nonce")) {
			return _nonce_exists;
		}
	
		if (!field.compare("gen_sig_str")) {
			return _gen_sig_str_exists;
		}
	
		if (!field.compare("deadline")) {
			return _deadline_exists;
		}
	
		if (!field.compare("our_best_deadline")) {
			return _our_best_deadline_exists;
		}
	
		if (!field.compare("num_potential_miners")) {
			return _num_potential_miners_exists;
		}
	
		if (!field.compare("json")) {
			return _json_exists;
		}
	

	return false;
}


bool Block::defined_by_name(std::string field) {
	
		if (!field.compare("blockID")) {
			return _blockID_defined;
		}
	
		if (!field.compare("first_seen_when")) {
			return _first_seen_when_defined;
		}
	
		if (!field.compare("best_nonce_account_id")) {
			return _best_nonce_account_id_defined;
		}
	
		if (!field.compare("generator_account_id")) {
			return _generator_account_id_defined;
		}
	
		if (!field.compare("block_reward")) {
			return _block_reward_defined;
		}
	
		if (!field.compare("is_our_block")) {
			return _is_our_block_defined;
		}
	
		if (!field.compare("has_been_shared")) {
			return _has_been_shared_defined;
		}
	
		if (!field.compare("base_target")) {
			return _base_target_defined;
		}
	
		if (!field.compare("forged_when")) {
			return _forged_when_defined;
		}
	
		if (!field.compare("scoop")) {
			return _scoop_defined;
		}
	
		if (!field.compare("nonce")) {
			return _nonce_defined;
		}
	
		if (!field.compare("gen_sig_str")) {
			return _gen_sig_str_defined;
		}
	
		if (!field.compare("deadline")) {
			return _deadline_defined;
		}
	
		if (!field.compare("our_best_deadline")) {
			return _our_best_deadline_defined;
		}
	
		if (!field.compare("num_potential_miners")) {
			return _num_potential_miners_defined;
		}
	
		if (!field.compare("json")) {
			return _json_defined;
		}
	

	return false;
}


bool Block::is_key_by_name(std::string field) {
	
		if (!field.compare("blockID"))
			return true;
	

	return false;
}	





	bool Block::get_Boolean_by_name(std::string field) {
		
			
			
			
			
			
			

			if (!field.compare("is_our_block")) {
				return _is_our_block;
			}
		
			

			if (!field.compare("has_been_shared")) {
				return _has_been_shared;
			}
		
			
			
			
			
			
			
			
			
			

		std::cerr << "Unimplemented getBoolean_by_name() call for " << field << std::endl;
		return (bool)false;
	}

	std::string Block::get_String_by_name(std::string field) {
		
			
			
			
			
			
			
			
			
			
			
			
			

			if (!field.compare("gen_sig_str")) {
				return _gen_sig_str;
			}
		
			
			
			
			

			if (!field.compare("json")) {
				return _json;
			}
		

		std::cerr << "Unimplemented getString_by_name() call for " << field << std::endl;
		return "";
	}

	double Block::get_Double_by_name(std::string field) {
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			

		std::cerr << "Unimplemented getDouble_by_name() call for " << field << std::endl;
		return (double)0.0;
	}

	int Block::get_Int_by_name(std::string field) {
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			

		std::cerr << "Unimplemented getInt_by_name() call for " << field << std::endl;
		return (int)0;
	}

	time_t Block::get_Timestamp_by_name(std::string field) {
		
			
			

			if (!field.compare("first_seen_when")) {
				return _first_seen_when;
			}
		
			
			
			
			
			
			
			

			if (!field.compare("forged_when")) {
				return _forged_when;
			}
		
			
			
			
			
			
			
			

		std::cerr << "Unimplemented getTimestamp_by_name() call for " << field << std::endl;
		return (time_t)0;
	}

	unsigned char * Block::get_Blob_by_name(std::string field) {
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			

		std::cerr << "Unimplemented getBlob_by_name() call for " << field << std::endl;
		return NULL;
	}

	unsigned int Block::get_UInt_by_name(std::string field) {
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			

		std::cerr << "Unimplemented getUInt_by_name() call for " << field << std::endl;
		return (unsigned int)0;
	}

	unsigned long long int Block::get_UInt64_by_name(std::string field) {
		
			

			if (!field.compare("blockID")) {
				return _blockID;
			}
		
			
			

			if (!field.compare("best_nonce_account_id")) {
				return _best_nonce_account_id;
			}
		
			

			if (!field.compare("generator_account_id")) {
				return _generator_account_id;
			}
		
			

			if (!field.compare("block_reward")) {
				return _block_reward;
			}
		
			
			
			

			if (!field.compare("base_target")) {
				return _base_target;
			}
		
			
			

			if (!field.compare("scoop")) {
				return _scoop;
			}
		
			

			if (!field.compare("nonce")) {
				return _nonce;
			}
		
			
			

			if (!field.compare("deadline")) {
				return _deadline;
			}
		
			

			if (!field.compare("our_best_deadline")) {
				return _our_best_deadline;
			}
		
			

			if (!field.compare("num_potential_miners")) {
				return _num_potential_miners;
			}
		
			

		std::cerr << "Unimplemented getUInt64_by_name() call for " << field << std::endl;
		return (unsigned long long int)0;
	}



void Block::clear() {
	if (results)
		delete results;
		
	_init();
	_init_columns();
}


Block *Block::clone() {
	Block *c = new Block();
	
	
		if ( _blockID_defined )
			c->blockID( _blockID );
	
		if ( _first_seen_when_defined )
			c->first_seen_when( _first_seen_when );
	
		if ( _best_nonce_account_id_defined )
			c->best_nonce_account_id( _best_nonce_account_id );
	
		if ( _generator_account_id_defined )
			c->generator_account_id( _generator_account_id );
	
		if ( _block_reward_defined )
			c->block_reward( _block_reward );
	
		if ( _is_our_block_defined )
			c->is_our_block( _is_our_block );
	
		if ( _has_been_shared_defined )
			c->has_been_shared( _has_been_shared );
	
		if ( _base_target_defined )
			c->base_target( _base_target );
	
		if ( _forged_when_defined )
			c->forged_when( _forged_when );
	
		if ( _scoop_defined )
			c->scoop( _scoop );
	
		if ( _nonce_defined )
			c->nonce( _nonce );
	
		if ( _gen_sig_str_defined )
			c->gen_sig_str( _gen_sig_str );
	
		if ( _deadline_defined )
			c->deadline( _deadline );
	
		if ( _our_best_deadline_defined )
			c->our_best_deadline( _our_best_deadline );
	
		if ( _num_potential_miners_defined )
			c->num_potential_miners( _num_potential_miners );
	
		if ( _json_defined )
			c->json( _json );
	

	return c;
}


Block *Block::skeleton() {
	Block *skel = new Block();
	
	
		
		skel->blockID( _blockID );
	
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		

	return skel;
}


Block *Block::load( unsigned long long int blockID ) {
	IDB::Where *where_clause = NULL;
	
	
		 
		 	where_clause = new IDB::sqlEqUInt64( "blockID", blockID );
		 
	
	
	return load( where_clause );
};


Block *Block::load(IDB::Where *where_clause) {
	std::vector<std::string>		cols;
	IDB::Tables						*tables = new IDB::Tables("Blocks");
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
		Block *loaded_obj = new Block( res );
		delete res;
		return loaded_obj;
	}

	delete res;
	return (Block *)0;
};

/* OLD BUT WORKING VERSION:
Block *Block::load(IO::Object *other_obj) {
	Block *search_obj = new Block(other_obj);
	Block *loaded_obj;

	loaded_obj = search_obj->present();
	delete search_obj;

	return loaded_obj;
};
*/

/* NEW, FASTER VERSION: */
Block *Block::load(IO::Object *other_obj) {
	// all key columns must exist and be defined (i.e. not undef/null)
	
		if ( ! other_obj->defined_by_name( "blockID" ) )
			return NULL;
	
	
	return load( other_obj->get_UInt64_by_name( "blockID" ) );
};


std::vector<Block *> Block::load_all_vector() {
	std::vector<Block *> results;

	Block me;
	me.search();
	
	while( Block *result = me.result() ) {
		results.push_back( result );	
	}

	return results;
};



void Block::refresh() {
	std::vector<std::string>		cols;
	IDB::Tables						*tables = new IDB::Tables("Blocks");
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
	
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		

	res = idbe()->select(&cols, tables, where_clause, IDB_NO_OPTIONS);
	delete tables;
	delete where_clause;

	if (res->next()) {
		this->_copy_from_res(res);
	}

	delete res;
};


	// heavy lifting for deleting children
	void Block::_delete_children() {
		
			
			Nonce *children0 = this->block_nonces();
			
				children0->search_and_destroy();
			
			delete children0;
		
			
			Share *children1 = this->block_shares();
			
				children1->search_and_destroy();
			
			delete children1;
		
			
			Reward *children2 = this->block_rewards();
			
				children2->search_and_destroy();
			
			delete children2;
		
	}


// heavy lifting for delete_obj()
void Block::_delete_obj() {
	
		// no class-special delete_obj() method so we need to delete children ourself
		_delete_children();
	
	
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
	
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		

	idbe()->deleterow("Blocks", where_clause);
	delete where_clause;
};


Block *Block::present() { return this->present(IDB_NO_OPTIONS, (std::vector<IO::Object *> *) NULL ); }

Block *Block::present(IDB::Options *options, std::vector<IO::Object *> *additional) {
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
		Block *loaded_obj = new Block( res );
		delete res;
		return loaded_obj;
	}

	delete res;
	return (Block *)0;
}


Block *Block::present_or_self() { 
	Block *found = this->present(IDB_NO_OPTIONS, 0);
	
	if (found)
		return found;
	else
		return this;
}


Block *Block::result() {
	if (results) {
		if (results->next()) {
			return new Block( results );
		}
		
		delete results;
		results = NULL;
	}
	
	return (Block *)0;
}


std::vector<Block *> Block::results_vector() {
	std::vector<Block *> output_vector;

	while( Block *vector_entry = result() ) {
		output_vector.push_back( vector_entry );	
	}

	return output_vector;
}

		
// search modifiers

	void Block::after_blockID(uint64_t v) { _SM_after_blockID_p = true; _SM_after_blockID = v; }

	void Block::before_blockID(uint64_t v) { _SM_before_blockID_p = true; _SM_before_blockID = v; }

	void Block::has_reward_value(bool v) { _SM_has_reward_value_p = true; _SM_has_reward_value = v; }



// order by
void Block::order_by( Block_columns_t col, order_direction_t dir ) {
	_order_by = Block_column_names[col] + " " + order_direction_names[dir];
}


// check database shape matches code
bool Block::check_db_shape() {
	bool shape_OK = true;

	std::vector<std::string> cols;
	cols.push_back("*");

	IDB::Tables *tables = new IDB::Tables( "INFORMATION_SCHEMA.COLUMNS" );

	IDB::Where *where_schema = new IDB::sqlEqCol( "table_schema", "database()" );
	IDB::Where *where_table = new IDB::sqlEqString( "table_name", "Blocks" );
	
	IDB::Where *where = new IDB::sqlAnd( where_schema, where_table );

	IDB::ResultSet *res = idbe()->select(&cols, tables, where, IDB_NO_OPTIONS);

	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "blockID" ) {
				std::cerr << "Blocks column #1 should be 'blockID' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Blocks column #1 should be 'blockID' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "first_seen_when" ) {
				std::cerr << "Blocks column #2 should be 'first_seen_when' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Blocks column #2 should be 'first_seen_when' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "best_nonce_account_id" ) {
				std::cerr << "Blocks column #3 should be 'best_nonce_account_id' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Blocks column #3 should be 'best_nonce_account_id' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "generator_account_id" ) {
				std::cerr << "Blocks column #4 should be 'generator_account_id' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Blocks column #4 should be 'generator_account_id' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "block_reward" ) {
				std::cerr << "Blocks column #5 should be 'block_reward' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Blocks column #5 should be 'block_reward' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "is_our_block" ) {
				std::cerr << "Blocks column #6 should be 'is_our_block' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Blocks column #6 should be 'is_our_block' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "has_been_shared" ) {
				std::cerr << "Blocks column #7 should be 'has_been_shared' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Blocks column #7 should be 'has_been_shared' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "base_target" ) {
				std::cerr << "Blocks column #8 should be 'base_target' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Blocks column #8 should be 'base_target' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "forged_when" ) {
				std::cerr << "Blocks column #9 should be 'forged_when' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Blocks column #9 should be 'forged_when' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "scoop" ) {
				std::cerr << "Blocks column #10 should be 'scoop' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Blocks column #10 should be 'scoop' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "nonce" ) {
				std::cerr << "Blocks column #11 should be 'nonce' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Blocks column #11 should be 'nonce' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "gen_sig_str" ) {
				std::cerr << "Blocks column #12 should be 'gen_sig_str' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Blocks column #12 should be 'gen_sig_str' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "deadline" ) {
				std::cerr << "Blocks column #13 should be 'deadline' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Blocks column #13 should be 'deadline' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "our_best_deadline" ) {
				std::cerr << "Blocks column #14 should be 'our_best_deadline' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Blocks column #14 should be 'our_best_deadline' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "num_potential_miners" ) {
				std::cerr << "Blocks column #15 should be 'num_potential_miners' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Blocks column #15 should be 'num_potential_miners' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	
		

		if ( res->next() ) {
			if ( res->getString( 4 ) != "json" ) {
				std::cerr << "Blocks column #16 should be 'json' but mySQL returns '" << res->getString(4) << "'" << std::endl;
				shape_OK = false;
			}
		} else {
			std::cerr << "Blocks column #16 should be 'json' but mySQL ran out of columns!" << std::endl;
			shape_OK = false;
		}
	

	return shape_OK;
}


// lock this database record
void Block::lock_record() {
	// SELECT true FROM <table> WHERE <keys> FOR UPDATE
	std::vector<std::string> cols;
	cols.push_back("true");

	IDB::Tables *tables = new IDB::Tables("Blocks");

	IDB::Where *where_clause = NULL;
	
	
		 
		 	where_clause = new IDB::sqlEqUInt64( "blockID", _blockID );
		 
	

	IDB::Options *options = new IDB::Options;
	options->for_update = true;
	
	IDB::ResultSet *res = idbe()->select(&cols, tables, where_clause, options);
	
	delete res;

	delete options;
	delete where_clause;
	delete tables;
}

