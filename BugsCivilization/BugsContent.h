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
	Vector2f pos/*, endPosition*/; 
	//bool needNewEndPosition = true;
	int  hunger,hungerResistance, age, size;
	//Vector2f oldEndPosiotion;
	~BugsContent();
	BugsContent(int,int);



};
#endif





