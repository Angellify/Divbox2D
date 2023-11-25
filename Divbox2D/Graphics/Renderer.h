#pragma once
#include "Shader.h"
#include "Sprite.h"
#include "Quad.h"
#include <vector>

namespace Divbox2D {

	class Renderer{
	public:
		static Shader shader;

		static void Init();
		static void Shutdown();
		static void DrawQuad(glm::vec2 _position, glm::vec2 _size);

	};

}