#include "BugsGen.h"
#include <string.h>


void BugsGen::bugsFirstDraw(RenderWindow& win, int howMany)
{

	default_random_engine gen(time(NULL)+rand());


	for (int i = 0; i < howMany; i++)
	{
		uniform_int_distribution<int> distX(1, 4);
		uniform_int_distribution<int> distY(1, 4);


		Bugs.push_back(new BugsContent(distX(gen) * 50, distY(gen) * 50));
		win.draw(Bugs[i]->sprite);

	}
}

void BugsGen::movingPath(RenderWindow& win, BugsContent* certainBug,int counter)
{

	if (needNewEndPosition == true)
	{

		default_random_engine gen(std::chrono::system_clock::now().time_since_epoch().count());

		uniform_int_distribution<int> dirX(50, 450);
		uniform_int_distribution<int> dirY(50, 450);


		needNewEndPosition = false;

		endPosition = Vector2f(int(dirX(gen)), int(dirY(gen)));
	}
	else if (certainBug->pos != endPosition)
	{

		(certainBug->pos.x < endPosition.x) ? certainBug->pos.x += 1 : certainBug->pos.x -= 1;

		if (certainBug->pos != endPosition)
		{
			(certainBug->pos.y < endPosition.y) ? certainBug->pos.y += 1 : certainBug->pos.y -= 1;

		}
		certainBug->sprite.setPosition(certainBug->pos);
		win.draw(certainBug->sprite);
	}
	else if (certainBug->pos == endPosition)
	{
		needNewEndPosition = true;
	}

	}


void BugsGen::hungerBehaviour(MapGen& gen, BugsContent* certainBug)
{
	

	certainBug->hunger -= 1;
	cout << certainBug->hunger << endl;

	if (certainBug->hunger < 0 && certainBug->hungerResistance == false)
	{
		bugsHungerDeath(certainBug);
	    certainBug = NULL;
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

void BugsGen::bugsHungerDeath(BugsContent* certainBug)
{
		Bugs.erase(remove(Bugs.begin(), Bugs.end(), certainBug),Bugs.end());
		certainBug = NULL;
		delete certainBug;

}

//void::BugsGen::liveTimer(BugsContent* certainBug)
//{
//
//	Sleep(20000);
//	//unique_lock<mutex> locker(mu);
//	cout << "Locker timera zamkniety " << endl;
//	//cond.wait(locker);
//	cout << "Timer po warunku " << endl;
//
//
//
//	if (Bugs.size() >= 1 && certainBug != NULL)
//	{
//		Bugs.erase(remove(Bugs.begin(), Bugs.end(), certainBug), Bugs.end());
//		try
//		{
//			delete certainBug;
//		}
//		catch (...)
//		{
//			cerr << " cos " << endl;
//		}
//	}
//	cout << "koniec timera " << endl;
//}

