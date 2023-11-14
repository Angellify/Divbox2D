#include "Utils.h"
#include "Renderer.h"

#include <glad/glad.h>

namespace Divbox2D {

	Sprite grassSprite;
	Shader Renderer::shader;
	std::vector<Quad> Renderer::Quads;

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
		grassSprite.LoadSprite("C:/Projects/Divbox2D/resources/Tilemap.png", GL_RGBA);
	}

	void Renderer::AddQuad(Quad quad)
	{
		Renderer::Quads.emplace_back(quad);
	}

	void Renderer::AddQuad(glm::vec2 position)
	{
		Quad quad;
		quad.CreateQuad();
		quad.posX = position.x;
		quad.posY = position.y;
		quad.width = 1.0f;
		quad.height = 1.0f;

		Renderer::Quads.emplace_back(quad);
	}

	void Renderer::AddQuad(glm::vec2 position, glm::vec2 size)
	{
		Quad quad;
		quad.CreateQuad();
		quad.posX = position.x;
		quad.posY = position.y;

		quad.width = size.x;
		quad.height = size.y;
		Renderer::Quads.emplace_back(quad);
	}


	void Renderer::DrawQuad()
	{
		glBindTexture(GL_TEXTURE_2D, grassSprite.spriteID);

		if (!Renderer::Quads.empty())
			for (Quad quad : Renderer::Quads)
			{
				glUseProgram(Renderer::shader.programID);
				glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(quad.width, quad.height, 0.0f));
				glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(quad.posX, quad.posY, 0.0f));
				glm::mat4 transfom = scale * model;

				Renderer::shader.UploadUniformMat("model", transfom);

				quad.GetVertexArray().Bind();
				glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
				quad.GetVertexArray().Unbind();
			}
	}

}