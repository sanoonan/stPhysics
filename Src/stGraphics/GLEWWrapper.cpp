#include "GLEWWrapper.h"

#include "stUtils/Log.h"

#include "GL/glew.h"

namespace stGraphics {

static void PrintGLVersionInfo();

bool GLEWWrapper::Init()
{
    glewExperimental = GL_TRUE;
    glewInit ();

    PrintGLVersionInfo();

    glEnable( GL_DEPTH_TEST );
    glDepthFunc( GL_LESS );

    return true;
}

static void PrintGLVersionInfo()
{
    const GLubyte* renderer = glGetString( GL_RENDERER );
    const GLubyte* version = glGetString( GL_VERSION );
    stUtils::Log::Info( "Renderer: ", renderer );
    stUtils::Log::Info( "OpenGL version supported: ", version );
}

} //stGraphics
