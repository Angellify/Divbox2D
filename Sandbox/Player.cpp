#include "Player.h"
#include <iostream>

void Player::Load()
{
	position = { 0.0f, 0.0f };
	size = { 128.0f, 128.0f };



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

	if (eventKey == (char)'W')
		position.y += 1.0f * deltaTime;
	if (eventKey == (char)'S')
		position.y -= 1.0f * deltaTime;
	if (eventKey == (char)'A')
		position.x -= 1.0f * deltaTime;
	if (eventKey == (char)'D')
		position.x += 1.0f * deltaTime;

}

void Player::Draw()
{
	Divbox2D::Renderer::DrawQuad(position, { size.x, size.y });
}

void Player::Update(int message)
{
	eventKey = message;
}
