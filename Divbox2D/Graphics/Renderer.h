#pragma once
#include "Shader.h"
#include "Sprite.h"
#include "Quad.h"
#include <vector>

namespace Divbox2D {

	class Renderer{
	public:
		static Shader shader;
		static std::vector<Quad> Quads;
		static void Init();
		static void Shutdown();

		static void DrawQuad();
		static void AddQuad(Quad quad);

	};

}