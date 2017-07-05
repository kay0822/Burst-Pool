#ifndef SSTRING
#if (defined(__GNUC__) || defined(__GNUG__)) && !(defined(__clang__) || defined(__INTEL_COMPILER))
#define SSTRING(x) dynamic_cast<std::ostringstream &>( std::ostringstream() << std::dec << x ).str()
#else
#define SSTRING(x) ( std::ostringstream() << std::dec << x ).str()
#endif
#endif
