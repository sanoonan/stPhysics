#pragma once

#include "stContainers/RingBuffer.h"

namespace stUtils {

class FrameRateCounter
{
public:
    void Update();

    float GetFrameDurationMS() const;
    float GetFrameRate() const;

private:
    float _lastFrameTimeMS{ 0 };

    static const int NUM_DURATIONS{ 15 };
    stContainers::RingBuffer< float, NUM_DURATIONS > _frameDurationsMS;
};

} //stUtils

