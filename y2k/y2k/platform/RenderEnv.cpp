#include "RenderEnv.h"

#include <iostream>

static void framebuffer_size_callback(GLFWwindow* window,int width,int height)
{
    glViewport(0,0,width,height);
    printf("%d,%d\n",width,height);
}

static void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

RenderEnv::RenderEnv(int width,int height)
    :_width(width)
    ,_height(height)
{
    
}

void RenderEnv::Initialize()
{
    glfwInit();
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    
    _window = glfwCreateWindow(_width, _height, "LearnOpenGL", NULL, NULL);
    if (_window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }
    
    
    glfwMakeContextCurrent(_window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return;
    }
    
    glfwSetFramebufferSizeCallback(_window,framebuffer_size_callback);
    
}

void RenderEnv::Deinitialize()
{
    
}

bool RenderEnv::ShouldClose()
{
    return glfwWindowShouldClose(_window);
}

void RenderEnv::FrameBegin()
{
    processInput(_window);
}

void RenderEnv::FrameEnd()
{
    glfwSwapBuffers(_window);
    glfwPollEvents();
}

