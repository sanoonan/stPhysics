#pragma once

#include <stUtils/StaticClass.h>
#include "stTypes/Types.h"
#include "stUtils/NonCopyable.h"

namespace stTypes {
struct Vec2;
}

class GLFWwindow;

namespace stGraphics {

class ApplicationWindow : stUtils::NonCopyable
{
public:
    static ApplicationWindow& Get();

public:
    bool Open( const char* pszName, const stTypes::Vec2& size );
    void Close();

private:
    ApplicationWindow() = default;

private:
    GLFWwindow* _glfwWindow{ ST_NULL };
};

} //stGraphics

