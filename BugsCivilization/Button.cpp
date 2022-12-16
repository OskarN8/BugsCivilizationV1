#include "Button.h"


Button::Button(string txtName, string varName)
{
	this->varName = varName;
	LoadTexture(txtName);
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

bool Button::Hover(RenderWindow& win)
{
	//mousePoint = Vector2f(Mouse::getPosition().x, Mouse::getPosition().y);
	if (bounds.contains(win.mapPixelToCoords(Mouse::getPosition(win))))
	{
		return true;
	}
	return false;
}
void Button::EditUp(BugsGen& bugsGen)
{
	if (varName == "children")
	{
		//vector<BugsContent*> tmp = bugsGen.Bugs;
		for (BugsContent* i : bugsGen.Bugs)
		{
			i->children++;
		}
	}


}

