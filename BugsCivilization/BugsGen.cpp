#include "BugsGen.h"


void BugsGen::LoadTextures()
{
	this->txt.loadFromFile("images/bug.png");
}

void BugsGen::bugsFirstDraw(RenderWindow& win, int howMany)
{

	default_random_engine gen(time(NULL)+rand());

	for (int i = 0; i < howMany; i++)
	{
		uniform_int_distribution<int> distX(1, 4);
		uniform_int_distribution<int> distY(1, 4);
		Bugs.push_back(new BugsContent(distX(gen) * 50, distY(gen) * 50,txt));
		win.draw(Bugs[i]->sprite);
	}
}

void BugsGen::movingPath(RenderWindow& win, BugsContent* certainBug)
{

	if (certainBug->needNewEndPosition == true)
	{
		default_random_engine gen(time(NULL) + rand());

		uniform_int_distribution<int> dirX(50, 500);
		uniform_int_distribution<int> dirY(50, 400);

		certainBug->needNewEndPosition = false;
		certainBug->endPosition = Vector2f(int(dirX(gen)), int(dirY(gen)));
	}
	else if (certainBug->pos != certainBug->endPosition)
	{
		(certainBug->pos.x < certainBug->endPosition.x) ? certainBug->pos.x += 1 : certainBug->pos.x -= 1;

		if (certainBug->pos != certainBug->endPosition)
		{
			(certainBug->pos.y < certainBug->endPosition.y) ? certainBug->pos.y += 1 : certainBug->pos.y -= 1;

		}
		certainBug->sprite.setPosition(certainBug->pos);
		win.draw(certainBug->sprite);
	}
	else if (certainBug->pos == certainBug->endPosition)
	{
		certainBug->needNewEndPosition = true;
	}
	}


void BugsGen::hungerBehaviour(MapGen& gen, BugsContent* certainBug)
{
	certainBug->hunger -= 0.1;
	//cout << certainBug->hunger << endl;

	if (certainBug->hunger < 0 && certainBug->hungerResistance == false)
	{
		HungerDeath(certainBug);
	}

	else if (certainBug->hunger < 80 && certainBug->hungerResistance == false)
	{
		int rowX = (certainBug->pos.x + 25) / 100;
		int rowY = (certainBug->pos.y + 25) / 100;

		(certainBug->pos.x + 25 > rowX * 100 + 50) ? rowX = rowX * 100 + 50 : rowX = rowX * 100;
		(certainBug->pos.y + 25 > rowY * 100 + 50) ? rowY = rowY * 100 + 50 : rowY = rowY * 100;
		
		if (gen.MapBlocks2D[(rowX / 50)][(rowY / 50)]->isFull == true)
		{

			gen.MapBlocks2D[(rowY / 50)][(rowX / 50)]->isFull = false;
			gen.MapBlocks2D[(rowY / 50)][(rowX / 50)]->setSprite();
			new thread(&MapBlock::renewTimer, gen.MapBlocks2D[(rowY / 50)][(rowX / 50)]);
			certainBug->hunger += 10;
		}
	}
}

void BugsGen::HungerDeath(BugsContent* certainBug)
{
		Bugs.erase(remove(Bugs.begin(), Bugs.end(), certainBug),Bugs.end());
		certainBug = NULL;
		delete certainBug;
}

void BugsGen::OldDeath(BugsContent* certainBug)
{
	certainBug->isAlive = false;
	Bugs.erase(remove(Bugs.begin(), Bugs.end(), certainBug), Bugs.end());
	certainBug = NULL;
	delete certainBug;
}

bool BugsGen::bugsCopulation(BugsContent* certainBug)
{
	if (certainBug->readyToCopulate == true)
	{
		for (BugsContent* i : Bugs)
		{
			if (i != certainBug && certainBug->sprite.getGlobalBounds().intersects(i->sprite.getGlobalBounds()))
			{
				certainBug->readyToCopulate = false;
				i->readyToCopulate = false;
				for (int y = 0;y < certainBug->children;y++)
				{
					Bugs.push_back(new BugsContent(certainBug->pos.x, certainBug->pos.y,txt));
					Bugs.back()->readyToCopulate = false;
				}
				return true;
			}
		}
	}
	return false;
}

void BugsGen::Growing(BugsContent* certainBug)
{
	if (certainBug->maxAge != certainBug->age &&(certainBug->lifeSeconds > certainBug->age * 10))
	{
		certainBug->age++;
		certainBug->sprite.scale(certainBug->sprite.getScale().x + 0.25, certainBug->sprite.getScale().y + 0.25);
	}
}




