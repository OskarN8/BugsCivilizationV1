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
private:
	Texture texture;
	bool canCopulate;

public:

	Vector2f endPosition, pos;
	Sprite sprite;
	int age,copulateSeconds, children, lifeSeconds, maxAge, maxCanCopulateSeconds, maxLifeSeconds;
	float hunger;
	bool hungerResistance, isAlive, needNewEndPosition, readyToCopulate;

	~BugsContent();
	BugsContent(int, int, Texture);

};
#endif





