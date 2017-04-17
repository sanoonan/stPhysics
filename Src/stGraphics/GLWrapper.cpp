#include "GLWrapper.h"

#include "stUtils/ErrorHandling.h"
#include "stUtils/Log.h"

namespace stGraphics {

static bool InitGLEW();
static void PrintGLVersionInfo();
static void EnableDepthTesting();

bool GLWrapper::Init()
{
    ST_Ensure( InitGLEW() );

    PrintGLVersionInfo();

    EnableDepthTesting();

    ST_ReturnBool( ( "GLWrapper::Init() - failed!" ) );
}

void GLWrapper::DrawTri( const glVec3* pVerts )
{
    ST_Assert( pVerts );
    ST_Assert( ( sizeof( pVerts ) / sizeof( glVec3 ) ) == 3 );

    GLuint vbo{ 0 };
    glGenBuffers( 1, &vbo );
    glBindBuffer( GL_ARRAY_BUFFER, vbo );
    glBufferData( GL_ARRAY_BUFFER, sizeof( pVerts ), pVerts, GL_STATIC_DRAW );

    GLuint vao{ 0 };
    glGenVertexArrays( 1, &vao );
    glBindVertexArray( vao );
    glEnableVertexAttribArray( 0 );
    glBindBuffer( GL_ARRAY_BUFFER, vbo );
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 0, NULL );
};

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

} //stGraphics
