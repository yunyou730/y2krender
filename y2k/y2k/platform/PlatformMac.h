#pragma once

#include "platform/Platform.h"

class PlatformMac : public ayy::Platform
{
public:
    virtual void Initialize() override;
    virtual void Deinitialize() override;
    
    virtual std::string GetResRootDirectory() override;
    
    double GetCurrentTimeStamp() const;
};
