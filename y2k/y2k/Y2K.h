#include "../ayy/Application.h"

class Scene;
class Y2K : public ayy::Application
{
public:
    Y2K(int width,int height);
    virtual ~Y2K();
    
    virtual void Initialize() override;
    virtual void Deinitialize() override;
    virtual void Update() override;
    
    void SetScene(Scene* scene);
    
protected:
    int     _width = 0;
    int     _height = 0;
    Scene*  _scene = nullptr;
    
};

