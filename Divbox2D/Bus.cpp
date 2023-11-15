#include "Utils.h"
#include "Bus.h"

void Bus::Subscribe(Listener* listener)
{
	listeners.push_back(listener);
}

void Bus::UpdateListener(int message)
{
	for (auto listener : listeners)
		listener->Update(message);
}

Bus* Bus::GetBus()
{
	static Bus bus;
	return &bus;
}
