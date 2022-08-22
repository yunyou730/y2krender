#include "PlatformMac.h"
#include <GLFW/glfw3.h>

void PlatformMac::Initialize()
{
    
}

void PlatformMac::Deinitialize()
{
    
}

std::string PlatformMac::GetResRootDirectory()
{
    return "";
}

double PlatformMac::GetCurrentTimeStamp() const
{
    return glfwGetTime();
}
