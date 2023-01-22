#ifndef BUTTONH
#define BUTTONH


#include <SFML/Graphics.hpp>
#include <string.h>
#include <iostream>
#include "BugsGen.h"
#include "Counter.h"


using namespace sf;
using namespace std;

class Button
{
private:
	Counter counter;
	Texture txt;
	FloatRect bounds;
	string varName;

	void LoadTexture(string name);

public:
	Sprite sprite;

	Button(string, string);
	void Draw(RenderWindow&);
	void EditUp(BugsGen&, MapGen&, RenderWindow&, Counter&);
	void EditDown(BugsGen&, MapGen&, RenderWindow&, Counter&);
	bool Hover(RenderWindow&);
	void SetPos(float, float);

};

#endif
