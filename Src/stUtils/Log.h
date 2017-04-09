#pragma once

#include "stUtils/StaticClass.h"

#include <iostream>

namespace stUtils {

class Log : StaticClass
{


public:
    template< typename... Args >
    static void Error( const Args&... args )
    {
        Print( "ERROR:", args..., "\n" );
    }

    template< typename... Args >
    static void Info( const Args&... args )
    {
        Print( "INFO:", args..., "\n" );
    }

private:
    template< typename T, typename... Args >
    static void Print( const T& msg, const Args&... args )
    {
        Print( msg );
        Print( args... );
    }

    template< typename T >
    static void Print( const T& msg )
    {
        std::cout << msg;
    }
};

} //stUtils

