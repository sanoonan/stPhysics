#pragma once

#include "stUtils/NonCopyable.h"

namespace stGraphics {

class Renderer : stUtils::NonCopyable
{
public:
    static Renderer& Get();

    bool Init();

private:
    Renderer() = default;

private:
    bool _isInited{ false };
};

} //stGraphics
