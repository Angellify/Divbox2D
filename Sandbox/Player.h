#pragma once
#include "Divbox2D.h"
#include "Bus.h"
#include "Listener.h"
#include <string>
class Player : public Divbox2D::Listener 
{
private:
	int eventKey;

	glm::vec2 size;
	glm::vec2 position;
	glm::mat4 transform;

public:
	Player() { Divbox2D::Bus::GetInstance().Subscribe(this); }

	void Load();
	void Move();
	void Draw();

	void Update(int message) override;
};

