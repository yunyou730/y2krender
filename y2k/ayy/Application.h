#pragma once

namespace ayy {

class Platform;
class Application
{
public:
    virtual ~Application() {}
    
    virtual void Initialize() = 0;
    virtual void Deinitialize() = 0;
    virtual void Update() = 0;
    
    
    virtual Platform* GetPlatform() = 0;
    
    virtual void SetDeltaTime(float deltaTime) = 0;
    virtual float GetDeltaTime() = 0;
};

}

