#include "Divbox2D.h"
#include "Player.h"

class Scene01 : public Divbox2D::Scene {

private:
	Player player;

public:
	void Init();
	void Update();
};