#include "ShaderProgram.h"
#include <iostream>

namespace ayy {

static const int kLogLength = 512;

ShaderProgram::ShaderProgram()
{
    
}

ShaderProgram::~ShaderProgram()
{
    Deinitialize();
}

bool ShaderProgram::Initilaize(const std::string& vertSource,const std::string& fragSource)
{
    GLuint vertShader = 0;
    GLuint fragShader = 0;
    
    char infoLog[kLogLength];
    if(!compileVert(vertShader,vertSource,infoLog))
    {
        return false;
    }
    if(!compileFrag(fragShader,fragSource,infoLog))
    {
        return false;
    }
    if(!linkProgram(vertShader,fragShader,infoLog))
    {
        return false;
    }
    
    return true;
}

void ShaderProgram::Deinitialize()
{
    if(_program > 0)
    {
        glDeleteProgram(_program);
        _program = 0;
    }
}

bool ShaderProgram::compileVert(GLuint& vertShader,const std::string& vertSource,char* infoLog)
{
    vertShader = glCreateShader(GL_VERTEX_SHADER);
    const char* vertContent = vertSource.c_str();
    glShaderSource(vertShader,1,&vertContent,nullptr);
    glCompileShader(vertShader);
    
    GLint success = GL_FALSE;
    glGetShaderiv(vertShader,GL_COMPILE_STATUS,&success);
    if(success != GL_TRUE)
    {
        glGetShaderInfoLog(vertShader,kLogLength,nullptr,infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;

        return false;
    }
    
    return true;
}

bool ShaderProgram::compileFrag(GLuint& fragShader,const std::string& fragSource,char* infoLog)
{
    fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    
    const char* shaderContent = fragSource.c_str();
    glShaderSource(fragShader,1,&shaderContent,nullptr);
    glCompileShader(fragShader);
    
    GLint success = GL_FALSE;
    glGetShaderiv(fragShader,GL_COMPILE_STATUS,&success);
    if(success != GL_TRUE)
    {
        glGetShaderInfoLog(fragShader,kLogLength,nullptr,infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;

        return false;
    }
    
    return true;
}

bool ShaderProgram::linkProgram(GLuint& vertShader,GLuint& fragShader,char* infoLog)
{
    _program = glCreateProgram();
    glAttachShader(_program,vertShader);
    glAttachShader(_program,fragShader);
    glLinkProgram(_program);
    
    GLint success = GL_FALSE;
    glGetProgramiv(_program,GL_LINK_STATUS,&success);
    if(success != GL_TRUE)
    {
        glGetProgramInfoLog(_program,kLogLength,nullptr,infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;

        return false;
    }
    
    glDeleteShader(vertShader);
    glDeleteShader(fragShader);
    vertShader = fragShader = 0;
    
    return true;
}

}

