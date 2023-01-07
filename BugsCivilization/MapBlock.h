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
	int renewSeconds;
	MapBlock( float, float);
	void setSprite();
	void loadTextures();
	void renewTimer();
};
#endif
