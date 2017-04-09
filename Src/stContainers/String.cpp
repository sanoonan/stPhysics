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

} //stContainers
