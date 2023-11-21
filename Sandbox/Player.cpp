#include "Player.h"
#include <iostream>

void Player::Load()
{
	playerQuad = new Divbox2D::Quad( {0.0f, 0.0f}, {100.0f, 100.0f});


	playerQuad->sprite.tileWidth = 32.0f;
	playerQuad->sprite.tileHeight = 32.0f;
	playerQuad->sprite.spriteHeight = 320.0f;
	playerQuad->sprite.spriteWidth = 320.0f;
	playerQuad->sprite.animationSpeed = 15.0f;
	playerQuad->sprite.animationUpdateTime = 1.0f / playerQuad->sprite.animationSpeed;


	Divbox2D::Renderer::AddQuad(playerQuad);
}



//bool CheckCollision(Divbox2D::Quad one, Divbox2D::Quad two) // AABB - AABB collision, not used anywhere right now
//{
//	bool collisionX = one.posX + one.width >= two.posX &&
//		two.posX + two.width >= one.posX;
//
//	bool collisionY = one.posY + one.height >= two.posY &&
//		two.posY + two.height >= one.posY;
//
//	return collisionX && collisionY;
//
//}

void Player::Move()
{
	double deltaTime = Divbox2D::Timetrack::Get()->deltaTime;
		std::cout << "Moving";
	if (eventKey == (char)'W')
	{
		playerQuad->sprite.y = 7;
		playerQuad->position.y += 1 * deltaTime;
	}
	if (eventKey == (char)'S')
		playerQuad->position.y -= 1 * deltaTime;
	if (eventKey == (char)'A')
		playerQuad->position.x -= 1 * deltaTime;
	if (eventKey == (char)'D')
		playerQuad->position.x += 1 * deltaTime;

}

void Player::Update(int message)
{
	//std::cout << "Player pressed: " << (char)message << '\n';
	eventKey = message;
}
