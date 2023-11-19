#include "Player.h"
#include <iostream>
// Animation speed controls



// How the texture gets selected. This shouldn't be here but it's a quick work around, will decouple in the future.
float x = 0;
int y = 9;
int spriteWidth = 320;
int spriteHeight = 320;
float tileWidth = 32.0f;
float tileHeight = 32.0f;

float vertices[] = {
	// positions          // colors           // texture coords
	-0.5f,  0.5f, 1.0f, 1.0f, 0.0f,   (x * tileWidth) / spriteWidth, ((y + 1) * tileHeight) / spriteHeight,   // top left 
	 0.5f,  0.5f, 1.0f, 0.0f, 0.0f,   ((x + 1) * tileWidth) / spriteWidth, ((y + 1) * tileHeight) / spriteHeight,  // top right
	 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,   ((x + 1) * tileWidth) / spriteWidth, (y * tileHeight) / spriteHeight,  // bottom right
	-0.5f, -0.5f, 0.0f, 0.0f, 1.0f,   (x * tileWidth) / spriteWidth, (y * tileHeight) / spriteHeight,  // bottom left
};


void Player::Load()
{
	playerSprite.LoadSprite("C:/Projects/Divbox2D/resources/orc.png", GL_RGBA);
	playerSprite.animationSpeed = 15.0f;
	playerSprite.animationUpdateTime = 1.0f / playerSprite.animationSpeed;
	playerQuad = Divbox2D::Quad( {0.0f, 0.0f}, {48.0f, 48.0f}, playerSprite);


}

void Player::Draw()
{
	double deltaTime = Divbox2D::Timetrack::Get()->deltaTime;


	float anim[] = {
		// positions          // colors           // texture coords
		-0.5f,  0.5f, 1.0f, 1.0f, 0.0f,   (x * tileWidth) / spriteWidth, ((y + 1) * tileHeight) / spriteHeight,   // top left 
		 0.5f,  0.5f, 1.0f, 0.0f, 0.0f,   ((x + 1) * tileWidth) / spriteWidth, ((y + 1) * tileHeight) / spriteHeight,  // top right
		 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,   ((x + 1) * tileWidth) / spriteWidth, (y * tileHeight) / spriteHeight,  // bottom right
		-0.5f, -0.5f, 0.0f, 0.0f, 1.0f,   (x * tileWidth) / spriteWidth, (y * tileHeight) / spriteHeight,  // bottom left
	};

	playerSprite.timeSinceLastFrameSwap += deltaTime;
	if (playerSprite.timeSinceLastFrameSwap > playerSprite.animationUpdateTime) {
		x++;
		playerSprite.timeSinceLastFrameSwap = 0.0f;
	}

	if (x >= 10) {
		x = 0;
	}

	playerQuad.Draw();
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
	y = 9;
	double deltaTime = Divbox2D::Timetrack::Get()->deltaTime;



}


void Player::Update(int message)
{
	//std::cout << "Player pressed: " << (char)message << '\n';
	eventKey = message;
}
