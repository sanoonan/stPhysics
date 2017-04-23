#include "Application.h"

#include "stEvents/EventHandler.h"
#include "stGraphics/GLWrapper.h"
#include "stMaths/Vec2.h"
#include "stUtils/ErrorHandling.h"

namespace Application {

Application& Application::Get()
{
    static Application sInstance;
    return sInstance;
}

bool Application::Init()
{
    ST_Ensure( _window.Open( "ApplicationWindow", stMaths::Vec2i{ 640, 480 } ) );
    ST_Ensure( stGraphics::GLWrapper::Init() );

    ST_ReturnBool( ( "Application::Init() - failed!" ) );
}

void Application::RunLoop()
{
    Update();
    Render();
}

void Application::Update()
{
    stEvents::EventHandler::PollEvents();
}

void Application::Render()
{
    stGraphics::GLWrapper::PreRender();

    _window.SwapBuffers();
}

} //Application