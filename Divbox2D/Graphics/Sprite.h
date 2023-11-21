#pragma once
#include "VertexArray.h"
namespace Divbox2D {

	class Sprite {
		VertexArray parentVertexID;
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

		double animationSpeed;
		double animationUpdateTime = 1.0f / animationSpeed;
		double timeSinceLastFrameSwap;

		Sprite();
		~Sprite();
		void Play();
		void LoadSprite(const char* filepath, unsigned int type);
	};

}