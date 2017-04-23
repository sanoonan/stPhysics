#pragma once

#include "stGraphics/GLWrapper.h"

namespace stGraphics {

class Material;

class Tri
{
public:
    Tri( const stMaths::Vec3& v1, const stMaths::Vec3& v2, const stMaths::Vec3& v3 );

    void Render( const Material& material );

private:
    glVec3 _verts[ 3 ];

    GLuint _vao{ 0 };
};

} //stGraphics
