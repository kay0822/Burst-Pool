BASE=../..
INC=-I. -I.. -Igenerated -I../.. -I/usr/local/include
LIBA=libIDB.a
LIBS=libIDB.so
CXXFLAGS?=-O3
CXXFLAGS+=-g -pthread -std=c++11 -pipe
SHELL=/usr/local/bin/bash

ifneq (,${findstring g++,${CXX}})
LDRPATHS+=-Wl,--rpath=/usr/local/lib/gcc49
endif

LIBDIRS=
LDFLAGS=${LIBDIRS} ${LDRPATHS} -shared -fpic -Wl,-soname,${LIBS} 


OPS=Eq Ge Gt Le Lt Ne
TYPES=Boolean Col Double Int Null String UInt UInt64

OBJS=engine.o tables.o where.o options.o resultset.o tableOrSubquery.o
INCS=IDB.h engine.h tables.h where.h options.h resultset.h tableOrSubquery.h

EXTRA_INCS=${shell ls -1 sql*.h | fgrep -v sqlOp | fgrep -v sqlIn.h | fgrep -v sqlBetween.h }
EXTRA_OBJS=${EXTRA_INCS:.h=.o}


.PHONY: generated-ops generated-ops-makefile compareOps.h

all: generated-ops ${LIBA} ${LIBS} generated/compareOps.h

clean:
	rm -fr *.o *.so *.a generated

${LIBA}: ${OBJS} ${EXTRA_OBJS}
	rm -f ${LIBA}
	ar r ${LIBA} $^ `ls -1 generated/*.o`

${LIBS}: ${OBJS} ${EXTRA_OBJS}
	${CXX} ${CXXFLAGS} ${LDFLAGS} -o ${LIBS} $^ `ls -1 generated/*.o`

.cpp.o: $*.h
	${CXX} ${CXXFLAGS} -fpic ${INC} -c -o $*.o $<

install: ${LIBA} ${LIBS} generated/compareOps.h
	cp ${LIBA} ${LIBS} ${BASE}/lib
	rm -fr ${BASE}/include/IDB
	mkdir ${BASE}/include/IDB
	cp `ls -1 generated/*.h *.h` ${EXTRA_INCS} ${BASE}/include/IDB

generated/compareOps.h: 
	@rm -f generated/compareOps.h
	for op in `(cd generated; ls -1 *.h)` ${EXTRA_INCS}; do echo '#include "IDB/'$${op}'"' >> generated/compareOps.h; done

generated-ops: generated-ops-makefile
	@echo '--> Generating SQL compare operators code'
	@gmake -f Makefile -f generated/Makefile generate-all

generated-ops-makefile:
	@echo '--> Generating SQL compare operators Makefile'
	@mkdir -p generated
	@rm -f generated/Makefile
	@for type in ${TYPES}; do \
		for op in ${OPS}; do \
			echo "generate-all: generated/sql$${op}$${type}.o" >> generated/Makefile; \
			echo "generated/sql$${op}$${type}.o: generated/sql$${op}$${type}.h generated/sql$${op}$${type}.cpp" >> generated/Makefile; \
			echo "generated/sql$${op}$${type}.h: sqlOp$${type}.h" >> generated/Makefile; \
			echo "	@sed 's/IDB_OP/$${op}/g' sqlOp$${type}.h > generated/sql$${op}$${type}.h" >> generated/Makefile; \
			echo "generated/sql$${op}$${type}.cpp: sqlOp$${type}.cpp op$${op}.h" >> generated/Makefile; \
			echo "	@sed 's/IDB_OP/$${op}/g' sqlOp$${type}.cpp > generated/sql$${op}$${type}.cpp" >> generated/Makefile; \
		done; \
		for op in In Between; do \
			if [ "$${type}" != "Null" ]; then \
				lowerOp=$${op,?}; \
				echo "generate-all: generated/sql$${op}$${type}.o" >> generated/Makefile; \
				echo "generated/sql$${op}$${type}.o: generated/sql$${op}$${type}.h generated/sql$${op}$${type}.cpp" >> generated/Makefile; \
				echo "generated/sql$${op}$${type}.h: sql$${op}.h" >> generated/Makefile; \
				echo "	@sed 's/IDB_SQL_TYPE/$${type}/g' sql$${op}.h | ${CXX} ${INC} -E -P - > generated/sql$${op}$${type}.h" >> generated/Makefile; \
				echo "generated/sql$${op}$${type}.cpp: sql$${op}.cpp $${lowerOp}$${type}.h" >> generated/Makefile; \
				echo "	@sed 's/IDB_SQL_TYPE/$${type}/g' sql$${op}.cpp > generated/sql$${op}$${type}.cpp" >> generated/Makefile; \
			fi; \
		done; \
	done
