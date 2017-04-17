#pragma once

#include "stGraphics/GLWrapper.h"

namespace stGraphics {

class Tri
{
    Tri( const stMaths::Vec3& v1, const stMaths::Vec3& v2, const stMaths::Vec3& v3 ) :
            _verts{ v1, v2, v3 } {}

    void Render();

private:
    glVec3 _verts[ 3 ];
};

} //stGraphics
