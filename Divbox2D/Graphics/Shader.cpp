#include "Utils.h"
#include "Shader.h"

#include <glad/glad.h>

namespace Divbox2D {

	const char* vertexShaderSource =
		"#version 410 core\n"
		"layout(location = 0) in vec3 aPos;\n"
		"layout(location = 1) in vec3 aColor;\n"
		"layout(location = 2) in vec2 aTexCoord;\n"

		"out vec3 ourColor;\n"
		"out vec2 TexCoord;\n"

		"uniform mat4 model;\n"
		"uniform mat4 world;\n"
		"uniform mat4 projection;\n"

		"void main()\n"
		"{\n"
		"   gl_Position = projection * world * model * vec4(aPos, 1.0);\n"
		"   ourColor = aColor;\n"
		"   TexCoord = vec2(aTexCoord.x, aTexCoord.y);\n"
		"}\0";
	const char* fragmentShaderSource =
		"#version 410 core\n"
		"out vec4 FragColor;"
		"in vec3 ourColor;\n"
		"in vec2 TexCoord;\n"
		"uniform vec3 color;\n"
		"uniform sampler2D texture1;\n"
		"void main()\n"
		"{\n"
		//"   FragColor = vec4(color, 1.0);\n"
		"   FragColor = texture(texture1, TexCoord);\n"
		"}\n\0";

	void Shader::CreateShader()
	{

		__int32 vertexShaderID = glCreateShader(GL_VERTEX_SHADER);

		glShaderSource(vertexShaderID, 1, &vertexShaderSource, nullptr);
		glCompileShader(vertexShaderID);

		__int32 vertexCompile;
		glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &vertexCompile);

		if (vertexCompile != GL_TRUE)
		{
			int logLength = 0;
			char msg[1024];
			glGetShaderInfoLog(vertexShaderID, 1024, &logLength, msg);
			std::cout << msg << std::endl;
		}
		else
		{
			std::cout << "Vertex Shader Compiled Succesfully" << std::endl;
		}


		__int32 fragmentCompile;

		__int32 fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShaderID, 1, &fragmentShaderSource, nullptr);
		glCompileShader(fragmentShaderID);

		glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &fragmentCompile);

		if (fragmentCompile != GL_TRUE)
		{
			int logLength = 0;
			char msg[1024];
			glGetShaderInfoLog(fragmentShaderID, 1024, &logLength, msg);
			std::cout << msg << std::endl;
		}
		else
		{
			std::cout << "Fragment Shader Compiled Succesfully" << std::endl;
		}

		__int32 programLink;

		programID = glCreateProgram();

		glAttachShader(programID, vertexShaderID);
		glAttachShader(programID, fragmentShaderID);
		glLinkProgram(programID);
		glGetProgramiv(programID, GL_LINK_STATUS, &programLink);

		char txt[1024];

		if (programLink != GL_TRUE)
		{
			int logLength = 0;
			glGetProgramInfoLog(programLink, 1024, NULL, txt);
			std::cout << txt << std::endl;
			std::cout << "FAILED TO COMPILE" << std::endl;

		}
		else
		{
			std::cout << "Program Linked Succesfully" << std::endl;
		}

		glUseProgram(programID);


	}

	void Shader::UploadUniformMat(const char* uniformName, glm::mat4 uniformMat)
	{
		glUniformMatrix4fv(glGetUniformLocation(this->programID, uniformName), 1, GL_FALSE, glm::value_ptr(uniformMat));
	}

	void Shader::UploadUniformMat(const char* uniformName, glm::vec3 uniformMat)
	{
		glUniformMatrix4fv(glGetUniformLocation(this->programID, uniformName), 1, GL_FALSE, glm::value_ptr(uniformMat));
	}
}