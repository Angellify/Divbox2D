#pragma once
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "Sprite.h"

#include <glm/glm.hpp>

namespace Divbox2D {

	class Quad {
	private:
		VertexArray vertexArray;
		VertexBuffer vertexBuffer;
	public:
		double posX;
		double posY;
		float height;
		float width;

		VertexArray GetVertexArray();
		VertexBuffer GetVertexBuffer();

		Sprite sprite;
		glm::mat4 transform = glm::mat4(1.0f);

		void Draw();
		void CreateQuad();

	};
}