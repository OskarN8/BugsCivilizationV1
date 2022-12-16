#include <SFML/Graphics.hpp>
#include <string.h>
#include <iostream>

using namespace sf;
using namespace std;

class Button
{
public:
	Texture txt;
	Sprite sprite;
	FloatRect bounds;
	FloatRect mousePoint;
	int editVar;
	Button(string);
	void SetPos(float, float);
	void Hover(RenderWindow&);
	void Click();
	void LoadTexture(string name);
	void Draw(RenderWindow&);

};

