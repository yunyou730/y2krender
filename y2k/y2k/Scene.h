#pragma once


class Scene
{
public:
    virtual ~Scene() {}
    
    virtual void OnEnter() = 0;
    virtual void OnExit() = 0;
    virtual void OnUpdate() = 0;
    virtual void OnRender() = 0;
};


