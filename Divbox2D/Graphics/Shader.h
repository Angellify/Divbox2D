#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Divbox2D {

	class Shader {
	public:
		unsigned __int32 programID;
		void CreateShader();
		void UploadUniformMat(const char* uniformName, glm::mat4 uniformMat);
		void UploadUniformMat(const char* uniformName, glm::vec3 uniformMat);

	};
}