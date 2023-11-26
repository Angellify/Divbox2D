#include "Scene01.h"
#include "Divbox2D.h"

Divbox2D::Sprite* enemySprite;
Divbox2D::Sprite* grassSprite;
Divbox2D::Sprite* checkpointSprite;

glm::vec2 size = { 128.0f, 128.0f };
glm::vec2 checkpointPosition = { 4.0f, 0.0f };

float enemyDirection = 1.0f;
float enemySpeed = 2.0f;
glm::vec2 enemyPosition = { -2.0f, 0.0f };
glm::vec2 enemyPosition2 = { 2.0f, 0.0f };



void Scene01::Init()
{
	Divbox2D::Camera mainCamera;

	Divbox2D::Renderer::Init();
	Divbox2D::Renderer::shader.UploadUniformMat("world", mainCamera.GetViewMatrix());
	Divbox2D::Renderer::shader.UploadUniformMat("projection", mainCamera.GetProjectionMatrix());

	player.Load();

	grassSprite = new Divbox2D::Sprite();
	enemySprite = new Divbox2D::Sprite();
	checkpointSprite = new Divbox2D::Sprite();

	checkpointSprite->LoadSprite("C:/Projects/Divbox2D/resources/Checkpoint.png", GL_RGBA);
	grassSprite->LoadSprite("C:/Projects/Divbox2D/resources/Grass.png", GL_RGBA);
	enemySprite->LoadSprite("C:/Projects/Divbox2D/resources/Enemy.png", GL_RGBA);


}

bool CheckCollision(glm::vec2 _objAPos, glm::vec2 _objASize, glm::vec2 _objBPos, glm::vec2 _objBSize) // AABB - AABB collision
{
	bool collisionX = _objAPos.x + _objASize.x >= _objBPos.x &&
		_objBPos.x + _objBSize.x >= _objAPos.x;

	bool collisionY = _objAPos.y + _objASize.y >= _objBPos.y &&
		_objBPos.y + _objBSize.y >= _objAPos.y;

	return collisionX && collisionY;

}



void Scene01::Update()
{

	double deltaTime = Divbox2D::Timetrack::Get()->GetDeltaTime();

	player.Move();
	player.Draw();
	

	if (enemyPosition.y <= -4.0f || enemyPosition.y >= 4.0f)
	{
		enemyDirection = enemyDirection * -1.0f;
	}
	enemyPosition.y +=  enemyDirection * enemySpeed *  deltaTime;

	// Enemy

	Divbox2D::Renderer::DrawQuad({ enemyPosition.x, enemyPosition.y, 0.1f }, size, enemySprite);
	Divbox2D::Renderer::DrawQuad({ enemyPosition2.x, enemyPosition2.y, 0.1f }, size, enemySprite);



	// Checkpoint
	Divbox2D::Renderer::DrawQuad({ checkpointPosition.x, checkpointPosition.y, -0.5f }, size, checkpointSprite);

	// Map
	if (!CheckCollision(player.position, { 1.0f, 1.0f }, checkpointPosition, { 1.0f, 1.0f }))
	{
		for (int x = -4; x < 4; x++)
			for (int y = -4; y < 4; y++)
				Divbox2D::Renderer::DrawQuad({ x, y, -0.1f }, { 512.0f, 512.0f }, grassSprite);
	}




	if (CheckCollision(player.position, { 1.0f, 1.0f }, enemyPosition, { 1.0f, 1.0f }))
		player.position = { -4.0f, 0.0f, 1.0f };



}

void Scene01::Clean()
{
	delete(checkpointSprite);
	delete(grassSprite);
	delete(enemySprite);
	Divbox2D::Renderer::Shutdown();
}
