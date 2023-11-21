#include "Utils.h"
#include "VertexBuffer.h"
#include <glad/glad.h>
#include <cstdint>

namespace Divbox2D {

	int x = 0;
	int y = 9;
	int spriteWidth = 320;
	int spriteHeight = 320;
	float tileWidth = 32.0f;
	float tileHeight = 32.0f;

	int indices[] =
	{
		0, 1, 3,
		2, 1, 3
	};


	float vertices[] = {

		// positions          // colors           // texture coords
		-0.5f,  0.5f, 1.0f, 1.0f, 0.0f,   (x * tileWidth) / spriteWidth, ((y + 1) * tileHeight) / spriteHeight,   // top left 
		 0.5f,  0.5f, 1.0f, 0.0f, 0.0f,   ((x + 1) * tileWidth) / spriteWidth, ((y + 1) * tileHeight) / spriteHeight,  // top right
		 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,   ((x + 1) * tileWidth) / spriteWidth, (y * tileHeight) / spriteHeight,  // bottom right
		-0.5f, -0.5f, 0.0f, 0.0f, 1.0f,   (x * tileWidth) / spriteWidth, (y * tileHeight) / spriteHeight,  // bottom left
	};


	VertexBuffer::VertexBuffer()
	{
		glGenBuffers(1, &vertexBufferID);
		glGenBuffers(1, &indexBufferID);
	}


	void VertexBuffer::Create()
	{
		glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	}

	void VertexBuffer::Delete()
	{
		glDeleteBuffers(1, &vertexBufferID);
		glDeleteBuffers(1, &indexBufferID);

	}



	void VertexBuffer::Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);
	}


	void VertexBuffer::Unbind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	unsigned __int32 VertexBuffer::GetVertexBufferID()
	{
		return vertexBufferID;
	}

	unsigned __int32 VertexBuffer::GetIndexBufferID()
	{
		return indexBufferID;
	}

}