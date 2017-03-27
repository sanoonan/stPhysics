#pragma once

#include "stMaths/VecDeclarations.h"
#include "stUtils/Assertions.h"

namespace stMaths {

template< typename T, unsigned int N >
class Vec
{
    ST_StaticAssert( N > 0 );

public:
    bool AllGreaterThanZero() const
    {
        for( int i = 0; i < N; ++i )
            if( v[i] <= 0.0f )
                return false;
        return true;
    }

public:
    T& Get( const int index )
    {
        ST_Assert( index >= 0 && index < N );
        return v[ index ];
    }

    const T& Get( const int index ) const
    {
        ST_Assert( index >= 0 && index < N );
        return v[ index ];
    }

private:
    T v[ N ];
};

} //stMaths
