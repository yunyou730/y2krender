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
    FragColor = vec4(0.2,0.5,1.0,1.0);
}
)";



Showcase1::~Showcase1()
{
    Cleanup();
}

void Showcase1::OnEnter()
{
    PrepareVAO();
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
    
}

void Showcase1::PrepareVAO()
{
    
}

void Showcase1::PrepareShader()
{
    _program = new ayy::ShaderProgram();
    _program->Initilaize(vertexShaderSource, fragShaderSource);
}

void Showcase1::Cleanup()
{
    SAFE_DEL(_program);
}

