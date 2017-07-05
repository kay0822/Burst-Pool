#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <stdio.h>
#include <string>

#include "ftime.hpp"

#ifdef DEBUG_WITH_DMALLOC
#include "dmalloc.h"
#endif



std::string ftime() {
	char ftime_buf[100];
	memset( ftime_buf, '\0', sizeof(ftime_buf) );

	struct timeval tp;
	gettimeofday( &tp, NULL );
	strftime( ftime_buf, sizeof(ftime_buf), "%Y-%m-%d %H:%M:%S", gmtime(&tp.tv_sec) );
	sprintf( &ftime_buf[ strlen(ftime_buf) ], ".%06lu ", tp.tv_usec );

	return std::string(ftime_buf);
}
