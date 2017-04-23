#include "Application.h"

#include "stUtils/ErrorHandling.h"

int main ()
{
    using Application::Application;

    ST_Ensure( Application::Get().Init() );

    while( !Application::Get().ShouldExit() )
    {
        Application::Get().RunLoop();
    }

    Application::Get().Exit();

    return 0;
ST_ExitWithError:
    return -1;
}
