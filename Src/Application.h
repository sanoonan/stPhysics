#pragma once

#include "stGraphics/ApplicationWindow.h"
#include "stUtils/FrameRateCounter.h"
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

    void UpdateFrameRateCounter();

private:
    Application() = default;

private:
    stGraphics::ApplicationWindow _window;

    stUtils::FrameRateCounter _frameRateCounter;
};

} //Application

