#pragma once

#include <string>

namespace ayy {

class Platform
{
public:
    virtual void Initialize() = 0;
    virtual void Deinitialize() = 0;
    
    virtual std::string GetResRootDirectory() = 0;
};

}
