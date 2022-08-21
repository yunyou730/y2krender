#pragma once

#include <glad/glad.h>
#include <string>

namespace ayy {

class ShaderProgram
{
public:
    ShaderProgram();
    ~ShaderProgram();
    
    bool Initilaize(const std::string& vertSource,const std::string& fragSource);
    void Deinitialize();
    
protected:
    bool compileVert(GLuint& vertShader,const std::string& vertSource,char* infoLog);
    bool compileFrag(GLuint& fragShader,const std::string& fragSource,char* infoLog);
    bool linkProgram(GLuint& vertShader,GLuint& fragShader,char* infoLog);
    
protected:
    GLuint  _program = 0;
};

}
