#include "Showcase3.h"
#include "resources/ShaderProgram.h"
#include "core/CoreUtils.h"
#include "core/IO.h"

#include "Application.h"

extern ayy::Application* g_app;

Showcase3::~Showcase3()
{
    Cleanup();
}

void Showcase3::OnEnter()
{
    PrepareVAO(_vao,_vbo);
    PrepareShader();
}

void Showcase3::OnExit()
{
    
}

void Showcase3::OnUpdate()
{
    _transform.SetRot(glm::vec3(0.0,1.0,0.0), _transform.GetRotDeg() + 100.0f * g_app->GetDeltaTime());
}

void Showcase3::OnRender()
{
    glUseProgram(_program->GetProgram());
    
    GLuint transLoc = glGetUniformLocation(_program->GetProgram(),"u_Transform");
    glUniformMatrix4fv(transLoc,1,GL_FALSE,glm::value_ptr(_transform.CalcTransformMatrix()));
    
    glBindVertexArray(_vao);
    glDrawArrays(GL_TRIANGLES,0,3);
}

void Showcase3::PrepareVAO(GLuint& VAO,GLuint& VBO)
{
    // NDC xyz [-1,1]
    float vertices[] = {
        
        // pos, color
      -0.5f,-0.5f,0.0f,    // left
       1.0f, 0.0f,0.0f,     // red
        
       0.5f,-0.5f,0.0f,    // right
       0.0f, 1.0f,0.0f,     // green
        
       0.0f, 0.5f, 0.0f,    // top
       0.0f, 0.0f, 1.0f,    // blue
    };
     
    glGenVertexArrays(1,&VAO);
    glGenBuffers(1,&VBO);
     
    glBindVertexArray(VAO);
    {
      glBindBuffer(GL_ARRAY_BUFFER,VBO);
      {
          glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
          
          // attribute 0, pos
          glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,6 * sizeof(float),(void*)0);
          glEnableVertexAttribArray(0);
          
          // attribute 1, color
          glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,6 * sizeof(float),(void*)(3 * sizeof(float)));
          glEnableVertexAttribArray(1);
          
      }
      // unbind VBO
      glBindBuffer(GL_ARRAY_BUFFER,0);
    }
    // unbind VAO
    glBindVertexArray(0);
}

void Showcase3::PrepareShader()
{
    _program = new ayy::ShaderProgram();
    
    std::string vertSource,fragSource;
    ayy::IO::ReadFile("assets/showcase3/test.vsh", vertSource);
    ayy::IO::ReadFile("assets/showcase3/test.fsh", fragSource);
    
    _program->Initilaize(vertSource, fragSource);
}

void Showcase3::Cleanup()
{
    glDeleteVertexArrays(1,&_vao);
    glDeleteBuffers(1,&_vbo);
    _vao = 0;
    _vbo = 0;
    SAFE_DEL(_program);
}

