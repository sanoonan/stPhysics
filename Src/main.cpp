#include <stGraphics/Renderer.h>
#include <stFiles/InputStream.h>
#include <stContainers/String.h>
#include <stUtils/Log.h>
#include <stEvents/EventHandler.h>
#include "stGraphics/ApplicationWindow.h"
#include "stMaths/Vec2.h"

int main ()
{
    using stGraphics::ApplicationWindow;

    ApplicationWindow::Get().Open( "Testing", stMaths::Vec2i{ 640, 480 } );

    stGraphics::Renderer::Get().Init();

//    stFiles::InputStream iStream;
//    iStream.Open( "../Assets/Shaders/sample.vert" );
//    stContainers::String string;
//    iStream.ReadFile( string );
//    stUtils::Log::Info( string.CStr() );

    while( !ApplicationWindow::Get().ShouldClose() )
    {
        stEvents::EventHandler::PollEvents();
    }

    ApplicationWindow::Get().Close();

    return 0;
}
