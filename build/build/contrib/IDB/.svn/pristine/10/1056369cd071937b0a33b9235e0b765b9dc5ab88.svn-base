#include "IDB/tableOrSubquery.h"

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif


namespace IDB {

	// Table (simple)
	std::string Table::toString() {
		return simple_table;
	};
	

	unsigned int Table::bind(sql::PreparedStatement *pstmt, unsigned int bind_offset) {
		return bind_offset;
	};




	// Subquery
	std::string Subquery::toString() {
		std::string sql = "(SELECT ";
		std::string delimiter = "";

		for( std::vector<std::string>::const_iterator it = sub_cols->begin(); it != sub_cols->end(); it++) {
			sql += delimiter + *it;
			delimiter = ", ";
		}

		if (sub_tables)
			sql += " FROM " + sub_tables->toString();

		if (sub_where)
			sql += " WHERE " + sub_where->toString();

		if (sub_options)
			sql += sub_options->toString();
		
		sql += ") AS " + sub_table;
		
		return sql;
	};
	

	unsigned int Subquery::bind(sql::PreparedStatement *pstmt, unsigned int bind_offset) {
		if (sub_tables)
			bind_offset = sub_tables->bind(pstmt, bind_offset);

		if (sub_where)
			bind_offset = sub_where->bind(pstmt, bind_offset);

		if (sub_options)
			bind_offset = sub_options->bind(pstmt, bind_offset);

		return bind_offset;
	};
	

	Subquery::~Subquery() {
		if (sub_cols)
			delete sub_cols;

		if (sub_tables && sub_tables != IDB_NO_TABLES)
			delete sub_tables;

		if (sub_where && sub_where != IDB_NO_WHERE)
			delete sub_where;

		if (sub_options && sub_options != IDB_NO_OPTIONS)
			delete sub_options;
	};
}
