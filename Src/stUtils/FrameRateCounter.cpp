#include "FrameRateCounter.h"

#include "stGraphics/GLFWInclude.h"
#include "stUtils/Assertions.h"

namespace stUtils {

void FrameRateCounter::Update()
{
    float currentTime = ( float )( glfwGetTime() * 1000 );

    float duration = currentTime - _lastFrameTimeMS;
    ST_Assert( duration >= 0.0f );
    _frameDurationsMS.PushBack( duration );

    _lastFrameTimeMS = currentTime;
}

float FrameRateCounter::GetFrameDurationMS() const
{
    if( _frameDurationsMS.Size() <= 0 )
        return 0.0f;

    float totalDuration{ 0.0f };
    for( const float duration : _frameDurationsMS )
    {
        totalDuration += duration;
    }

    return totalDuration /= _frameDurationsMS.Size();
}

float FrameRateCounter::GetFrameRate() const
{
    float frameDuration = GetFrameDurationMS();
    if( frameDuration <= 0 )
        return 0.0f;

    return 1.0f / ( frameDuration * 0.001f );
}


} //stUtils
