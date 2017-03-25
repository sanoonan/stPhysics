#include "ApplicationWindow.h"

#include "stTypes/Vec2.h"
#include "stUtils/ErrorHandling.h"
#include "stUtils/Log.h"

#include <GLFW/glfw3.h>

namespace stGraphics {

ApplicationWindow& ApplicationWindow::Get()
{
    static ApplicationWindow instance;
    return instance;
}

bool ApplicationWindow::Open( const char* pszName, const stTypes::Vec2& size )
{
    ST_Ensure( pszName );
    ST_Ensure( size.GreaterThanZero() );

    ST_Ensure( !_glfwWindow );

#if defined( APPLE )
    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 2 );
    glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );
    glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
#endif

    ST_Ensure( glfwInit() );

    ST_Ensure( _glfwWindow = glfwCreateWindow( size.w, size.h, pszName, NULL, NULL ) );
    glfwMakeContextCurrent( _glfwWindow );

    ST_ReturnBool( "ApplicationWindow::Open() - failed!" );
}

void ApplicationWindow::Close()
{
    if( !_glfwWindow )
        return;

    glfwTerminate();
}

} //stGraphics