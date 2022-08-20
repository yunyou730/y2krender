#include "RenderEnv.h"
#include "Y2K.h"
#include "platform/PlatformMac.h"

const int kScreenWidth = 400;
const int kScreenHeight = 300;

int main(int argc, const char * argv[])
{
    RenderEnv env(kScreenWidth,kScreenHeight);
    env.Initialize();
    
    PlatformMac platform;
    platform.Initialize();
    
    Y2K app(kScreenWidth,kScreenHeight,&platform);
    app.Initialize();
    
    while(!env.ShouldClose())
    {
        env.FrameBegin();
        app.Update();
        env.FrameEnd();
    }
    
    app.Deinitialize();
    env.Deinitialize();
    platform.Deinitialize();
    
    return 0;
}

