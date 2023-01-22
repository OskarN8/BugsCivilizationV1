#include "Button.h"

Button::Button(string txtName, string varName)
{
	this->varName = varName;
	LoadTexture(txtName);
	sprite.setTexture(this->txt);
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
	if (bounds.contains(win.mapPixelToCoords(Mouse::getPosition(win))))
	{
		return true;
	}
	return false;
}
void Button::EditUp(BugsGen& bugsGen, MapGen& mapGen, RenderWindow& window, Counter& counter)
{
	if (varName == "children")
	{
		for (BugsContent* i : bugsGen.Bugs)
		{
			i->children++;
			counter.Update(window, i->children, i->pos.x + 25, i->pos.y + 25);
		}
		window.display();
	}
	else if (varName == "hungerResistance")
	{
		for (BugsContent* i : bugsGen.Bugs)
		{
			i->hungerResistance = true;
			counter.Update(window, i->hungerResistance, i->pos.x + 25, i->pos.y + 25);
		}
		window.display();
	}
	else if (varName == "maxAge")
	{
		for (BugsContent* i : bugsGen.Bugs)
		{
			i->maxAge++;
			counter.Update(window, i->maxAge, i->pos.x + 25, i->pos.y + 25);
		}
		window.display();
	}
	else if (varName == "maxCanCopulateSeconds")
	{
		for (BugsContent* i : bugsGen.Bugs)
		{
			i->maxCanCopulateSeconds++;
			counter.Update(window, i->maxCanCopulateSeconds-i->lifeSeconds, i->pos.x + 25, i->pos.y + 25);
		}
		window.display();
	}
	else if (varName == "maxLifeSeconds")
	{
		for (BugsContent* i : bugsGen.Bugs)
		{
			i->maxLifeSeconds++;
			counter.Update(window, i->maxLifeSeconds-i->lifeSeconds, i->pos.x + 25, i->pos.y + 25);
		}
		window.display();
	}
	else if (varName == "renewSeconds")
	{

		for (vector<MapBlock*> i : mapGen.MapBlocks2D)
		{
			for (MapBlock* z : i)
				z->renewSeconds++;
		}
		counter.Update(window, mapGen.MapBlocks2D[1][1]->renewSeconds, window.getSize().x - 200, window.getSize().y - 200);
		window.display();
	}
}

void Button::EditDown(BugsGen& bugsGen, MapGen& mapGen, RenderWindow& window, Counter& counter)
{
	if (varName == "children")
	{
		for (BugsContent* i : bugsGen.Bugs)
		{
			if(i->children > 0) i->children--;
			counter.Update(window, i->children, i->pos.x + 25, i->pos.y + 25);
		}
		window.display();
	}
	else if (varName == "hungerResistance")
	{
		for (BugsContent* i : bugsGen.Bugs)
		{
			i->hungerResistance = false;
			counter.Update(window, i->hungerResistance, i->pos.x + 25, i->pos.y + 25);
		}
		window.display();
	}
	else if (varName == "maxAge")
	{
		for (BugsContent* i : bugsGen.Bugs)
		{
			if (i->maxAge > 0) i->maxAge--;
			counter.Update(window, i->maxAge, i->pos.x + 25, i->pos.y + 25);
		}
		window.display();
	}
	else if (varName == "maxCanCopulateSeconds")
	{
		for (BugsContent* i : bugsGen.Bugs)
		{
			if(i->maxCanCopulateSeconds>0) i->maxCanCopulateSeconds--;
			counter.Update(window, i->maxCanCopulateSeconds - i->lifeSeconds, i->pos.x + 25, i->pos.y + 25);
		}
		window.display();
	}
	else if (varName == "maxLifeSeconds")
	{
		for (BugsContent* i : bugsGen.Bugs)
		{
			if (i->maxLifeSeconds > 1) i->maxLifeSeconds--;
			counter.Update(window, i->maxLifeSeconds - i->lifeSeconds, i->pos.x + 25, i->pos.y + 25);
		}
		window.display();
	}
	else if (varName == "renewSeconds")
	{
		for (vector<MapBlock*> i : mapGen.MapBlocks2D)
		{
			for(MapBlock* z : i)
			if (z->renewSeconds > 1) z->renewSeconds--;
		}
		counter.Update(window, mapGen.MapBlocks2D[1][1]->renewSeconds, window.getSize().x - 200, window.getSize().y - 200);
		window.display();
	}

}


