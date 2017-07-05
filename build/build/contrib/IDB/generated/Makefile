generate-all: generated/sqlEqBoolean.o
generated/sqlEqBoolean.o: generated/sqlEqBoolean.h generated/sqlEqBoolean.cpp
generated/sqlEqBoolean.h: sqlOpBoolean.h
	@sed 's/IDB_OP/Eq/g' sqlOpBoolean.h > generated/sqlEqBoolean.h
generated/sqlEqBoolean.cpp: sqlOpBoolean.cpp opEq.h
	@sed 's/IDB_OP/Eq/g' sqlOpBoolean.cpp > generated/sqlEqBoolean.cpp
generate-all: generated/sqlGeBoolean.o
generated/sqlGeBoolean.o: generated/sqlGeBoolean.h generated/sqlGeBoolean.cpp
generated/sqlGeBoolean.h: sqlOpBoolean.h
	@sed 's/IDB_OP/Ge/g' sqlOpBoolean.h > generated/sqlGeBoolean.h
generated/sqlGeBoolean.cpp: sqlOpBoolean.cpp opGe.h
	@sed 's/IDB_OP/Ge/g' sqlOpBoolean.cpp > generated/sqlGeBoolean.cpp
generate-all: generated/sqlGtBoolean.o
generated/sqlGtBoolean.o: generated/sqlGtBoolean.h generated/sqlGtBoolean.cpp
generated/sqlGtBoolean.h: sqlOpBoolean.h
	@sed 's/IDB_OP/Gt/g' sqlOpBoolean.h > generated/sqlGtBoolean.h
generated/sqlGtBoolean.cpp: sqlOpBoolean.cpp opGt.h
	@sed 's/IDB_OP/Gt/g' sqlOpBoolean.cpp > generated/sqlGtBoolean.cpp
generate-all: generated/sqlLeBoolean.o
generated/sqlLeBoolean.o: generated/sqlLeBoolean.h generated/sqlLeBoolean.cpp
generated/sqlLeBoolean.h: sqlOpBoolean.h
	@sed 's/IDB_OP/Le/g' sqlOpBoolean.h > generated/sqlLeBoolean.h
generated/sqlLeBoolean.cpp: sqlOpBoolean.cpp opLe.h
	@sed 's/IDB_OP/Le/g' sqlOpBoolean.cpp > generated/sqlLeBoolean.cpp
generate-all: generated/sqlLtBoolean.o
generated/sqlLtBoolean.o: generated/sqlLtBoolean.h generated/sqlLtBoolean.cpp
generated/sqlLtBoolean.h: sqlOpBoolean.h
	@sed 's/IDB_OP/Lt/g' sqlOpBoolean.h > generated/sqlLtBoolean.h
generated/sqlLtBoolean.cpp: sqlOpBoolean.cpp opLt.h
	@sed 's/IDB_OP/Lt/g' sqlOpBoolean.cpp > generated/sqlLtBoolean.cpp
generate-all: generated/sqlNeBoolean.o
generated/sqlNeBoolean.o: generated/sqlNeBoolean.h generated/sqlNeBoolean.cpp
generated/sqlNeBoolean.h: sqlOpBoolean.h
	@sed 's/IDB_OP/Ne/g' sqlOpBoolean.h > generated/sqlNeBoolean.h
generated/sqlNeBoolean.cpp: sqlOpBoolean.cpp opNe.h
	@sed 's/IDB_OP/Ne/g' sqlOpBoolean.cpp > generated/sqlNeBoolean.cpp
generate-all: generated/sqlInBoolean.o
generated/sqlInBoolean.o: generated/sqlInBoolean.h generated/sqlInBoolean.cpp
generated/sqlInBoolean.h: sqlIn.h
	@sed 's/IDB_SQL_TYPE/Boolean/g' sqlIn.h | c++ -I. -I.. -Igenerated -I../.. -I/usr/local/include -E -P - > generated/sqlInBoolean.h
generated/sqlInBoolean.cpp: sqlIn.cpp inBoolean.h
	@sed 's/IDB_SQL_TYPE/Boolean/g' sqlIn.cpp > generated/sqlInBoolean.cpp
generate-all: generated/sqlBetweenBoolean.o
generated/sqlBetweenBoolean.o: generated/sqlBetweenBoolean.h generated/sqlBetweenBoolean.cpp
generated/sqlBetweenBoolean.h: sqlBetween.h
	@sed 's/IDB_SQL_TYPE/Boolean/g' sqlBetween.h | c++ -I. -I.. -Igenerated -I../.. -I/usr/local/include -E -P - > generated/sqlBetweenBoolean.h
generated/sqlBetweenBoolean.cpp: sqlBetween.cpp betweenBoolean.h
	@sed 's/IDB_SQL_TYPE/Boolean/g' sqlBetween.cpp > generated/sqlBetweenBoolean.cpp
generate-all: generated/sqlEqCol.o
generated/sqlEqCol.o: generated/sqlEqCol.h generated/sqlEqCol.cpp
generated/sqlEqCol.h: sqlOpCol.h
	@sed 's/IDB_OP/Eq/g' sqlOpCol.h > generated/sqlEqCol.h
generated/sqlEqCol.cpp: sqlOpCol.cpp opEq.h
	@sed 's/IDB_OP/Eq/g' sqlOpCol.cpp > generated/sqlEqCol.cpp
generate-all: generated/sqlGeCol.o
generated/sqlGeCol.o: generated/sqlGeCol.h generated/sqlGeCol.cpp
generated/sqlGeCol.h: sqlOpCol.h
	@sed 's/IDB_OP/Ge/g' sqlOpCol.h > generated/sqlGeCol.h
generated/sqlGeCol.cpp: sqlOpCol.cpp opGe.h
	@sed 's/IDB_OP/Ge/g' sqlOpCol.cpp > generated/sqlGeCol.cpp
generate-all: generated/sqlGtCol.o
generated/sqlGtCol.o: generated/sqlGtCol.h generated/sqlGtCol.cpp
generated/sqlGtCol.h: sqlOpCol.h
	@sed 's/IDB_OP/Gt/g' sqlOpCol.h > generated/sqlGtCol.h
generated/sqlGtCol.cpp: sqlOpCol.cpp opGt.h
	@sed 's/IDB_OP/Gt/g' sqlOpCol.cpp > generated/sqlGtCol.cpp
generate-all: generated/sqlLeCol.o
generated/sqlLeCol.o: generated/sqlLeCol.h generated/sqlLeCol.cpp
generated/sqlLeCol.h: sqlOpCol.h
	@sed 's/IDB_OP/Le/g' sqlOpCol.h > generated/sqlLeCol.h
generated/sqlLeCol.cpp: sqlOpCol.cpp opLe.h
	@sed 's/IDB_OP/Le/g' sqlOpCol.cpp > generated/sqlLeCol.cpp
generate-all: generated/sqlLtCol.o
generated/sqlLtCol.o: generated/sqlLtCol.h generated/sqlLtCol.cpp
generated/sqlLtCol.h: sqlOpCol.h
	@sed 's/IDB_OP/Lt/g' sqlOpCol.h > generated/sqlLtCol.h
generated/sqlLtCol.cpp: sqlOpCol.cpp opLt.h
	@sed 's/IDB_OP/Lt/g' sqlOpCol.cpp > generated/sqlLtCol.cpp
generate-all: generated/sqlNeCol.o
generated/sqlNeCol.o: generated/sqlNeCol.h generated/sqlNeCol.cpp
generated/sqlNeCol.h: sqlOpCol.h
	@sed 's/IDB_OP/Ne/g' sqlOpCol.h > generated/sqlNeCol.h
generated/sqlNeCol.cpp: sqlOpCol.cpp opNe.h
	@sed 's/IDB_OP/Ne/g' sqlOpCol.cpp > generated/sqlNeCol.cpp
generate-all: generated/sqlInCol.o
generated/sqlInCol.o: generated/sqlInCol.h generated/sqlInCol.cpp
generated/sqlInCol.h: sqlIn.h
	@sed 's/IDB_SQL_TYPE/Col/g' sqlIn.h | c++ -I. -I.. -Igenerated -I../.. -I/usr/local/include -E -P - > generated/sqlInCol.h
generated/sqlInCol.cpp: sqlIn.cpp inCol.h
	@sed 's/IDB_SQL_TYPE/Col/g' sqlIn.cpp > generated/sqlInCol.cpp
generate-all: generated/sqlBetweenCol.o
generated/sqlBetweenCol.o: generated/sqlBetweenCol.h generated/sqlBetweenCol.cpp
generated/sqlBetweenCol.h: sqlBetween.h
	@sed 's/IDB_SQL_TYPE/Col/g' sqlBetween.h | c++ -I. -I.. -Igenerated -I../.. -I/usr/local/include -E -P - > generated/sqlBetweenCol.h
generated/sqlBetweenCol.cpp: sqlBetween.cpp betweenCol.h
	@sed 's/IDB_SQL_TYPE/Col/g' sqlBetween.cpp > generated/sqlBetweenCol.cpp
generate-all: generated/sqlEqDouble.o
generated/sqlEqDouble.o: generated/sqlEqDouble.h generated/sqlEqDouble.cpp
generated/sqlEqDouble.h: sqlOpDouble.h
	@sed 's/IDB_OP/Eq/g' sqlOpDouble.h > generated/sqlEqDouble.h
generated/sqlEqDouble.cpp: sqlOpDouble.cpp opEq.h
	@sed 's/IDB_OP/Eq/g' sqlOpDouble.cpp > generated/sqlEqDouble.cpp
generate-all: generated/sqlGeDouble.o
generated/sqlGeDouble.o: generated/sqlGeDouble.h generated/sqlGeDouble.cpp
generated/sqlGeDouble.h: sqlOpDouble.h
	@sed 's/IDB_OP/Ge/g' sqlOpDouble.h > generated/sqlGeDouble.h
generated/sqlGeDouble.cpp: sqlOpDouble.cpp opGe.h
	@sed 's/IDB_OP/Ge/g' sqlOpDouble.cpp > generated/sqlGeDouble.cpp
generate-all: generated/sqlGtDouble.o
generated/sqlGtDouble.o: generated/sqlGtDouble.h generated/sqlGtDouble.cpp
generated/sqlGtDouble.h: sqlOpDouble.h
	@sed 's/IDB_OP/Gt/g' sqlOpDouble.h > generated/sqlGtDouble.h
generated/sqlGtDouble.cpp: sqlOpDouble.cpp opGt.h
	@sed 's/IDB_OP/Gt/g' sqlOpDouble.cpp > generated/sqlGtDouble.cpp
generate-all: generated/sqlLeDouble.o
generated/sqlLeDouble.o: generated/sqlLeDouble.h generated/sqlLeDouble.cpp
generated/sqlLeDouble.h: sqlOpDouble.h
	@sed 's/IDB_OP/Le/g' sqlOpDouble.h > generated/sqlLeDouble.h
generated/sqlLeDouble.cpp: sqlOpDouble.cpp opLe.h
	@sed 's/IDB_OP/Le/g' sqlOpDouble.cpp > generated/sqlLeDouble.cpp
generate-all: generated/sqlLtDouble.o
generated/sqlLtDouble.o: generated/sqlLtDouble.h generated/sqlLtDouble.cpp
generated/sqlLtDouble.h: sqlOpDouble.h
	@sed 's/IDB_OP/Lt/g' sqlOpDouble.h > generated/sqlLtDouble.h
generated/sqlLtDouble.cpp: sqlOpDouble.cpp opLt.h
	@sed 's/IDB_OP/Lt/g' sqlOpDouble.cpp > generated/sqlLtDouble.cpp
generate-all: generated/sqlNeDouble.o
generated/sqlNeDouble.o: generated/sqlNeDouble.h generated/sqlNeDouble.cpp
generated/sqlNeDouble.h: sqlOpDouble.h
	@sed 's/IDB_OP/Ne/g' sqlOpDouble.h > generated/sqlNeDouble.h
generated/sqlNeDouble.cpp: sqlOpDouble.cpp opNe.h
	@sed 's/IDB_OP/Ne/g' sqlOpDouble.cpp > generated/sqlNeDouble.cpp
generate-all: generated/sqlInDouble.o
generated/sqlInDouble.o: generated/sqlInDouble.h generated/sqlInDouble.cpp
generated/sqlInDouble.h: sqlIn.h
	@sed 's/IDB_SQL_TYPE/Double/g' sqlIn.h | c++ -I. -I.. -Igenerated -I../.. -I/usr/local/include -E -P - > generated/sqlInDouble.h
generated/sqlInDouble.cpp: sqlIn.cpp inDouble.h
	@sed 's/IDB_SQL_TYPE/Double/g' sqlIn.cpp > generated/sqlInDouble.cpp
generate-all: generated/sqlBetweenDouble.o
generated/sqlBetweenDouble.o: generated/sqlBetweenDouble.h generated/sqlBetweenDouble.cpp
generated/sqlBetweenDouble.h: sqlBetween.h
	@sed 's/IDB_SQL_TYPE/Double/g' sqlBetween.h | c++ -I. -I.. -Igenerated -I../.. -I/usr/local/include -E -P - > generated/sqlBetweenDouble.h
generated/sqlBetweenDouble.cpp: sqlBetween.cpp betweenDouble.h
	@sed 's/IDB_SQL_TYPE/Double/g' sqlBetween.cpp > generated/sqlBetweenDouble.cpp
generate-all: generated/sqlEqInt.o
generated/sqlEqInt.o: generated/sqlEqInt.h generated/sqlEqInt.cpp
generated/sqlEqInt.h: sqlOpInt.h
	@sed 's/IDB_OP/Eq/g' sqlOpInt.h > generated/sqlEqInt.h
generated/sqlEqInt.cpp: sqlOpInt.cpp opEq.h
	@sed 's/IDB_OP/Eq/g' sqlOpInt.cpp > generated/sqlEqInt.cpp
generate-all: generated/sqlGeInt.o
generated/sqlGeInt.o: generated/sqlGeInt.h generated/sqlGeInt.cpp
generated/sqlGeInt.h: sqlOpInt.h
	@sed 's/IDB_OP/Ge/g' sqlOpInt.h > generated/sqlGeInt.h
generated/sqlGeInt.cpp: sqlOpInt.cpp opGe.h
	@sed 's/IDB_OP/Ge/g' sqlOpInt.cpp > generated/sqlGeInt.cpp
generate-all: generated/sqlGtInt.o
generated/sqlGtInt.o: generated/sqlGtInt.h generated/sqlGtInt.cpp
generated/sqlGtInt.h: sqlOpInt.h
	@sed 's/IDB_OP/Gt/g' sqlOpInt.h > generated/sqlGtInt.h
generated/sqlGtInt.cpp: sqlOpInt.cpp opGt.h
	@sed 's/IDB_OP/Gt/g' sqlOpInt.cpp > generated/sqlGtInt.cpp
generate-all: generated/sqlLeInt.o
generated/sqlLeInt.o: generated/sqlLeInt.h generated/sqlLeInt.cpp
generated/sqlLeInt.h: sqlOpInt.h
	@sed 's/IDB_OP/Le/g' sqlOpInt.h > generated/sqlLeInt.h
generated/sqlLeInt.cpp: sqlOpInt.cpp opLe.h
	@sed 's/IDB_OP/Le/g' sqlOpInt.cpp > generated/sqlLeInt.cpp
generate-all: generated/sqlLtInt.o
generated/sqlLtInt.o: generated/sqlLtInt.h generated/sqlLtInt.cpp
generated/sqlLtInt.h: sqlOpInt.h
	@sed 's/IDB_OP/Lt/g' sqlOpInt.h > generated/sqlLtInt.h
generated/sqlLtInt.cpp: sqlOpInt.cpp opLt.h
	@sed 's/IDB_OP/Lt/g' sqlOpInt.cpp > generated/sqlLtInt.cpp
generate-all: generated/sqlNeInt.o
generated/sqlNeInt.o: generated/sqlNeInt.h generated/sqlNeInt.cpp
generated/sqlNeInt.h: sqlOpInt.h
	@sed 's/IDB_OP/Ne/g' sqlOpInt.h > generated/sqlNeInt.h
generated/sqlNeInt.cpp: sqlOpInt.cpp opNe.h
	@sed 's/IDB_OP/Ne/g' sqlOpInt.cpp > generated/sqlNeInt.cpp
generate-all: generated/sqlInInt.o
generated/sqlInInt.o: generated/sqlInInt.h generated/sqlInInt.cpp
generated/sqlInInt.h: sqlIn.h
	@sed 's/IDB_SQL_TYPE/Int/g' sqlIn.h | c++ -I. -I.. -Igenerated -I../.. -I/usr/local/include -E -P - > generated/sqlInInt.h
generated/sqlInInt.cpp: sqlIn.cpp inInt.h
	@sed 's/IDB_SQL_TYPE/Int/g' sqlIn.cpp > generated/sqlInInt.cpp
generate-all: generated/sqlBetweenInt.o
generated/sqlBetweenInt.o: generated/sqlBetweenInt.h generated/sqlBetweenInt.cpp
generated/sqlBetweenInt.h: sqlBetween.h
	@sed 's/IDB_SQL_TYPE/Int/g' sqlBetween.h | c++ -I. -I.. -Igenerated -I../.. -I/usr/local/include -E -P - > generated/sqlBetweenInt.h
generated/sqlBetweenInt.cpp: sqlBetween.cpp betweenInt.h
	@sed 's/IDB_SQL_TYPE/Int/g' sqlBetween.cpp > generated/sqlBetweenInt.cpp
generate-all: generated/sqlEqNull.o
generated/sqlEqNull.o: generated/sqlEqNull.h generated/sqlEqNull.cpp
generated/sqlEqNull.h: sqlOpNull.h
	@sed 's/IDB_OP/Eq/g' sqlOpNull.h > generated/sqlEqNull.h
generated/sqlEqNull.cpp: sqlOpNull.cpp opEq.h
	@sed 's/IDB_OP/Eq/g' sqlOpNull.cpp > generated/sqlEqNull.cpp
generate-all: generated/sqlGeNull.o
generated/sqlGeNull.o: generated/sqlGeNull.h generated/sqlGeNull.cpp
generated/sqlGeNull.h: sqlOpNull.h
	@sed 's/IDB_OP/Ge/g' sqlOpNull.h > generated/sqlGeNull.h
generated/sqlGeNull.cpp: sqlOpNull.cpp opGe.h
	@sed 's/IDB_OP/Ge/g' sqlOpNull.cpp > generated/sqlGeNull.cpp
generate-all: generated/sqlGtNull.o
generated/sqlGtNull.o: generated/sqlGtNull.h generated/sqlGtNull.cpp
generated/sqlGtNull.h: sqlOpNull.h
	@sed 's/IDB_OP/Gt/g' sqlOpNull.h > generated/sqlGtNull.h
generated/sqlGtNull.cpp: sqlOpNull.cpp opGt.h
	@sed 's/IDB_OP/Gt/g' sqlOpNull.cpp > generated/sqlGtNull.cpp
generate-all: generated/sqlLeNull.o
generated/sqlLeNull.o: generated/sqlLeNull.h generated/sqlLeNull.cpp
generated/sqlLeNull.h: sqlOpNull.h
	@sed 's/IDB_OP/Le/g' sqlOpNull.h > generated/sqlLeNull.h
generated/sqlLeNull.cpp: sqlOpNull.cpp opLe.h
	@sed 's/IDB_OP/Le/g' sqlOpNull.cpp > generated/sqlLeNull.cpp
generate-all: generated/sqlLtNull.o
generated/sqlLtNull.o: generated/sqlLtNull.h generated/sqlLtNull.cpp
generated/sqlLtNull.h: sqlOpNull.h
	@sed 's/IDB_OP/Lt/g' sqlOpNull.h > generated/sqlLtNull.h
generated/sqlLtNull.cpp: sqlOpNull.cpp opLt.h
	@sed 's/IDB_OP/Lt/g' sqlOpNull.cpp > generated/sqlLtNull.cpp
generate-all: generated/sqlNeNull.o
generated/sqlNeNull.o: generated/sqlNeNull.h generated/sqlNeNull.cpp
generated/sqlNeNull.h: sqlOpNull.h
	@sed 's/IDB_OP/Ne/g' sqlOpNull.h > generated/sqlNeNull.h
generated/sqlNeNull.cpp: sqlOpNull.cpp opNe.h
	@sed 's/IDB_OP/Ne/g' sqlOpNull.cpp > generated/sqlNeNull.cpp
generate-all: generated/sqlEqString.o
generated/sqlEqString.o: generated/sqlEqString.h generated/sqlEqString.cpp
generated/sqlEqString.h: sqlOpString.h
	@sed 's/IDB_OP/Eq/g' sqlOpString.h > generated/sqlEqString.h
generated/sqlEqString.cpp: sqlOpString.cpp opEq.h
	@sed 's/IDB_OP/Eq/g' sqlOpString.cpp > generated/sqlEqString.cpp
generate-all: generated/sqlGeString.o
generated/sqlGeString.o: generated/sqlGeString.h generated/sqlGeString.cpp
generated/sqlGeString.h: sqlOpString.h
	@sed 's/IDB_OP/Ge/g' sqlOpString.h > generated/sqlGeString.h
generated/sqlGeString.cpp: sqlOpString.cpp opGe.h
	@sed 's/IDB_OP/Ge/g' sqlOpString.cpp > generated/sqlGeString.cpp
generate-all: generated/sqlGtString.o
generated/sqlGtString.o: generated/sqlGtString.h generated/sqlGtString.cpp
generated/sqlGtString.h: sqlOpString.h
	@sed 's/IDB_OP/Gt/g' sqlOpString.h > generated/sqlGtString.h
generated/sqlGtString.cpp: sqlOpString.cpp opGt.h
	@sed 's/IDB_OP/Gt/g' sqlOpString.cpp > generated/sqlGtString.cpp
generate-all: generated/sqlLeString.o
generated/sqlLeString.o: generated/sqlLeString.h generated/sqlLeString.cpp
generated/sqlLeString.h: sqlOpString.h
	@sed 's/IDB_OP/Le/g' sqlOpString.h > generated/sqlLeString.h
generated/sqlLeString.cpp: sqlOpString.cpp opLe.h
	@sed 's/IDB_OP/Le/g' sqlOpString.cpp > generated/sqlLeString.cpp
generate-all: generated/sqlLtString.o
generated/sqlLtString.o: generated/sqlLtString.h generated/sqlLtString.cpp
generated/sqlLtString.h: sqlOpString.h
	@sed 's/IDB_OP/Lt/g' sqlOpString.h > generated/sqlLtString.h
generated/sqlLtString.cpp: sqlOpString.cpp opLt.h
	@sed 's/IDB_OP/Lt/g' sqlOpString.cpp > generated/sqlLtString.cpp
generate-all: generated/sqlNeString.o
generated/sqlNeString.o: generated/sqlNeString.h generated/sqlNeString.cpp
generated/sqlNeString.h: sqlOpString.h
	@sed 's/IDB_OP/Ne/g' sqlOpString.h > generated/sqlNeString.h
generated/sqlNeString.cpp: sqlOpString.cpp opNe.h
	@sed 's/IDB_OP/Ne/g' sqlOpString.cpp > generated/sqlNeString.cpp
generate-all: generated/sqlInString.o
generated/sqlInString.o: generated/sqlInString.h generated/sqlInString.cpp
generated/sqlInString.h: sqlIn.h
	@sed 's/IDB_SQL_TYPE/String/g' sqlIn.h | c++ -I. -I.. -Igenerated -I../.. -I/usr/local/include -E -P - > generated/sqlInString.h
generated/sqlInString.cpp: sqlIn.cpp inString.h
	@sed 's/IDB_SQL_TYPE/String/g' sqlIn.cpp > generated/sqlInString.cpp
generate-all: generated/sqlBetweenString.o
generated/sqlBetweenString.o: generated/sqlBetweenString.h generated/sqlBetweenString.cpp
generated/sqlBetweenString.h: sqlBetween.h
	@sed 's/IDB_SQL_TYPE/String/g' sqlBetween.h | c++ -I. -I.. -Igenerated -I../.. -I/usr/local/include -E -P - > generated/sqlBetweenString.h
generated/sqlBetweenString.cpp: sqlBetween.cpp betweenString.h
	@sed 's/IDB_SQL_TYPE/String/g' sqlBetween.cpp > generated/sqlBetweenString.cpp
generate-all: generated/sqlEqUInt.o
generated/sqlEqUInt.o: generated/sqlEqUInt.h generated/sqlEqUInt.cpp
generated/sqlEqUInt.h: sqlOpUInt.h
	@sed 's/IDB_OP/Eq/g' sqlOpUInt.h > generated/sqlEqUInt.h
generated/sqlEqUInt.cpp: sqlOpUInt.cpp opEq.h
	@sed 's/IDB_OP/Eq/g' sqlOpUInt.cpp > generated/sqlEqUInt.cpp
generate-all: generated/sqlGeUInt.o
generated/sqlGeUInt.o: generated/sqlGeUInt.h generated/sqlGeUInt.cpp
generated/sqlGeUInt.h: sqlOpUInt.h
	@sed 's/IDB_OP/Ge/g' sqlOpUInt.h > generated/sqlGeUInt.h
generated/sqlGeUInt.cpp: sqlOpUInt.cpp opGe.h
	@sed 's/IDB_OP/Ge/g' sqlOpUInt.cpp > generated/sqlGeUInt.cpp
generate-all: generated/sqlGtUInt.o
generated/sqlGtUInt.o: generated/sqlGtUInt.h generated/sqlGtUInt.cpp
generated/sqlGtUInt.h: sqlOpUInt.h
	@sed 's/IDB_OP/Gt/g' sqlOpUInt.h > generated/sqlGtUInt.h
generated/sqlGtUInt.cpp: sqlOpUInt.cpp opGt.h
	@sed 's/IDB_OP/Gt/g' sqlOpUInt.cpp > generated/sqlGtUInt.cpp
generate-all: generated/sqlLeUInt.o
generated/sqlLeUInt.o: generated/sqlLeUInt.h generated/sqlLeUInt.cpp
generated/sqlLeUInt.h: sqlOpUInt.h
	@sed 's/IDB_OP/Le/g' sqlOpUInt.h > generated/sqlLeUInt.h
generated/sqlLeUInt.cpp: sqlOpUInt.cpp opLe.h
	@sed 's/IDB_OP/Le/g' sqlOpUInt.cpp > generated/sqlLeUInt.cpp
generate-all: generated/sqlLtUInt.o
generated/sqlLtUInt.o: generated/sqlLtUInt.h generated/sqlLtUInt.cpp
generated/sqlLtUInt.h: sqlOpUInt.h
	@sed 's/IDB_OP/Lt/g' sqlOpUInt.h > generated/sqlLtUInt.h
generated/sqlLtUInt.cpp: sqlOpUInt.cpp opLt.h
	@sed 's/IDB_OP/Lt/g' sqlOpUInt.cpp > generated/sqlLtUInt.cpp
generate-all: generated/sqlNeUInt.o
generated/sqlNeUInt.o: generated/sqlNeUInt.h generated/sqlNeUInt.cpp
generated/sqlNeUInt.h: sqlOpUInt.h
	@sed 's/IDB_OP/Ne/g' sqlOpUInt.h > generated/sqlNeUInt.h
generated/sqlNeUInt.cpp: sqlOpUInt.cpp opNe.h
	@sed 's/IDB_OP/Ne/g' sqlOpUInt.cpp > generated/sqlNeUInt.cpp
generate-all: generated/sqlInUInt.o
generated/sqlInUInt.o: generated/sqlInUInt.h generated/sqlInUInt.cpp
generated/sqlInUInt.h: sqlIn.h
	@sed 's/IDB_SQL_TYPE/UInt/g' sqlIn.h | c++ -I. -I.. -Igenerated -I../.. -I/usr/local/include -E -P - > generated/sqlInUInt.h
generated/sqlInUInt.cpp: sqlIn.cpp inUInt.h
	@sed 's/IDB_SQL_TYPE/UInt/g' sqlIn.cpp > generated/sqlInUInt.cpp
generate-all: generated/sqlBetweenUInt.o
generated/sqlBetweenUInt.o: generated/sqlBetweenUInt.h generated/sqlBetweenUInt.cpp
generated/sqlBetweenUInt.h: sqlBetween.h
	@sed 's/IDB_SQL_TYPE/UInt/g' sqlBetween.h | c++ -I. -I.. -Igenerated -I../.. -I/usr/local/include -E -P - > generated/sqlBetweenUInt.h
generated/sqlBetweenUInt.cpp: sqlBetween.cpp betweenUInt.h
	@sed 's/IDB_SQL_TYPE/UInt/g' sqlBetween.cpp > generated/sqlBetweenUInt.cpp
generate-all: generated/sqlEqUInt64.o
generated/sqlEqUInt64.o: generated/sqlEqUInt64.h generated/sqlEqUInt64.cpp
generated/sqlEqUInt64.h: sqlOpUInt64.h
	@sed 's/IDB_OP/Eq/g' sqlOpUInt64.h > generated/sqlEqUInt64.h
generated/sqlEqUInt64.cpp: sqlOpUInt64.cpp opEq.h
	@sed 's/IDB_OP/Eq/g' sqlOpUInt64.cpp > generated/sqlEqUInt64.cpp
generate-all: generated/sqlGeUInt64.o
generated/sqlGeUInt64.o: generated/sqlGeUInt64.h generated/sqlGeUInt64.cpp
generated/sqlGeUInt64.h: sqlOpUInt64.h
	@sed 's/IDB_OP/Ge/g' sqlOpUInt64.h > generated/sqlGeUInt64.h
generated/sqlGeUInt64.cpp: sqlOpUInt64.cpp opGe.h
	@sed 's/IDB_OP/Ge/g' sqlOpUInt64.cpp > generated/sqlGeUInt64.cpp
generate-all: generated/sqlGtUInt64.o
generated/sqlGtUInt64.o: generated/sqlGtUInt64.h generated/sqlGtUInt64.cpp
generated/sqlGtUInt64.h: sqlOpUInt64.h
	@sed 's/IDB_OP/Gt/g' sqlOpUInt64.h > generated/sqlGtUInt64.h
generated/sqlGtUInt64.cpp: sqlOpUInt64.cpp opGt.h
	@sed 's/IDB_OP/Gt/g' sqlOpUInt64.cpp > generated/sqlGtUInt64.cpp
generate-all: generated/sqlLeUInt64.o
generated/sqlLeUInt64.o: generated/sqlLeUInt64.h generated/sqlLeUInt64.cpp
generated/sqlLeUInt64.h: sqlOpUInt64.h
	@sed 's/IDB_OP/Le/g' sqlOpUInt64.h > generated/sqlLeUInt64.h
generated/sqlLeUInt64.cpp: sqlOpUInt64.cpp opLe.h
	@sed 's/IDB_OP/Le/g' sqlOpUInt64.cpp > generated/sqlLeUInt64.cpp
generate-all: generated/sqlLtUInt64.o
generated/sqlLtUInt64.o: generated/sqlLtUInt64.h generated/sqlLtUInt64.cpp
generated/sqlLtUInt64.h: sqlOpUInt64.h
	@sed 's/IDB_OP/Lt/g' sqlOpUInt64.h > generated/sqlLtUInt64.h
generated/sqlLtUInt64.cpp: sqlOpUInt64.cpp opLt.h
	@sed 's/IDB_OP/Lt/g' sqlOpUInt64.cpp > generated/sqlLtUInt64.cpp
generate-all: generated/sqlNeUInt64.o
generated/sqlNeUInt64.o: generated/sqlNeUInt64.h generated/sqlNeUInt64.cpp
generated/sqlNeUInt64.h: sqlOpUInt64.h
	@sed 's/IDB_OP/Ne/g' sqlOpUInt64.h > generated/sqlNeUInt64.h
generated/sqlNeUInt64.cpp: sqlOpUInt64.cpp opNe.h
	@sed 's/IDB_OP/Ne/g' sqlOpUInt64.cpp > generated/sqlNeUInt64.cpp
generate-all: generated/sqlInUInt64.o
generated/sqlInUInt64.o: generated/sqlInUInt64.h generated/sqlInUInt64.cpp
generated/sqlInUInt64.h: sqlIn.h
	@sed 's/IDB_SQL_TYPE/UInt64/g' sqlIn.h | c++ -I. -I.. -Igenerated -I../.. -I/usr/local/include -E -P - > generated/sqlInUInt64.h
generated/sqlInUInt64.cpp: sqlIn.cpp inUInt64.h
	@sed 's/IDB_SQL_TYPE/UInt64/g' sqlIn.cpp > generated/sqlInUInt64.cpp
generate-all: generated/sqlBetweenUInt64.o
generated/sqlBetweenUInt64.o: generated/sqlBetweenUInt64.h generated/sqlBetweenUInt64.cpp
generated/sqlBetweenUInt64.h: sqlBetween.h
	@sed 's/IDB_SQL_TYPE/UInt64/g' sqlBetween.h | c++ -I. -I.. -Igenerated -I../.. -I/usr/local/include -E -P - > generated/sqlBetweenUInt64.h
generated/sqlBetweenUInt64.cpp: sqlBetween.cpp betweenUInt64.h
	@sed 's/IDB_SQL_TYPE/UInt64/g' sqlBetween.cpp > generated/sqlBetweenUInt64.cpp
