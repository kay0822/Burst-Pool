#ifndef IDB_TABLE_OR_SUBQUERY_INCLUDED
#define IDB_TABLE_OR_SUBQUERY_INCLUDED 1

#include "IDB/tables.h"
#include "IDB/where.h"
#include "IDB/options.h"

#include <cppconn/prepared_statement.h>
#include <vector>
#include <string>

namespace IDB {

	class Tables;
	class Where;
	class Options;
	

	class TableOrSubquery {
		public:
			virtual std::string toString() =0;
			virtual unsigned int bind(sql::PreparedStatement *pstmt, unsigned int bind_offset) =0;
			virtual ~TableOrSubquery() { };
	};
	
	class Table: public TableOrSubquery {
		private:
			std::string simple_table;
	
		public:
			Table(std::string table): simple_table(table) { };
			virtual std::string toString();
			virtual unsigned int bind(sql::PreparedStatement *pstmt, unsigned int bind_offset);			
	};
	
	class Subquery: public TableOrSubquery {
		private:
			std::vector<std::string>	*sub_cols;
			IDB::Tables					*sub_tables;
			IDB::Where					*sub_where;
			IDB::Options				*sub_options;
			std::string					sub_table;
			
		public:
			Subquery( std::vector<std::string> *cols, IDB::Tables *tables, IDB::Where *where, IDB::Options *options, std::string table ): \
				sub_cols(cols), sub_tables(tables), sub_where(where), sub_options(options), sub_table(table) { };
			virtual std::string toString();
			virtual unsigned int bind(sql::PreparedStatement *pstmt, unsigned int bind_offset);
			~Subquery();
	};
}

#endif
