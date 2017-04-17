#pragma once

#include "stMaths/Vec3.h"
#include "stUtils/StaticClass.h"

#include "GLTypes.h"

namespace stGraphics {

using glVec3 = stMaths::Vec3Base< GLfloat >;

class GLWrapper : stUtils::StaticClass
{
public:
    static bool Init();

    static void DrawTri( const glVec3* pVerts );
};

} //stGraphics


