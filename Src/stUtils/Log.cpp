#include "Log.h"

#include <iostream>

namespace stUtils {

void Log::Error( const char* pszMsg )
{
    std::cout << "ERROR: " << pszMsg << "\n";
}

} //stUtils
