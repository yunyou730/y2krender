#include "RenderEnv.h"
#include "Y2K.h"

const int kScreenWidth = 400;
const int kScreenHeight = 300;



int main(int argc, const char * argv[])
{
    RenderEnv env(kScreenWidth,kScreenHeight);
    env.Initialize();
    
    Y2K  app(kScreenWidth,kScreenHeight);
    app.Initialize();
    
    while(!env.ShouldClose())
    {
        env.FrameBegin();
        app.Update();
        env.FrameEnd();
    }
    
    app.Deinitialize();
    env.Deinitialize();
    
    return 0;
}

