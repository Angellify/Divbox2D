#pragma once
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "Sprite.h"

#include <glm/glm.hpp>

namespace Divbox2D {

	class Quad {
	private:
		Sprite sprite;
		glm::vec2 size;
		glm::vec2 position;
		glm::mat4 transform = glm::mat4(1.0f);

		VertexArray vertexArray;
		VertexBuffer vertexBuffer;
	public:

		VertexArray GetVertexArray();
		VertexBuffer GetVertexBuffer();
		Quad();
		Quad(glm::vec2 _position, glm::vec2 _size, Sprite _sprite);
		void Draw();

	};
}