#pragma once
#include "Divbox2D.h"
#include "Bus.h"
#include "Listener.h"
#include <string>
class Player : public Divbox2D::Listener 
{
private:
	int eventKey;


	Divbox2D::Sprite* playerSprite;

public:
	glm::vec2 size;
	glm::vec3 position;

	Player() { Divbox2D::Bus::GetInstance().Subscribe(this); }
	~Player();
	void Load();
	void Move();
	void Draw();

	void Update(int message) override;
};

