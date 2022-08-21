#include "Showcase2.h"
#include "resources/ShaderProgram.h"
#include "core/CoreUtils.h"
#include "core/IO.h"


Showcase2::~Showcase2()
{
    Cleanup();
}

void Showcase2::OnEnter()
{
    PrepareVAO(_vao,_vbo);
    PrepareShader();
}

void Showcase2::OnExit()
{
    
}

void Showcase2::OnUpdate()
{
    
}

void Showcase2::OnRender()
{
    glUseProgram(_program->GetProgram());
    glBindVertexArray(_vao);
    glDrawArrays(GL_TRIANGLES,0,3);
}

void Showcase2::PrepareVAO(GLuint& VAO,GLuint& VBO)
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

void Showcase2::PrepareShader()
{
    _program = new ayy::ShaderProgram();
    
    std::string vertSource,fragSource;
    ayy::IO::ReadFile("assets/showcase2/test.vsh", vertSource);
    ayy::IO::ReadFile("assets/showcase2/test.fsh", fragSource);
    
    _program->Initilaize(vertSource, fragSource);
}

void Showcase2::Cleanup()
{
    glDeleteVertexArrays(1,&_vao);
    glDeleteBuffers(1,&_vbo);
    _vao = 0;
    _vbo = 0;
    SAFE_DEL(_program);
}

