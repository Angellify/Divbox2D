#include "Utils.h"
#include "Quad.h"

namespace Divbox2D {

	void Quad::CreateQuad()
	{
		vertexArray.Create();
		vertexArray.Bind();
		vertexBuffer.Create();

		vertexArray.PushAttribute(0, 2, 0);
		vertexArray.PushAttribute(1, 3, sizeof(float) * 2);
		vertexArray.PushAttribute(2, 2, sizeof(float) * 5);
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
	}

}