#pragma once
#include "scene_management/Scene.h"
#include <glad/glad.h>


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "scene_management/component/TransformComponent.h"

/*
Transform with GLM and matrix
*/
namespace ayy {
class ShaderProgram;
}
class Showcase3 : public Scene
{
public:
    virtual ~Showcase3();
    
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
    TransformComponent _transform;
};

