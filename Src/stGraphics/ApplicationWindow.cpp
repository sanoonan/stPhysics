#include "ApplicationWindow.h"

#include "stMaths/Vec2.h"
#include "stUtils/ErrorHandling.h"

#include "stGraphics/GLFWInclude.h"

namespace stGraphics {

bool ApplicationWindow::Open( const char* pszName, const stMaths::Vec2i& size )
{
    ST_Ensure( pszName );
    ST_Ensure( size.AllGreaterThanZero() );

    ST_Ensure( !_glfwWindow );

#if defined( APPLE )
    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 2 );
    glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );
    glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
#endif

    ST_Ensure( glfwInit() );

    ST_Ensure( _glfwWindow = glfwCreateWindow( size.W(), size.H(), pszName, NULL, NULL ) );
    glfwMakeContextCurrent( _glfwWindow );

    ST_ReturnBool( ( "ApplicationWindow::Open() - failed!" ) );
}

void ApplicationWindow::Close()
{
    if( !_glfwWindow )
        return;

    glfwTerminate();
}

bool ApplicationWindow::ShouldClose() const
{
    if( _glfwWindow )
        return glfwWindowShouldClose( _glfwWindow );

    return true;
}

void ApplicationWindow::SwapBuffers()
{
    ST_Ensure( _glfwWindow );
    glfwSwapBuffers( _glfwWindow );

    ST_Return( ( "ApplicationWindow::SwapBuffers() - failed!" ) );
}

} //stGraphics