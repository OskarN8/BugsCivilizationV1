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
	bool needNewEndPosition, hungerResistance, canCopulate,readyToCopulate, isAlive;
	int   age=0, size, lifeSeconds, copulateSeconds, childrens;
	float hunger;
	~BugsContent();
	BugsContent(int,int);


};
#endif





