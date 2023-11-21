#include "Utils.h"
#include "Window.h"
#include "Bus.h"
#include "Input.h"


namespace Divbox2D {

	void framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		float aspect = (float)width / height;
		float halfHeight = height / 2.0f;
		float halfWidth = halfHeight * aspect;

		Renderer::shader.UploadUniformMat("projection", glm::ortho(-halfWidth, halfWidth, -halfHeight, halfHeight, -1.0f, 1.0f));
		glViewport(0, 0, width, height);
	}

	void Window::Run()
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		window = glfwCreateWindow(screenWidth, screenHeight, "COOL GAME", NULL, NULL);


		if (window == NULL)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
		}
		glfwMakeContextCurrent(window);
		glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
		}

	}


	void Window::PushScene(Scene* scene)
	{
		if (scene != nullptr)
			scene->Init();

		scenes.emplace_back(scene);
	}


	

	void Window::Update()
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		Input input;

		while (!glfwWindowShouldClose(window))
		{
			glClearColor(0.2f, 0.5f, 0.5f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			Timetrack::Get()->UpdateTime();
			Bus::GetInstance().UpdateListener(input.Update());

			if (!scenes.empty())
				for (auto scene : scenes)
					scene->Update();

			Renderer::DrawQuad();

			glfwSwapBuffers(window);
			glfwPollEvents();
		}

		for (Quad* quad : Renderer::pQuads)
			delete quad;

		Renderer::Shutdown();
		glfwTerminate();
	}



}
