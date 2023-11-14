# Divbox2D
 A simple game engine made with OpenGL and C++. The goal of this project was to learn more about how computer graphics work and how games are made and also get more familiar with the C++ language. This is about one month of work. Currently the engine is pretty bare bones with only the basics added. However the plan is to iterate and improve the engine as time goes on. Here are some of the features available:
 
> [!NOTE]
> This project in it's early stages of development and there are a lot of features missing or not yet fully implemented and thus subject to change. 

 ### Basic Sprite Renderer
<img align="left" src="https://github.com/Angellify/DivineEngine/assets/147601523/2c701894-cf3e-47a8-87ed-cab79b46caf1" alt="My Image"> 
Currently the renderer is capable of drawing quads at different positions, with different sizes and textures and even play animations. There is still some functionality missing from the Renderer class, since playing animations isn't exactly straight forward and still relies on writing a lot of the code by hand. The plan is to streamline this feature and add more support for sprite animations in the future.

<br clear="left"/>

### Input Delegation
Similar to the Unity engine, you can check from anywhere if a certain key is being pressed.
```
Player.cpp
if (Divbox2D::Input::Get()->Update() == 'W')
    playerQuad.posY += 1.0f * deltaTime;
```
This is however a bit limited at the time since pressing any other button cancels the action out. 
A possible fix that I have yet to implement is mapping the key states to a binary number and check for possible combations (for example, W+D = Move Diagonally).

## Timestep
There is a class that keeps track of the Delta Time and, using a static getter, it can be used for movement or anything else.
```
double deltaTime = Divbox2D::Timetrack::Get()->deltaTime;
```

## Scene Management
Albeit a crude implementation, it is possible to create different scenes and swap between them. This is not %100 fully implemented yet but the groundwork is there.

```
Application.cpp
void Application::Init()
{
    Divbox2D::Scene* scene01 = new Scene01();
    this->PushScene(scene01);
}
```

# Architecture & Documentation

The plan is to have two separate entities whenever creating a game using the engine: The **Engine** and the **Game**. Here is a quick (and not complete) overview of the project structure. Currently there is only one project and two folders that separate the engine and game files. In the future I might separate it further with two visual studio projects but for easier overview and management, I haven't done so yet.

1. Engine
   - Graphics
     - Quad
     - VertexBuffer
     - VertexArray
     - Renderer
   - Camera
   - Input
   - Window
   - Scene
2. Game
   - Application
   - Player
   - Scene01
     
# Getting Started

In order to create a game, you first create a class that inherits from *Divbox2D::Window*. There aren't any methods to implement, all we need is a method where we will load up our scenes and send them to the engine. This is also where the program will run from so we also need to create a main function. We then create a window, initialize our scenes and start updating the game by using the Run() and Update() methods from the base class.
```
Application.cpp
void Application::Init()
{
    Divbox2D::Scene* scene01 = new Scene01();
    this->PushScene(scene01);
}
void Application::Init()
{
    Divbox2D::Scene* scene01 = new Scene01();
    this->PushScene(scene01);
}

int main(void)
{
    Application Prototype01;
    Prototype01.Run();
    Prototype01.Init();
    Prototype01.Update();
}
```
## Scene Management
The idea of a scene is to contain everything that is needed for a game level. That means, the camera, player, enemies, game logic and such. Creating a scene is straight forward, we just create a new class that inherits from the *Divbox2D::Scene*. Since this is a pure virtual class, we will need to implement the virtual methods and then code our game logic. The *Init* method should be used for initializing the camera, renderer and any and all textures, quads, creating the map and such. The *Update* method should then be used for the game loop, drawing objects and other logic. 
```
Scene01.cpp
void Scene01::Init()
{
    Divbox2D::Camera mainCamera;

    Divbox2D::Renderer::Init();
    Divbox2D::Renderer::shader.UploadUniformMat("world", mainCamera.GetViewMatrix());
    Divbox2D::Renderer::shader.UploadUniformMat("projection", mainCamera.GetProjectionMatrix());

    player.Load();  
}

void Scene01::Update() {
    player.Draw();
    player.Move();
}
```

## Quads, shaders, buffers and sprites
Starting off, we have a Quad class that can be used to quickly create objects for our game. It creates a vertex array, vertex buffer and the needed indices. Currently there is no batch rendering so after a couple thousand quads we will see some frame drops. The plan is to re-structure the renderer in the future and improve it, but for now I was happy to get a basic renderer working.

**Shaders** are pretty straight forward, currently I am only using one renderer and didn't bother writing an elaborate class to handle them. Everything is done in one class and mostly one method, with two extra methods allowing us to update and change shader uniforms.
```
Shader.cpp
void Shader::UploadUniformMat(const char* uniformName, glm::mat4 uniformMat)
	{
		glUniformMatrix4fv(glGetUniformLocation(this->programID, uniformName), 1, GL_FALSE, glm::value_ptr(uniformMat));
	}

	void Shader::UploadUniformMat(const char* uniformName, glm::vec3 uniformMat)
	{
		glUniformMatrix4fv(glGetUniformLocation(this->programID, uniformName), 1, GL_FALSE, glm::value_ptr(uniformMat));
	}
}
```
**Buffer objects** are also pretty straight forward but will need a re-write in the future as the current implementation won't support batch rendering without a rewrite of the logic. The texture coordinates being passed into the vertex buffer is also less than ideal since it's pretty much hard coded at this point and it makes it pretty painful to add anything more than one or two textures to use and there is also no straight forward way of changing the index of a texture, or changing coordinates in case of a tile map. This is all subject to a rewrite of course, to make it more efficient and easier to work with.

**Sprite** just generates the texture but doesn't really support different textures as of now, it's mostly tailored to tile maps. The implementation is straight forward and simple enough using the stb library. 

## Coordinates

Right now, moving and changing object's positions is done through the shader by modifying the *Model* shader uniform. During the drawing loop, we get each quad's position and pass it to the transformation matrix. From my research this is pretty much the way to do it but it will also need to be rewritten whenever I implement batch rendering.
```
Renderer.cpp
	void Renderer::DrawQuad()
	{
		if (!Renderer::Quads.empty())
			for (Quad quad : Renderer::Quads)
			{
				glUseProgram(Renderer::shader.programID);
				glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(quad.width, quad.height, 0.0f));
				glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(quad.posX, quad.posY, 0.0f));
				glm::mat4 transfom = scale * model;

				Renderer::shader.UploadUniformMat("model", transfom);

			}
	}
```

### Libraries:
https://www.glfw.org/ \
https://glad.dav1d.de/ \
https://glm.g-truc.net/0.9.2/api/index.html \
https://registry.khronos.org/EGL/api/KHR/khrplatform.h \
https://github.com/nothings/stb/blob/master/stb_image.h \


### Resources:
https://learnopengl.com/ \
https://www.youtube.com/@TheCherno 
