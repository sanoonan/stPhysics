#include <stGraphics/Renderer.h>
#include <stFiles/InputStream.h>
#include <stContainers/String.h>
#include <stUtils/Log.h>
#include <stEvents/EventHandler.h>
#include "stGraphics/ApplicationWindow.h"
#include "stGraphics/Material.h"
#include "stGraphics/Tri.h"
#include "stMaths/Vec2.h"

int main ()
{
    using stGraphics::ApplicationWindow;

    ApplicationWindow::Get().Open( "Testing", stMaths::Vec2i{ 640, 480 } );

    stGraphics::Renderer::Get().Init();

    stGraphics::Tri testTri{
        stMaths::Vec3{ 0.0f, 0.5f, 0.0f },
        stMaths::Vec3{ 0.5f, -0.5f, 0.0f },
        stMaths::Vec3{ -0.5f, -0.5f, 0.0f } };

    stGraphics::Material testMaterial;
    testMaterial.Load( "../../Assets/Shaders/sample.vert", "../../Assets/Shaders/sample.frag" );

    while( !ApplicationWindow::Get().ShouldClose() )
    {
        stEvents::EventHandler::PollEvents();

        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

        testTri.Render( testMaterial );

        ApplicationWindow::Get().SwapBuffers();
    }

    ApplicationWindow::Get().Close();

    return 0;
}
