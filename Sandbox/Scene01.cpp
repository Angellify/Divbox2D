#include "Scene01.h"
#include "Divbox2D.h"

void Scene01::Init()
{
    Divbox2D::Camera mainCamera;

    Divbox2D::Renderer::Init();
    Divbox2D::Renderer::shader.UploadUniformMat("world", mainCamera.GetViewMatrix());
    Divbox2D::Renderer::shader.UploadUniformMat("projection", mainCamera.GetProjectionMatrix());
    
    // Map
    for (int x = -4; x < 4; x++)
        for (int y = -4; y < 4; y++)
            Divbox2D::Renderer::AddQuad({ x, y }, { 48.0f, 48.0f });
    
    player.Load();  

}

void Scene01::Update() {
    player.Draw();
    player.Move();
}