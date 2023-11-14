#pragma once

namespace Divbox2D {

	class Sprite {
	public:
		unsigned int spriteID;
		unsigned int spriteWidth;
		unsigned int spriteHeight;

		Sprite();
		void LoadSprite(const char* filepath, unsigned int type);

	};

}