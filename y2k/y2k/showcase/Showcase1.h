#pragma once

#include "scene_management/Scene.h"

/*
 Display with VAO & VBO
 */
class Showcase1 : public Scene
{
public:
    virtual ~Showcase1();
    
    virtual void OnEnter() override;
    virtual void OnExit() override;
    virtual void OnUpdate() override;
    virtual void OnRender() override;
    
protected:
    
};

