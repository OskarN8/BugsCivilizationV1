#ifndef MAPBLOCK
#define MAPBLOCK
#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <windows.h>

using namespace sf;
using namespace std;
class MapBlock
{
public:
	bool isFull;
	Vector2f pos;
	Texture textureLava, textureBricks;
	Sprite sprite;
	MapBlock( float, float);
	void setSprite();
	void loadTextures();
	void renewTimer();



};
#endif

/*
#ifndef MAINMAP_H
#define MAINMAP_H

#include <SFML/Graphics.hpp>
#include "AppTile.h"
#include <vector>

class MainMap
{
	vector<Vector2i>bugsPosiotions;
	void setUpInitialState();
	void setUpBugsPositions();
	void setUpTiles();

public:
	vector<vector<AppTile*> > tiles;
	int gridLength;
	MainMap();


};

#endif 
*/