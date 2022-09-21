#pragma once
#define __MINGW32__
#define _WIN32
#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine/olcPixelGameEngine.h"

class GameEngine : public olc::PixelGameEngine {};

static GameEngine *engine;

namespace shape
{
	class Rectangle
	{
		public:
			float x, y, width, height;
			olc::Pixel color;

			Rectangle(float x, float y, float width, float height, olc::Pixel color)
			{
				this->x = x;
				this->y = y;
				this->width = width;
				this->height = height;
				this->color = color;
			}
	};

	class Circle
	{
		public:
			float x, y, radius;
			olc::Pixel color;

			Circle(float x, float y, float radius, olc::Pixel color)
			{
				this->x = x;
				this->y = y;
				this->radius = radius;
				this->color = color;
			}
	};
}

namespace sprite
{
    class SpriteSheet
    {
        public:
            olc::Sprite *spritesheet;
            int spriteWidth, spriteHeight;

            SpriteSheet(olc::Sprite *spritesheet, int spriteWidth, int spriteHeight)
            {
                this->spritesheet = spritesheet;
                this->spriteWidth = spriteWidth;
                this->spriteHeight = spriteHeight;
            }

            olc::Sprite* Crop(int x, int y)
            {
                olc::Sprite *newSprite = new olc::Sprite(spriteWidth, spriteHeight);

                engine->SetDrawTarget(newSprite);
                engine->DrawSprite({-spriteWidth * x, -spriteHeight * y}, spritesheet);
                engine->SetDrawTarget(nullptr);

                return newSprite;
            }
    };
}
