#include "Shader.h"

#include "stContainers/String.h"
#include "stFiles/InputStream.h"
#include "stTypes/Types.h"
#include "stUtils/Assertions.h"
#include "stUtils/ErrorHandling.h"

namespace stGraphics {

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
    const char* shaderBuffer{ ST_NULL };

    ST_Ensure( _shader == 0 );

    ST_Ensure( pszShaderPath );

    ST_Ensure( InputStream::ReadFileToString( shaderStr, pszShaderPath ) );
    ST_Ensure( shaderBuffer = shaderStr.CStr() );

    ST_Ensure( _shader = glCreateShader( GL_VERTEX_SHADER ) );
    glShaderSource( _shader, 1, &shaderBuffer, NULL );
    glCompileShader( _shader );

    ST_ReturnBool( ( "Shader::Loader() - failed!" ) );
}

} //stGraphics
