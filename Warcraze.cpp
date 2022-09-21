#include "GameEngine.h"

int gameboard[5][15];

class Warcraze : public GameEngine
{
    enum CharacterClass
    {
        CIVILIAN, BARD, SOLDIER,
        SCOUT, DEVOUT, CONJURER
    };

    class Character
    {
        public:
            CharacterClass characterClass;

            Character()
            {

            }
    };

    bool OnUserCreate() override
    {
        olc::Sprite *sprite = new olc::Sprite("assets\02-bard.png");
        sprite::SpriteSheet *spriteSheet = new sprite::SpriteSheet(sprite, 50, 50);

        olc::Sprite *newSprite = spriteSheet->Crop(0, 0);

        DrawSprite(0, 0, newSprite);
    }
};

int main()
{
	if (engine->Construct(450, 300, 2, 2, false, true, true))
	{
		engine->Start();
	}
	return 0;
}
