#pragma once

namespace Divbox2D {

	class VertexArray {
	private:
		unsigned __int32 vertexArrayID;
	public:

		void Bind();
		void Unbind();
		void Create();
		void Delete();
		void PushAttribute(int index, int size, int stride);
		void Draw();
		unsigned __int32 GetVertexArrayID();

	};

}