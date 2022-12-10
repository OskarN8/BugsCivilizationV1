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
	Vector2f pos;
	bool hungerResistance = false;
	int  hunger, age, size;
	~BugsContent();
	BugsContent(int,int);
};
#endif





