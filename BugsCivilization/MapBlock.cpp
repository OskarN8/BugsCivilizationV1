#include "MapBlock.h"


MapBlock::MapBlock(float x, float y)
{
	isFull = true;
	loadTextures();
	setSprite();
	pos = Vector2f(x, y);
	sprite.setPosition(pos);
	renewSeconds = 30;
}

void MapBlock::loadTextures()
{
	textureLava.loadFromFile("images/lava.png");
	textureBricks.loadFromFile("images/bricks.png");
}

void MapBlock::setSprite()
{
	if (isFull == true)
	{
		sprite.setTexture(textureLava);
	}
	else
	{
		sprite.setTexture(textureBricks);
	}
}

void MapBlock::renewTimer()
{
	Sleep(renewSeconds*1000);
	sprite.setTexture(textureLava);
	isFull = true;
}
