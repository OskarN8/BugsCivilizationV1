#include "BugsContent.h"



BugsContent::BugsContent(int x, int y,Texture txt)
{
	texture = txt;
	pos = Vector2f(x,y);
	size = 0;
	lifeSeconds = 0;
	copulateSeconds = 0;
	childrens = 5;
	hunger = 100;
	hungerResistance = false;
	needNewEndPosition = true;
	canCopulate = true;
	readyToCopulate = false;
	isAlive = true;
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, 50, 50));
	sprite.setPosition(pos);


}



BugsContent::~BugsContent()
{
	cout << "Robal usuniety" << endl;
}




