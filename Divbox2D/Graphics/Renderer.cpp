#include "Utils.h"
#include "Renderer.h"

#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>


namespace Divbox2D {

	Shader Renderer::shader;

	struct RenderData {
		VertexArray* vertexArray = new VertexArray;
		Sprite* defaultSprite = new Sprite;
	};
	
	static RenderData renderData;

	void Renderer::Shutdown()
	{
		renderData.vertexArray->Delete();
		delete(renderData.vertexArray);
		delete(renderData.defaultSprite);
	}

	void Renderer::Init()
	{
		std::cout << "Initiating Renderer" << '\n';
		renderData.defaultSprite->LoadSprite("C:/Projects/Divbox2D/resources/Tilemap.png", GL_RGBA);

		Renderer::shader.CreateShader();
		renderData.vertexArray->Create();
		renderData.vertexArray->Bind();
		
		VertexBuffer* vertexBuffer = new VertexBuffer;
		vertexBuffer->Create();

		renderData.vertexArray->PushAttribute(0, 2, sizeof(float) * 0);
		renderData.vertexArray->PushAttribute(1, 3, sizeof(float) * 2);
		renderData.vertexArray->PushAttribute(2, 2, sizeof(float) * 5);
		
		vertexBuffer->Unbind();
		delete(vertexBuffer);
	}

	void Renderer::DrawQuad(glm::vec2 _position, glm::vec2 _size)
	{
		DrawQuad({ _position.x, _position.y, -0.1f }, _size, renderData.defaultSprite);
	}

	void Renderer::DrawQuad(glm::vec2 _position, glm::vec2 _size, Sprite* _sprite)
	{
		DrawQuad({ _position.x, _position.y, -0.1f }, _size, _sprite);
	}

	void Renderer::DrawQuad(glm::vec3 _position, glm::vec2 _size, Sprite *_sprite)
	{
		glBindTexture(GL_TEXTURE_2D, _sprite->spriteID);
		glUseProgram(Renderer::shader.programID);
		glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(_size.x, _size.y, 0.0f));
		glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(_position.x, _position.y, _position.z));
		glm::mat4 transform = scale * model;
		Renderer::shader.UploadUniformMat("model", transform);
		renderData.vertexArray->Draw();
	}

}