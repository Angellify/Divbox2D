#include "Utils.h"
#include "Quad.h"
#include "Renderer.h"

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>


namespace Divbox2D {

	Quad::Quad()
	{
	}

	Quad::Quad(glm::vec2 _position, glm::vec2 _size, Sprite _sprite)
	{
		vertexArray.Create();
		vertexArray.Bind();
		vertexBuffer.Create();

		vertexArray.PushAttribute(0, 2, 0);
		vertexArray.PushAttribute(1, 3, sizeof(float) * 2);
		vertexArray.PushAttribute(2, 2, sizeof(float) * 5);

		size = _size;
		position = _position;
		sprite = _sprite;

		glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(size.x, size.y, 0.0f));
		glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(position.x, position.y, 0.0f));
		transform = scale * model;
	}


	VertexArray Quad::GetVertexArray()
	{
		return vertexArray;
	}

	VertexBuffer Quad::GetVertexBuffer()
	{
		return vertexBuffer;
	}




	void Quad::Draw()
	{
		vertexArray.Bind();
		glBindTexture(GL_TEXTURE_2D, sprite.spriteID);
		
		glUseProgram(Renderer::shader.programID);
		Renderer::shader.UploadUniformMat("model", transform);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
		vertexArray.Unbind();
	}

}