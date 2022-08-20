#pragma once

namespace ayy {

class Application
{
public:
    virtual ~Application() {}
    
    virtual void Initialize() = 0;
    virtual void Deinitialize() = 0;
    virtual void Update() = 0;
};

}

