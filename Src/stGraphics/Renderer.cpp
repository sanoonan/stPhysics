#include "Renderer.h"

#include "stGraphics/GLWrapper.h"
#include "stUtils/ErrorHandling.h"
#include "stUtils/Log.h"

namespace stGraphics {

Renderer& Renderer::Get()
{
    static Renderer instance;
    return instance;
}

bool Renderer::Init()
{
    ST_Ensure( GLWrapper::Init() );



    ST_ReturnBool( ( "Renderer::Init() - failed!" ) );
}



} //stGraphics
