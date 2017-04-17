#include "EventHandler.h"

#include "stGraphics/GLFWInclude.h"

namespace stEvents {

void EventHandler::PollEvents()
{
    glfwPollEvents();
}

} //stEvents
