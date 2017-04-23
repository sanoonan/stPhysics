#pragma once

#include "GLTypes.h"
#include "stUtils/NonCopyable.h"

namespace stGraphics {

class Material : stUtils::NonCopyable
{
public:
    ~Material();

    bool Load( const char* pszVertexShader, const char* pszFragmentShader );

    bool IsLoaded() const { return _shaderProgram != 0; }

    GLuint GetHandle() const { return _shaderProgram; }

private:
    GLuint _shaderProgram{ 0 };
};

} //stGraphics
