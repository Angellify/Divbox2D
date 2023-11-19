#pragma once
#include "Listener.h"

namespace Divbox2D {

	class Listener;
	class Bus
	{
	private:
		std::vector<Listener*> listeners;
	public:
		void Subscribe(Listener* listener);
		void Unsubscribe(Listener* listener);
		void UpdateListener(int message);
		static Bus& GetInstance();
	};

}

