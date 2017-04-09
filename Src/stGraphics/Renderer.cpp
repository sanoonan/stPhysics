#include "Renderer.h"

#include "stGraphics/GLEWWrapper.h"
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
    ST_Ensure( GLEWWrapper::Init() );



    ST_ReturnBool( "Renderer::Init() - failed!" );
}



} //stGraphics
