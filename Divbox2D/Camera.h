#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Divbox2D {

	class Camera {
	private:
		glm::mat4 world;
		glm::mat4 projection;
		glm::vec3 position = glm::vec3(0.0f, 0.0f, -0.5f);
		glm::vec3 front = glm::vec3(0.0f, 0.0f, -0.5f);
		glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
		float rotation;

	public:
		Camera();
		~Camera();

		glm::mat4 GetViewMatrix();
		glm::mat4 GetProjectionMatrix();

		void Move();
	};
}