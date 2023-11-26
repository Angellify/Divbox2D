#include "Player.h"
#include <iostream>

Player::~Player()
{
	delete(playerSprite);
}

void Player::Load()
{
	position = { -4.0f, 0.0f, 1.0f };
	size = { 128.0f, 128.0f };
	

	playerSprite = new Divbox2D::Sprite();
	playerSprite->LoadSprite("C:/Projects/Divbox2D/resources/Player.png", GL_RGBA);
}





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
	Divbox2D::Renderer::DrawQuad(position, size, playerSprite);
}

void Player::Update(int message)
{
	eventKey = message;
}
