#include "stGraphics/ApplicationWindow.h"
#include "stTypes/Vec2.h"

int main ()
{
    stGraphics::ApplicationWindow::Get().Open( "Testing", stTypes::Vec2{ 640, 480 } );

    stGraphics::ApplicationWindow::Get().Close();
}
