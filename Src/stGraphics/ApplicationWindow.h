#pragma once

#include "stMaths/VecDeclarations.h"
#include "stTypes/Types.h"
#include "stUtils/NonCopyable.h"

struct GLFWwindow;

namespace stGraphics {

class ApplicationWindow : stUtils::NonCopyable
{
public:
    static ApplicationWindow& Get();

public:
    bool Open( const char* pszName, const stMaths::Vec2i& size );
    void Close();

    bool ShouldClose() const;

private:
    ApplicationWindow() = default;

private:
    GLFWwindow* _glfwWindow{ ST_NULL };
};

} //stGraphics

