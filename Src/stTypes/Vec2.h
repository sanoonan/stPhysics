#pragma once

namespace stTypes {

struct Vec2
{
    union
    {
        float x;
        float w;
    };

    union
    {
        float y;
        float h;
    };

    Vec2( const float inX, const float inY ) : x( inX ), y( inY ) {}

    bool GreaterThanZero() const { return x > 0 && y > 0; }
};

};