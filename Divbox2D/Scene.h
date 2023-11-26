#pragma once
namespace Divbox2D {

	class Scene {
	public:
		virtual void Init() = 0;
		virtual void Update() = 0;
		virtual void Clean() = 0;
	};
}