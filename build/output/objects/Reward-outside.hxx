
// object "outside" .hxx template

#include "IDB/IDB.h"
#include "IO/Object.h"

#ifdef STATIC
#undef STATIC
#endif
#define STATIC static

// class definitions needed by this class

class Block;
#include "Block.hpp"

class Account;
#include "Account.hpp"


// child objects


