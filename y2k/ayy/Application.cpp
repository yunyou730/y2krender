#include "Application.h"


ayy::Application*    g_app = nullptr;

namespace ayy {


Application::Application()
{
    g_app = this;
}

Application::~Application()
{
    g_app = nullptr;
}

}
