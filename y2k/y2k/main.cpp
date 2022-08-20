#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

const int kScreenWidth = 400;
const int kScreenHeight = 300;


void framebuffer_size_callback(GLFWwindow* window,int width,int height)
{
    glViewport(0,0,width,height);
    printf("%d,%d\n",width,height);
}

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}


int main(int argc, const char * argv[])
{
    glfwInit();
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    
    GLFWwindow* window = glfwCreateWindow(kScreenWidth, kScreenHeight, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    
    
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    
    glfwSetFramebufferSizeCallback(window,framebuffer_size_callback);
    
    glViewport(0,0,kScreenWidth,kScreenHeight);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    
    while(!glfwWindowShouldClose(window))
    {
        processInput(window);
        
        // Render code here
        glClear(GL_COLOR_BUFFER_BIT);  // render begin
        
        // render end
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwTerminate();
    
    return 0;
}

