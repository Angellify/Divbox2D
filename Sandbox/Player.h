#pragma once
#include "Divbox2D.h"
#include "Bus.h"
#include "Listener.h"
#include <string>
class Player : public Divbox2D::Listener 
{
private:
	int eventKey;
	glm::mat4 transform;
	Divbox2D::Quad playerQuad;
	Divbox2D::Sprite playerSprite;
public:
	Player() { Divbox2D::Bus::GetInstance().Subscribe(this); }
	void Load();
	void Draw();
	void Move();

	// Inherited via Listener
	void Update(int message) override;
};

