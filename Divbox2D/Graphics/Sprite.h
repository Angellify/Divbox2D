#pragma once

namespace Divbox2D {

	class Sprite {
	public:
		unsigned int spriteID;
		
		int x = 0;
		int y = 9;
		int spriteWidth;
		int spriteHeight;
		float tileWidth;
		float tileHeight;

		bool animation;
		bool active;
		bool moving;
		double animationSpeed = 15.0f;
		double animationUpdateTime = 1.0f / animationSpeed;
		double timeSinceLastFrameSwap;

		Sprite();
		void LoadSprite(const char* filepath, unsigned int type);

	};

}