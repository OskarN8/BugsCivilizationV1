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
	Texture texture;
	Vector2f pos, endPosition;
	bool maxAge, needNewEndPosition, hungerResistance, canCopulate,readyToCopulate, isAlive;
	int   maksAge, age, lifeSeconds, copulateSeconds, childrens;
	float hunger;
	~BugsContent();
	BugsContent(int,int,Texture);


};
#endif





