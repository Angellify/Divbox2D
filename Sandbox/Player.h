#pragma once
#include "Divbox2D.h"
#include "Listener.h"
#include <string>
class Player : public Listener 
{
private:
	int eventKey;
	glm::mat4 transform;
	Divbox2D::Quad playerQuad;
public:

	void Load();
	void Draw();
	void Move();
	Divbox2D::Quad GetQuad();

	// Inherited via Listener
	void Update(int message) override;
};

