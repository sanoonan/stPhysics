#include <stGraphics/Renderer.h>
#include "stGraphics/ApplicationWindow.h"
#include "stMaths/Vec2.h"

int main ()
{
    using stGraphics::ApplicationWindow;

    ApplicationWindow::Get().Open( "Testing", stMaths::Vec2i{ 640, 480 } );

    stGraphics::Renderer::Get().Init();

    while( !ApplicationWindow::Get().ShouldClose() )
    {
    }

    ApplicationWindow::Get().Close();

    return 0;
}
