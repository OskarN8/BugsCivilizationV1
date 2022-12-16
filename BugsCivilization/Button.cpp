#include "Button.h"


Button::Button(string name)
{
	LoadTexture(name);
	sprite.setTexture(this->txt);
	//SetPos(x, y);

}

void Button::LoadTexture(string name)
{
	txt.loadFromFile("images/" + name +".png");
}

void Button::Draw(RenderWindow& win)
{
	win.draw(sprite);
}

void Button::SetPos(float x, float y)
{
	sprite.setPosition(x, y);
	bounds = sprite.getGlobalBounds();
}

void Button::Hover(RenderWindow& win)
{
	//mousePoint = Vector2f(Mouse::getPosition().x, Mouse::getPosition().y);
	if (bounds.contains(win.mapPixelToCoords(Mouse::getPosition(win))))
	{
		cout<<"lol dziala"<<endl;
	}
}

