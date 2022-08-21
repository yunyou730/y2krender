#pragma once

#include "scene_management/Scene.h"
#include <glad/glad.h>

/*
 Shader source code from asset file;
 Add aColor attribute for each vertex
*/
namespace ayy {
class ShaderProgram;
}
class Showcase2 : public Scene
{
public:
    virtual ~Showcase2();
    
    virtual void OnEnter() override;
    virtual void OnExit() override;
    virtual void OnUpdate() override;
    virtual void OnRender() override;
    
protected:
    void PrepareVAO(GLuint& VAO,GLuint& VBO);
    void PrepareShader();
    void Cleanup();
    
protected:
    GLuint _vao = 0;
    GLuint _vbo = 0;
    GLuint _ebo = 0;
    
    ayy::ShaderProgram*  _program = nullptr;
    
};

