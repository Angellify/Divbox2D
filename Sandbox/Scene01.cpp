#include "Scene01.h"
#include "Divbox2D.h"

void Scene01::Init()
{
	Divbox2D::Camera mainCamera;

	Divbox2D::Renderer::Init();
	Divbox2D::Renderer::shader.UploadUniformMat("world", mainCamera.GetViewMatrix());
	Divbox2D::Renderer::shader.UploadUniformMat("projection", mainCamera.GetProjectionMatrix());

	player.Load();


}

void Scene01::Update()
{
	Divbox2D::Renderer::DrawQuad({ 2.0f, 0.0f }, { 100.f, 100.f });
	player.Move();
	player.Draw();


}
