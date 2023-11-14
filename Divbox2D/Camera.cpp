#include "Utils.h"
#include "Camera.h"

namespace Divbox2D {

	Camera::Camera()
	{
		float aspect = (float)1600 / 900;
		float halfHeight = 900.0f / 2.0f;
		float halfWidth = halfHeight * aspect;
		world = glm::lookAt(position, position + front, up);
		projection = glm::ortho(-halfWidth, halfWidth, -halfHeight, halfHeight, -1.0f, 1.0f);
	}

	Camera::~Camera()
	{
	}

	glm::mat4 Camera::GetProjectionMatrix()
	{
		return projection;
	}

	

	glm::mat4 Camera::GetViewMatrix()
	{
		return world;
	}
	void Camera::Move()
	{
	}
}