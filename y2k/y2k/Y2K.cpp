#include "Y2K.h"
#include <glad/glad.h>
#include "Scene.h"
#include "core/CoreUtils.h"

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
    SAFE_DEL(_scene);
}

void Y2K::Update()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    if(_scene != nullptr)
    {
        
    }
}

void Y2K::SetScene(Scene* scene)
{
    if(_scene != nullptr)
    {
        _scene->OnExit();
        SAFE_DEL(_scene);
    }
    _scene = scene;
    _scene->OnEnter();
}
