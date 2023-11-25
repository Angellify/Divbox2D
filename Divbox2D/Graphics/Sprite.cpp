#include "Utils.h"
#include "Sprite.h"
#include "Timetrack.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <glad/glad.h>

namespace Divbox2D {

	Sprite::Sprite()
	{
		spriteWidth = 0;
		spriteHeight = 0;
	}

	void Sprite::LoadSprite(const char* filepath, unsigned int type)
	{

		glGenTextures(1, &spriteID);
		glBindTexture(GL_TEXTURE_2D, spriteID); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
		// set the texture wrapping parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		// set texture filtering parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		// load image, create texture and generate mipmaps
		int nrChannels;

		stbi_set_flip_vertically_on_load(1);
		unsigned char* data = stbi_load(filepath, &spriteWidth, &spriteHeight, &nrChannels, 4);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, type, spriteWidth, spriteHeight, 0, type, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);

		}
		else
		{
			if (stbi_failure_reason())

				std::cout << stbi_failure_reason() << '\n';
		}
		stbi_image_free(data);
	}



	void Sprite::Play()
	{


		float vertices[] = {

			// positions          // colors           // texture coords
			-0.5f,  0.5f, 1.0f, 1.0f, 0.0f,   (x * tileWidth) / spriteWidth, ((y + 1) * tileHeight) / spriteHeight,   // top left 
			 0.5f,  0.5f, 1.0f, 0.0f, 0.0f,   ((x + 1) * tileWidth) / spriteWidth, ((y + 1) * tileHeight) / spriteHeight,  // top right
			 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,   ((x + 1) * tileWidth) / spriteWidth, (y * tileHeight) / spriteHeight,  // bottom right
			-0.5f, -0.5f, 0.0f, 0.0f, 1.0f,   (x * tileWidth) / spriteWidth, (y * tileHeight) / spriteHeight,  // bottom left
		};

		double deltaTime = Timetrack::Get()->deltaTime;
		timeSinceLastFrameSwap += deltaTime;

		if (timeSinceLastFrameSwap > animationUpdateTime) {
			x++;
			timeSinceLastFrameSwap = 0.0f;
		}
		if (x > 10)
			x = 0;

		parentVertexID.Bind();
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
		parentVertexID.Unbind();



	}

	Sprite::~Sprite()
	{
		glDeleteTextures(1, &spriteID);
	}


}

