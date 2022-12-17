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
void Button::EditUp(BugsGen& bugsGen, MapGen& mapGen)
{
	if (varName == "children")
	{
		//vector<BugsContent*> tmp = bugsGen.Bugs;
		for (BugsContent* i : bugsGen.Bugs)
		{
			i->children++;
		}
	}
	else if (varName == "hungerResistance")
	{
		for (BugsContent* i : bugsGen.Bugs)
		{
			i->hungerResistance = true;
		}
	}
	else if (varName == "maxAge")
	{
		for (BugsContent* i : bugsGen.Bugs)
		{
			i->maxAge++;
		}
	}
	else if (varName == "maxCanCopulateSeconds")
	{
		for (BugsContent* i : bugsGen.Bugs)
		{
			i->maxCanCopulateSeconds++;
		}
	}
	else if (varName == "maxLifeSeconds")
	{
		for (BugsContent* i : bugsGen.Bugs)
		{
			i->maxLifeSeconds++;
		}
	}
	else if (varName == "renewSeconds")
	{
		for (MapBlock* i : mapGen.Blocks)
		{
			i->renewSeconds++;
		}
	}
}

void Button::EditDown(BugsGen& bugsGen, MapGen& mapGen)
{
	if (varName == "children")
	{
		//vector<BugsContent*> tmp = bugsGen.Bugs;
		for (BugsContent* i : bugsGen.Bugs)
		{
			if(i->children > 0) i->children--;
		}
	}
	else if (varName == "hungerResistance")
	{
		for (BugsContent* i : bugsGen.Bugs)
		{
			i->hungerResistance = false;
		}
	}
	else if (varName == "maxAge")
	{
		for (BugsContent* i : bugsGen.Bugs)
		{
			if (i->maxAge > 0) i->maxAge--;
		}
	}
	else if (varName == "maxCanCopulateSeconds")
	{
		for (BugsContent* i : bugsGen.Bugs)
		{
			if(i->maxCanCopulateSeconds>0) i->maxCanCopulateSeconds--;
		}
	}
	else if (varName == "maxLifeSeconds")
	{
		for (BugsContent* i : bugsGen.Bugs)
		{
			if (i->maxLifeSeconds > 1) i->maxLifeSeconds--;
		}
	}
	else if (varName == "renewSeconds")
	{
		for (MapBlock* i : mapGen.Blocks)
		{
			if (i->renewSeconds > 1) i->renewSeconds--;
		}
	}
}


