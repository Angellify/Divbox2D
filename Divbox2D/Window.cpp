#include "Utils.h"
#include "Window.h"
#include "Subject.h"
#include "Observer.h"



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

		Subject* subj = new Subject;
		Observer* observer1 = new Observer(*subj);
		Observer* observer2 = new Observer(*subj);

		subj->CreateMessage("Hello World");
		subj->CreateMessage();
		observer2->RemoveMeFromTheList();
		subj->CreateMessage("Oh no");


		while (!glfwWindowShouldClose(window))
		{
			glClearColor(0.2f, 0.5f, 0.5f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			Timetrack::Get()->UpdateTime();
			Renderer::DrawQuad();

			if (!scenes.empty())
				for (auto scene : scenes)
					scene->Update();

			glfwSwapBuffers(window);
			glfwPollEvents();
		}
		Renderer::Shutdown();
		glfwTerminate();
	}



}
