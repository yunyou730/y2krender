#pragma once

#include "scene_management/Scene.h"
#include <glad/glad.h>

/*
 Display with VAO & VBO
 */

namespace ayy {
class ShaderProgram;
}
class Showcase1 : public Scene
{
public:
    virtual ~Showcase1();
    
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

