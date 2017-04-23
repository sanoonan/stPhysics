#include "ApplicationWindow.h"

#include "stMaths/Vec2.h"
#include "stUtils/ErrorHandling.h"

#include "stGraphics/GLFWInclude.h"

namespace stGraphics {

bool ApplicationWindow::Open( const char* pszTitle, const stMaths::Vec2i& size )
{
    ST_Ensure( pszTitle );
    ST_Ensure( size.AllGreaterThanZero() );

    ST_Ensure( !_pGlfwWindow );

#if defined( APPLE )
    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 2 );
    glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );
    glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
#endif

    ST_Ensure( glfwInit() );

    ST_Ensure( _pGlfwWindow = glfwCreateWindow( size.W(), size.H(), pszTitle, NULL, NULL ) );
    glfwMakeContextCurrent( _pGlfwWindow );

    ST_ReturnBool( ( "ApplicationWindow::Open() - failed!" ) );
}

void ApplicationWindow::Close()
{
    if( !_pGlfwWindow )
        return;

    glfwTerminate();
}

bool ApplicationWindow::ShouldClose() const
{
    if( _pGlfwWindow )
        return glfwWindowShouldClose( _pGlfwWindow );

    return true;
}

void ApplicationWindow::SwapBuffers()
{
    ST_Ensure( _pGlfwWindow );
    glfwSwapBuffers( _pGlfwWindow );

    ST_Return( ( "ApplicationWindow::SwapBuffers() - failed!" ) );
}

void ApplicationWindow::SetTitle( const char* pszTitle )
{
    ST_Assert( _pGlfwWindow );
    ST_Assert( pszTitle );

    glfwSetWindowTitle( _pGlfwWindow, pszTitle );
}

} //stGraphics