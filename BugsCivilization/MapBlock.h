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
private:
	Vector2f pos;
	Texture textureLava, textureBricks;
	void loadTextures();

public:
	bool isFull;
	int renewSeconds;
	Sprite sprite;

	MapBlock(float, float);
	void renewTimer();
	void setSprite();
};
#endif
