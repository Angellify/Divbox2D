#include "Scene01.h"
#include "Divbox2D.h"

void Scene01::Init()
{
    Divbox2D::Camera mainCamera;

    Divbox2D::Renderer::Init();
    Divbox2D::Renderer::shader.UploadUniformMat("world", mainCamera.GetViewMatrix());
    Divbox2D::Renderer::shader.UploadUniformMat("projection", mainCamera.GetProjectionMatrix());

    
    Divbox2D::Quad* test = new Divbox2D::Quad({ 0.0f, 0.0f }, { 48.0f, 48.0f });
    Divbox2D::Renderer::AddQuad(test);

    player.Load();


}

void Scene01::Update() {
    player.Move();
}