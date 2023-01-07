#include "BugsContent.h"



BugsContent::BugsContent(int x, int y,Texture txt)
{
	texture = txt;
	pos = Vector2f(x,y);
	age = 0;
	maxAge = 3;
	lifeSeconds = 0;
	maxLifeSeconds = 20;
	copulateSeconds = 0;
	maxCanCopulateSeconds = 60;
	children = 1;
	hunger = 100;
	hungerResistance = false;
	needNewEndPosition = true;
	canCopulate = true;
	readyToCopulate = false;
	isAlive = true;
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, 50, 50));
	sprite.setPosition(pos);
	sprite.setScale(0.8f, 0.8f);
}

BugsContent::~BugsContent()
{
}




