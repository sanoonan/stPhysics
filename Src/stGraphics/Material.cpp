#include "Material.h"

#include "Shader.h"
#include "stUtils/Assertions.h"
#include "stUtils/ErrorHandling.h"

namespace stGraphics {

Material::~Material()
{
    if( _shaderProgram )
    {
        glDeleteProgram( _shaderProgram );
    }
}

bool Material::Load( const char* pszVertexShader, const char* pszFragmentShader )
{
    Shader vertShader, fragShader;

    ST_Ensure( !IsLoaded() );

    ST_Ensure( pszVertexShader && pszFragmentShader );

    ST_Ensure( vertShader.Load( pszVertexShader, Shader::Type::Vertex ) );
    ST_Ensure( fragShader.Load( pszFragmentShader, Shader::Type::Fragment ) );

    ST_Assert( _shaderProgram == 0 );
    ST_Ensure( _shaderProgram = glCreateProgram() );
    glAttachShader( _shaderProgram, vertShader.GetHandle() );
    glAttachShader( _shaderProgram, fragShader.GetHandle() );
    glLinkProgram( _shaderProgram );

    ST_ReturnBool( ( "Material::Load() - failed!" ) );
}

} //stGraphics
