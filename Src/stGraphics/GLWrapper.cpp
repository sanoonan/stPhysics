#include "GLWrapper.h"

#include "stUtils/ErrorHandling.h"
#include "stUtils/Log.h"

namespace stGraphics {

static bool InitGLEW();
static void PrintGLVersionInfo();
static void EnableDepthTesting();
static void ClearBuffer();

bool GLWrapper::Init()
{
    ST_Ensure( InitGLEW() );

    PrintGLVersionInfo();

    EnableDepthTesting();

    ST_ReturnBool( ( "GLWrapper::Init() - failed!" ) );
}

void GLWrapper::PreRender()
{
    ClearBuffer();
}

static bool InitGLEW()
{
    glewExperimental = GL_TRUE;
    glewInit();

    return true;
}

static void PrintGLVersionInfo()
{
    const GLubyte* renderer = glGetString( GL_RENDERER );
    const GLubyte* version = glGetString( GL_VERSION );
    stUtils::Log::Info( "Renderer: ", renderer );
    stUtils::Log::Info( "OpenGL version supported: ", version );
}

static void EnableDepthTesting()
{
    glEnable( GL_DEPTH_TEST );
    glDepthFunc( GL_LESS );
}

static void ClearBuffer()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}

} //stGraphics
