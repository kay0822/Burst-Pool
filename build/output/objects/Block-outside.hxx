
// object "outside" .hxx template

#include "IDB/IDB.h"
#include "IO/Object.h"

#ifdef STATIC
#undef STATIC
#endif
#define STATIC static

// class definitions needed by this class


// child objects

class Nonce;
#include "Nonce.hpp"

class Share;
#include "Share.hpp"

class Reward;
#include "Reward.hpp"


