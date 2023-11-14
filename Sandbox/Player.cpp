#include "Player.h"

// Animation speed controls
double animationSpeed = 15.0f;
double animationUpdateTime = 1.0f / animationSpeed;
double timeSinceLastFrameSwap = 0.0f;
bool active = true;
bool moving = false;


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
	playerQuad.CreateQuad();

	playerQuad.posX = 0.0f;
	playerQuad.posY = 0.0f;

	playerQuad.width = 128.0f;
	playerQuad.height = 128.0f;
	playerQuad.sprite.LoadSprite("C:/Projects/Divbox2D/resources/orc.png", GL_RGBA);
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

	timeSinceLastFrameSwap += deltaTime;
	if (timeSinceLastFrameSwap > animationUpdateTime) {
		x++;
		timeSinceLastFrameSwap = 0.0f;
	}

	if (x >= 10) {
		x = 0;
	}

	playerQuad.GetVertexArray().Bind();
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(anim), anim);

	glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(playerQuad.width, playerQuad.height, 0.0f));
	glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(playerQuad.posX, playerQuad.posY, 0.0f));
	transform = scale * model;

	Divbox2D::Renderer::shader.UploadUniformMat("model", transform);
	glBindTexture(GL_TEXTURE_2D, playerQuad.sprite.spriteID);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

}

bool CheckCollision(Divbox2D::Quad one, Divbox2D::Quad two) // AABB - AABB collision, not used anywhere right now
{
	bool collisionX = one.posX + one.width >= two.posX &&
		two.posX + two.width >= one.posX;

	bool collisionY = one.posY + one.height >= two.posY &&
		two.posY + two.height >= one.posY;

	return collisionX && collisionY;

}

void Player::Move()
{
	y = 9;
	double deltaTime = Divbox2D::Timetrack::Get()->deltaTime;
	if (Divbox2D::Input::Get()->Update() == 'W')
	{

		y = 7;
		playerQuad.posY += 1.0f * deltaTime;

	}

	if (Divbox2D::Input::Get()->Update() == 'S')
	{
		playerQuad.posY -= 1.0f * deltaTime;

		y = 7;
	}

	if (Divbox2D::Input::Get()->Update() == 'D')
	{
		playerQuad.posX += 1.0f * deltaTime;

		y = 7;
	}

	if (Divbox2D::Input::Get()->Update() == 'A')
	{
		playerQuad.posX -= 1.0f * deltaTime;

		y = 7;
	}

}

Divbox2D::Quad Player::GetQuad()
{
	return playerQuad;
}
