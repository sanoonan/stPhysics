#include "String.h"

#include "stUtils/Assertions.h"

namespace stContainers {

String& String::Append( const char* pszValue )
{
    _string.append( pszValue );
    return *this;
}

String& String::Append( const char value )
{
    _string.push_back( value );
    return *this;
}

String& String::Append( const float value )
{
    std::string valueStr = std::to_string( value );
    return Append( valueStr.c_str() );
}

} //stContainers
