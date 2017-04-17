#pragma once

#include <memory>
#include "stUtils/NonCopyable.h"

namespace stGraphics {

class Material
{
public:
    bool Load( const char* pszVertexShader, const char* pszFragmentShader );

    ~Material();

private:
    Material() = default;
};

} //stGraphics
