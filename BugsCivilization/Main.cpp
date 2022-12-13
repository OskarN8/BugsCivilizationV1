#include "Main.h"



int main()
{

	RenderWindow window(VideoMode(500, 500), "Bugs Civilization!");
	MapGen mapGen;
	BugsGen bugsGen;
	howManyBugs = 5;
	// <PART 1> - MAP AND BUGS FIST GENERATION
	window.clear();
	mapGen.MapFirstDraw(window);
	bugsGen.bugsFirstDraw(window, howManyBugs);

	for (BugsContent* i : bugsGen.Bugs)
	{
		new thread(&liveTimer, i, ref(bugsGen));
		new thread(&BugsGen::CopulationTimer, bugsGen, i);

	}
	// <END PART1>

	while (window.isOpen())
	{
		Event event;
		if (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}
		unique_lock<mutex> locker(mu);
		mapGen.MapDrawUpdate(window);
		if (bugsGen.Bugs.size() > 0)
		{
			for (BugsContent* i : bugsGen.Bugs)
			{
				
				bugsGen.movingPath(window, i);
				bugsGen.hungerBehaviour(mapGen, i);
				if (bugsGen.bugsCopulation(i) == true)
				{
					new thread(&liveTimer, i, ref(bugsGen));
					new thread(&BugsGen::CopulationTimer,bugsGen,i);
				}
			}

		}
		Sleep(1);
		locker.unlock();
		cond.notify_all();
		window.display();
	}
	return 0;
}

void liveTimer(BugsContent* certainBug, BugsGen& bugsGen)
{
	Sleep(30000);
	unique_lock<mutex> locker(mu);
	cout << "Locker zamkniety" << endl;
	cond.wait(locker);
	bugsGen.Bugs.erase(remove(bugsGen.Bugs.begin(), bugsGen.Bugs.end(), certainBug), bugsGen.Bugs.end());
	certainBug = NULL;
	delete certainBug;
}

