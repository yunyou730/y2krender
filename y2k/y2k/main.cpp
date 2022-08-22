#include "RenderEnv.h"
#include "Y2K.h"
#include "platform/PlatformMac.h"

#include "showcase/Showcase1.h"
#include "showcase/Showcase2.h"
#include "showcase/Showcase3.h"

const int kScreenWidth = 400;
const int kScreenHeight = 400;

int main(int argc, const char * argv[])
{    
    RenderEnv env(kScreenWidth,kScreenHeight);
    env.Initialize();
    
    PlatformMac platform;
    platform.Initialize();
    
    Y2K app(kScreenWidth,kScreenHeight,&platform);
    app.Initialize();
    
    Scene* showcase = new Showcase3();
    app.SetScene(showcase);
    
    double prevTime = platform.GetCurrentTimeStamp();
    while(!env.ShouldClose())
    {
        double currentTime = platform.GetCurrentTimeStamp();
        float deltaTime = currentTime - prevTime;
        prevTime = currentTime;
        app.SetDeltaTime(deltaTime);
        
        env.FrameBegin();
        app.Update();
        env.FrameEnd();
    }
    
    app.Deinitialize();
    env.Deinitialize();
    platform.Deinitialize();
    
    return 0;
}

