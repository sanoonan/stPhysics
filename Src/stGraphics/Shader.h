#pragma once

#include "GLTypes.h"

namespace stGraphics {

class Shader
{
public:
    ~Shader();

    enum class Type
    {
        Vertex,
        Fragment
    };

    bool Load( const char* pszShaderPath, const Type type );

private:
    GLuint _shader;
};

} //stGraphics
