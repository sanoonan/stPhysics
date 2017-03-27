#include "stGraphics/ApplicationWindow.h"
#include "stMaths/Vec2.h"

int main ()
{
    stGraphics::ApplicationWindow::Get().Open( "Testing", stMaths::Vec2i{ 640, 480 } );

    stGraphics::ApplicationWindow::Get().Close();
}
