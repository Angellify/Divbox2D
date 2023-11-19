#pragma once
#include "Bus.h"
#include <iostream>

namespace Divbox2D {

	class Listener {
	private:
		int _id;
	public:
		virtual void Update(int message) = 0;
	};

}