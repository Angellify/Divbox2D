#include "Utils.h"
#include "Timetrack.h"

#include <GLFW/glfw3.h>
namespace Divbox2D {

	Timetrack::Timetrack()
	{
		time = 0.0f;
		deltaTime = 0.0f;
		lastTime = 0.0f;
	}

	void Timetrack::Init()
	{

		std::cout << "TIME INIT" << '\n';
	}

	void Timetrack::UpdateTime()
	{
		Timetrack::time = double(glfwGetTime());
		deltaTime = time - lastTime;
		lastTime = time;
	}

	double Timetrack::GetDeltaTime()
	{
		return deltaTime;
		//return deltaTime;
	}

	Timetrack* Timetrack::Get()
	{
		static Timetrack time;
		return &time;
	}
}