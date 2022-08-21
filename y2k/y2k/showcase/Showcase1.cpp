#include "Showcase1.h"
#include "resources/ShaderProgram.h"
#include "core/CoreUtils.h"

static const char* vertexShaderSource = R"(
#version 330 core
layout (location = 0) in vec3 aPos;
void main()
{
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
}
)";



static const char* fragShaderSource = R"(
#version 330 core
out vec4 FragColor;
void main()
{
    FragColor = vec4(1.0,0.5,0.2,1.0);
}
)";



Showcase1::~Showcase1()
{
    Cleanup();
}

void Showcase1::OnEnter()
{
    PrepareVAO(_vao,_vbo);
    PrepareShader();
}

void Showcase1::OnExit()
{
    
}

void Showcase1::OnUpdate()
{
    
}

void Showcase1::OnRender()
{
    glUseProgram(_program->GetProgram());
    glBindVertexArray(_vao);
    glDrawArrays(GL_TRIANGLES,0,3);
}

void Showcase1::PrepareVAO(GLuint& VAO,GLuint& VBO)
{
    // NDC xyz [-1,1]
    float vertices[] = {
      -0.5f,-0.5f,0.0f,    // left
       0.5f,-0.5f,0.0f,    // right
       0.0f, 0.5f,0.0f,    // top
    };
     
    glGenVertexArrays(1,&VAO);
    glGenBuffers(1,&VBO);
     
    glBindVertexArray(VAO);
    {
      glBindBuffer(GL_ARRAY_BUFFER,VBO);
      {
        glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
        glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3 * sizeof(float),(void*)0);
        glEnableVertexAttribArray(0);
      }
      // unbind VBO
      glBindBuffer(GL_ARRAY_BUFFER,0);
    }
    // unbind VAO
    glBindVertexArray(0);
}

void Showcase1::PrepareShader()
{
    _program = new ayy::ShaderProgram();
    _program->Initilaize(vertexShaderSource, fragShaderSource);
}

void Showcase1::Cleanup()
{
    glDeleteVertexArrays(1,&_vao);
    glDeleteBuffers(1,&_vbo);
    _vao = 0;
    _vbo = 0;
    SAFE_DEL(_program);
}

