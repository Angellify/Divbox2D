#pragma once
#include <string>

class Listener {

private:
public:
	virtual void Update(int message) = 0;
};
