#include "Material.h"

#include "GLTypes.h"
#include "Shader.h"
#include "stUtils/ErrorHandling.h"

namespace stGraphics {

bool Material::Load( const char* pszVertexShader, const char* pszFragmentShader )
{
    Shader vertShader, fragShader;

    ST_Ensure( pszVertexShader && pszFragmentShader );

    ST_Ensure( vertShader.Load( pszVertexShader, Shader::Type::Vertex ) );
    ST_Ensure( fragShader.Load( pszFragmentShader, Shader::Type::Vertex ) );

    //@TODO - compile

    ST_ReturnBool( ( "Material::Load() - failed!" ) );
}

} //stGraphics
