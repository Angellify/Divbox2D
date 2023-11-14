#pragma once
#include "Scene.h"
#include "Timetrack.h"
#include "Graphics/Renderer.h"
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Divbox2D {

	class Window {
	private:
		int screenWidth = 1600;
		int screenHeight = 900;

		GLFWwindow* window;
		std::vector<Scene*> scenes;
	public:

		void Run();
		void PushScene(Scene* scene);
		void Update();
	};
}