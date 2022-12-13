#ifndef BUGSCONTENTH
#define BUGSCONTENTH

#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <vector>
#include "MapGen.h"

using namespace sf;
using namespace std;

class BugsContent
{
public:
	Sprite sprite;
	Texture txt;
	Vector2f pos, endPosition;
	bool needNewEndPosition = true, hungerResistance = false, canCopulate,readyToCopulate, isAlive = true;
	int   age=0, size = 0,lifeSeconds = 0, copulateSeconds = 0;
	float hunger;
	~BugsContent();
	BugsContent(int,int);

};
#endif





