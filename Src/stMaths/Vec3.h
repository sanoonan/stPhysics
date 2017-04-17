#pragma once

#include "stMaths/Vec.h"

namespace stMaths {

template< typename T >
class Vec3Base : public Vec< T, 3 >
{
    using Super = Vec< T, 3 >;

public:
    Vec3Base( const T x, const T y, const T z )
    {
        X() = x;
        Y() = y;
        Z() = z;
    }

    T& X() { return Super::Get( 0 ); }
    T& Y() { return Super::Get( 1 ); }
    T& Z() { return Super::Get( 2 ); }

    const T& X() const { return Super::Get( 0 ); }
    const T& Y() const { return Super::Get( 1 ); }
    const T& Z() const { return Super::Get( 2 ); }
};

} //stMaths
