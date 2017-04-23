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

    GLuint GetHandle() const { return _shader; }

private:
    GLuint _shader{ 0 };
};

} //stGraphics
