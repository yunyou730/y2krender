#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class RenderEnv
{
public:
    RenderEnv(int width,int height);
    void Initialize();
    void Deinitialize();
    
    bool ShouldClose();
    
    void FrameBegin();
    void FrameEnd();
    
protected:
    int _width,_height;
    GLFWwindow* _window = nullptr;
};
