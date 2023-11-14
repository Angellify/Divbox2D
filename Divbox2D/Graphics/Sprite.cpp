#include "Utils.h"
#include "Sprite.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <glad/glad.h>

namespace Divbox2D {

	Sprite::Sprite()
	{
		spriteID = 0;
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
		int width, height, nrChannels;

		stbi_set_flip_vertically_on_load(1);
		unsigned char* data = stbi_load(filepath, &width, &height, &nrChannels, 4);
		if (data)
		{

			glTexImage2D(GL_TEXTURE_2D, 0, type, width, height, 0, type, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);

		}
		else
		{
			if (stbi_failure_reason())

				std::cout << stbi_failure_reason() << '\n';
		}
		stbi_image_free(data);
	}


}

