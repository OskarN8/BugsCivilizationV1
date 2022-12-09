#include "MapBlock.h"


MapBlock::MapBlock(float x, float y)
{
	isFull = true;
	loadTextures();
	setSprite();
	pos = Vector2f(x, y);
	sprite.setPosition(pos);
	

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
	//sprite.setTextureRect(IntRect(0, 0, 50, 50));

}


void MapBlock::renewTimer()
{
	Sleep(30000);
	sprite.setTexture(textureLava);

}
