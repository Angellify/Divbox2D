#pragma once
#include <vector>
#include "Listener.h"

class Bus
{
private:
	std::vector<Listener*> listeners;
public:
	void Subscribe(Listener* listener);
	void UpdateListener(int message);
	static Bus* GetBus();
};

