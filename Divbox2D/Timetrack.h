#pragma once


namespace Divbox2D {

	class Timetrack {
	public:
		double time;
		double deltaTime;
		double lastTime;
		Timetrack();
		void Init();
		void UpdateTime();
		double GetDeltaTime();
		static Timetrack* Get();
	};


}