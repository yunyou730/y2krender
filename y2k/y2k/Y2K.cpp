#include "Y2K.h"
#include <glad/glad.h>

Y2K::Y2K(int width,int height)
    :_width(width)
    ,_height(height)
{
    
}

Y2K::~Y2K()
{
    
}

void Y2K::Initialize()
{
    glViewport(0,0,_width,_height);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
}

void Y2K::Deinitialize()
{
    
}

void Y2K::Update()
{
    glClear(GL_COLOR_BUFFER_BIT);
}
