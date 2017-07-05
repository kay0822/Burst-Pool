BASE=../..
INC=-I. -I.. -I/usr/local/include -I../../include
LIBA=libIO.a
LIBS=libIO.so
OBJS=Object.o PreppedSearch.o
INCS=Object.h PreppedSearch.h
CXXFLAGS?=-O3 -g -std=c++11

all: ${LIBA} ${LIBS}

clean:
	rm -f *.so *.a *.o

${LIBA}: ${OBJS}
	rm -f ${LIBA}
	ar r ${LIBA} $^

${LIBS}: ${OBJS}
	${CXX} ${CXXFLAGS} -pthread -shared -fpic -Wl,-soname,${LIBS} -o ${LIBS} $^

.cpp.o: $*.h
	${CXX} ${CXXFLAGS} -pthread -fpic ${INC} -c $<

install: ${LIBA} ${LIBS}
	cp ${LIBA} ${LIBS} ${BASE}/lib
	rm -fr ${BASE}/include/IO
	mkdir ${BASE}/include/IO
	cp ${INCS} ${BASE}/include/IO
