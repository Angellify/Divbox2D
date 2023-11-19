#include "Utils.h"
#include "Bus.h"
#include "Listener.h"

namespace Divbox2D {

	void Bus::Subscribe(Listener* listener)
	{
		listeners.push_back(listener);
	}

	void Bus::Unsubscribe(Listener* listener)
	{
		listeners.erase(std::remove(listeners.begin(), listeners.end(), listener), listeners.end());
	}

	void Bus::UpdateListener(int message)
	{
		for (auto listener : listeners)
			listener->Update(message);
	}

	Bus& Bus::GetInstance()
	{
		static Bus instance;
		return instance;
	}
}
