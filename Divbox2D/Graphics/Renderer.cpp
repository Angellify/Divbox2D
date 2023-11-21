#include "Utils.h"
#include "Renderer.h"

#include <glad/glad.h>

namespace Divbox2D {

	Sprite grassSprite;
	Shader Renderer::shader;
	std::vector<Quad> Renderer::Quads;
	std::vector<Quad*> Renderer::pQuads;


	void Renderer::Shutdown()
	{
		for (auto i : Quads)
		{
			i.GetVertexBuffer().Delete();
			i.GetVertexArray().Delete();
		}
	}

	void Renderer::Init()
	{
		Renderer::shader.CreateShader();
	}

	void Renderer::AddQuad(Quad quad)
	{
		Renderer::Quads.emplace_back(quad);
	}
	void Renderer::AddQuad(Quad* quad)
	{
		Renderer::pQuads.emplace_back(quad);
	}

	void Renderer::DrawQuad()
	{
		if (!Renderer::pQuads.empty())
			for (Quad* quad : Renderer::pQuads)
				quad->Draw();
	}

}