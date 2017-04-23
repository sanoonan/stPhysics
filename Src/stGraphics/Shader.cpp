#include "Shader.h"

#include "stContainers/String.h"
#include "stFiles/InputStream.h"
#include "stTypes/Types.h"
#include "stUtils/Assertions.h"
#include "stUtils/ErrorHandling.h"

namespace stGraphics {

static GLuint CreateShader( Shader::Type type );

Shader::~Shader()
{
    if( _shader )
    {
        glDeleteShader( _shader );
    }
}

bool Shader::Load( const char* pszShaderPath, const Type type )
{
    using stFiles::InputStream;
    using stContainers::String;

    String shaderStr;
    const char* pszShaderBuffer{ ST_NULL };

    ST_Ensure( _shader == 0 );

    ST_Ensure( pszShaderPath );

    ST_Ensure( InputStream::ReadFileToString( shaderStr, pszShaderPath ) );
    ST_Ensure( pszShaderBuffer = shaderStr.CStr() );

    ST_Ensure( _shader = CreateShader( type ) );
    glShaderSource( _shader, 1, &pszShaderBuffer, NULL );
    glCompileShader( _shader );

    ST_ReturnBool( ( "Shader::Loader() - failed!" ) );
}

static GLuint CreateShader( Shader::Type type )
{
    switch( type )
    {
        case( Shader::Type::Vertex ):
            return glCreateShader( GL_VERTEX_SHADER );

        case( Shader::Type::Fragment ):
            return glCreateShader( GL_FRAGMENT_SHADER );
    };

    return 0;
}

} //stGraphics
