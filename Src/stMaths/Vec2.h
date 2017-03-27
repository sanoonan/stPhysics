#pragma once

#include "stMaths/Vec.h"

namespace stMaths {

template< typename T >
class Vec2Base : public Vec< T, 2 >
{
    using Super = Vec< T, 2 >;

public:
    Vec2Base( const T x, const T y )
    {
        X() = x;
        Y() = y;
    }

    T& X() { return Super::Get( 0 ); }
    T& Y() { return Super::Get( 1 ); }

    T& W() { return Super::Get( 0 ); }
    T& H() { return Super::Get( 1 ); }

    const T& X() const { return Super::Get( 0 ); }
    const T& Y() const { return Super::Get( 1 ); }

    const T& W() const { return Super::Get( 0 ); }
    const T& H() const { return Super::Get( 1 ); }
};

using Vec2 = Vec2Base< float >;

} //stMaths
