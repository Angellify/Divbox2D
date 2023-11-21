#pragma once
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "Sprite.h"

#include <glm/glm.hpp>

namespace Divbox2D {

	struct Animation
	{
		int frames;
		int x, y;

	};

	class Quad {

	private:
		glm::vec2 size;

		VertexArray vertexArray;
		VertexBuffer vertexBuffer;



		Animation idleAnim;
	public:
		Sprite sprite;
		glm::vec2 position;
		glm::mat4 transform = glm::mat4(1.0f);

		VertexArray GetVertexArray();
		VertexBuffer GetVertexBuffer();
		Quad();
		Quad(glm::vec2 _position, glm::vec2 _size);
		~Quad();
		void Draw();
		void Modify();
	};
}