#pragma once
#include "Divbox2D.h"

class Player {
private:
	glm::mat4 transform;
	Divbox2D::Quad playerQuad;
public:

	void Load();
	void Draw();
	void Move();
	Divbox2D::Quad GetQuad();
};

