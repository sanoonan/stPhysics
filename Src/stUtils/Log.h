#pragma once

#include "stUtils/StaticClass.h"

#include <iostream>

namespace stUtils {

class Log : StaticClass
{


public:
    template< typename... Args >
    static void Error( const char* pszMsg, const Args&... args )
    {
        Print( "ERROR:", pszMsg, args..., "\n" );
    }

    template< typename... Args >
    static void Info( const char* pszMsg, const Args&... args )
    {
        Print( "INFO:", pszMsg, args..., "\n" );
    }

private:
    template< typename... Args >
    static void Print( const unsigned char* const pszMsg, const Args&... args )
    {
        Print( pszMsg );
        Print( args... );
    }

    static void Print( const unsigned char* const pszMsg )
    {
        std::cout << pszMsg;
    }

    template< typename... Args >
    static void Print( const char* const pszMsg, const Args&... args )
    {
        Print( pszMsg );
        Print( args... );
    }

    static void Print( const char* const pszMsg )
    {
        std::cout << pszMsg;
    }

};

} //stUtils

