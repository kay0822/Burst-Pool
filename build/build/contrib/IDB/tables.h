#ifndef IDB_TABLES_INCLUDED
#define IDB_TABLES_INCLUDED 1

#include <cppconn/prepared_statement.h>
#include <vector>
#include <string>

#define IDB_NO_TABLES (IDB::Tables *)0
#define IDB_NO_ON_CLAUSE (IDB::Where *)0

namespace IDB {

	class TableOrSubquery;
	class Where;

	class Tables {
		private:
			class TableJoin {
				private:
					bool						table_needs_deleting;

				public:
					std::string					join;
					IDB::TableOrSubquery		*table;
					IDB::Where					*on;

					TableJoin( std::string join_type, IDB::TableOrSubquery *new_table, IDB::Where *on_clause );
					TableJoin( std::string join_type, std::string new_table, IDB::Where *on_clause );
					~TableJoin();
			};

			IDB::TableOrSubquery			*initial_table;
			bool							initial_table_needs_deleting;

			// top-level Tables	 object passed to select() holds all the joins
			std::vector<TableJoin *>		joins;

		public:
			Tables( IDB::TableOrSubquery *table );
			// backwards compatibility
			Tables( std::string table );

			void join( std::string join_type, IDB::TableOrSubquery *new_table, IDB::Where *on_clause );
			// backwards compatibility
			void join( std::string join_type, std::string new_table, IDB::Where *on_clause );


			std::string toString();
			unsigned int bind( sql::PreparedStatement *pstmt, unsigned int bind_offset );
			~Tables();
	};

}

#endif
