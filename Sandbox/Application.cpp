#include "Application.h"
#include "Scene01.h"
#include "Player.h"

void Application::Init()
{
    Divbox2D::Scene* scene01 = new Scene01();
    PushScene(scene01);
}

int main(void)
{
    Application Prototype01;
    Prototype01.Run();
    Prototype01.Init();
    Prototype01.Update();
}