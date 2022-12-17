#include <SFML/Graphics.hpp>
#include <string.h>
#include <iostream>
#include "BugsGen.h"


using namespace sf;
using namespace std;

class Button
{
public:
	Texture txt;
	Sprite sprite;
	FloatRect bounds;
	FloatRect mousePoint;
	Button(string,string);
	void SetPos(float, float);
	string varName;
	bool Hover(RenderWindow&);
	void Click();
	void LoadTexture(string name);
	void Draw(RenderWindow&);
	void EditUp(BugsGen&, MapGen&);
	void EditDown(BugsGen&, MapGen&);

};

