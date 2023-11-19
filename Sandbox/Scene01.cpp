#include "Scene01.h"
#include "Divbox2D.h"

void Scene01::Init()
{
    Divbox2D::Camera mainCamera;

    Divbox2D::Renderer::Init();
    Divbox2D::Renderer::shader.UploadUniformMat("world", mainCamera.GetViewMatrix());
    Divbox2D::Renderer::shader.UploadUniformMat("projection", mainCamera.GetProjectionMatrix());
    
    player.Load();  

    Divbox2D::Sprite mapTile; 
    mapTile.LoadSprite("C:/Projects/Divbox2D/resources/Tilemap.png", GL_RGBA);

    Divbox2D::Quad grassQuad = Divbox2D::Quad({ 2.0f, 0.0f }, { 48.0f, 48.0f }, mapTile);
    Divbox2D::Renderer::AddQuad(grassQuad);

}

void Scene01::Update() {
    player.Draw();
    player.Move();
}