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

	Quad::Quad(glm::vec2 _position, glm::vec2 _size)
	{
		idleAnim.frames = 10;
		idleAnim.x = 0;
		idleAnim.y = 9;

		vertexArray.Create();
		vertexArray.Bind();
		vertexBuffer.Create();

		vertexArray.PushAttribute(0, 2, sizeof(float) * 0);
		vertexArray.PushAttribute(1, 3, sizeof(float) * 2);
		vertexArray.PushAttribute(2, 2, sizeof(float) * 5);

		size = _size;
		position = _position;
		sprite.LoadSprite("C:/Projects/Divbox2D/resources/orc.png", GL_RGBA);
		std::cout << "Created Quad with ID:" << vertexBuffer.GetVertexBufferID() << " and with sprite ID : " << sprite.spriteID << '\n';
	}

	Quad::~Quad()
	{
		std::cout << "Quad out of scope, Destroying" << '\n';
	}


	VertexArray Quad::GetVertexArray()
	{
		return vertexArray;
	}

	VertexBuffer Quad::GetVertexBuffer()
	{
		return vertexBuffer;
	}

	// modify quad function here with glbuffersubdata
	// anim data



	void Quad::Modify()
	{
	
		vertexArray.Bind();
		

	}
	void Quad::Draw()
	{
		vertexArray.Bind();
		glBindTexture(GL_TEXTURE_2D, sprite.spriteID);
		glUseProgram(Renderer::shader.programID);
		glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(size.x, size.y, 0.0f));
		glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(position.x, position.y, 0.0f));
		transform = scale * model;
		Renderer::shader.UploadUniformMat("model", transform);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
		vertexArray.Unbind();

	}

}