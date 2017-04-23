#pragma once

#include "stGraphics/ApplicationWindow.h"
#include "stUtils/NonCopyable.h"

namespace Application {

class Application : stUtils::NonCopyable
{
public:
    static Application& Get();

public:
    bool Init();
    void Exit() { _window.Close(); }

    void RunLoop();

    bool ShouldExit() const { return _window.ShouldClose(); }

private:
    void Update();
    void Render();

private:
    Application() = default;

private:
    stGraphics::ApplicationWindow _window;
};

} //Application

