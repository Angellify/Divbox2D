#pragma once

namespace Divbox2D {




	class VertexBuffer {


	private:
		unsigned __int32 vertexBufferID;
		unsigned __int32 indexBufferID;
	public:
		VertexBuffer();


		void Create();

		void Delete();

		void Bind();
		void Unbind();

		unsigned __int32 GetVertexBufferID();
		unsigned __int32 GetIndexBufferID();

	};
}