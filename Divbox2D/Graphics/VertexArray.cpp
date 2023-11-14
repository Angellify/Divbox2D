#include "Utils.h"
#include "VertexArray.h"
#include <glad/glad.h>
namespace Divbox2D {

	void VertexArray::Bind()
	{
		glBindVertexArray(vertexArrayID);
	}

	void VertexArray::Unbind()
	{
		glBindVertexArray(0);
	}

	void VertexArray::Create()
	{
		glGenVertexArrays(1, &vertexArrayID);
	}

	void VertexArray::Delete()
	{
		glDeleteVertexArrays(1, &vertexArrayID);
	}

	void VertexArray::PushAttribute(int index, int size, int stride)
	{
		glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, sizeof(float) * 7, (const void*)stride);
		glEnableVertexAttribArray(index);
	}

	unsigned __int32 VertexArray::GetVertexArrayID()
	{
		return vertexArrayID;
	}

}