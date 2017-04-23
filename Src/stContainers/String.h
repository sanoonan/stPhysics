#pragma once

#include "stUtils/NonCopyable.h"

#include <string>

namespace stContainers {

class String : stUtils::NonCopyable
{
public:
    String& Append( const char* pszValue );
    String& Append( const char value );

    String& Append( const float value );

    const char* CStr() const { return _string.c_str(); }

private:
    std::string _string;
};

} //stContainers
