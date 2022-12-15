#include "Main.h"



int main()
{

	RenderWindow window(VideoMode(500, 500), "Bugs Civilization!");
	MapGen mapGen;
	BugsGen bugsGen;
	howManyBugs = 5;
	// <PART 1> - MAP AND BUGS FIST GENERATION
	bugsGen.LoadTextures();
	window.clear();
	mapGen.MapFirstDraw(window);
	
	bugsGen.bugsFirstDraw(window, howManyBugs);
	window.setFramerateLimit(20);
	
	
	for (BugsContent* i : bugsGen.Bugs)
	{
		new thread(&liveTimer, i, ref(bugsGen));
		//new thread(&BugsGen::CopulationTimer, bugsGen, i);

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
		cout << "Zablokowany moment poruszania" << endl;
		mapGen.MapDrawUpdate(window);
		if (bugsGen.Bugs.size() > 0)
		{
			vector<BugsContent*> actualBugs = bugsGen.Bugs;
			for (BugsContent* i : actualBugs)
			{
				
				if(i!= NULL)bugsGen.movingPath(window, i);
				

				if(i != NULL && bugsGen.bugsCopulation(i) == true)
				{
					for (int y = 1; y <= i->childrens;y++)
					{
						new thread(&liveTimer, bugsGen.Bugs.end()[-y], ref(bugsGen));
					}
				}
				if (i != NULL)bugsGen.hungerBehaviour(mapGen, i);
			}
		}
		Sleep(1);
		locker.unlock();
		cond.notify_all();
		cout << "Odblokowany moment poruszania" << endl;
		window.display();
	}
	return 0;
}

void liveTimer(BugsContent* certainBug, BugsGen& bugsGen)
{

	while (certainBug->isAlive == true)
	{

		Sleep(1000);
		certainBug->lifeSeconds++;

		if (certainBug->maxAge == false)
		{
			bugsGen.Growing(certainBug);
		}

		if (certainBug->readyToCopulate == false)
		{
			certainBug->copulateSeconds++;
			if (certainBug->copulateSeconds % 5 == 0)
			{
				certainBug->readyToCopulate = true;
			}
		}

		else if (certainBug->lifeSeconds > 30)
		{
			cout << "Mamy 7 SEKUND | Robakow jest: "<< bugsGen.Bugs.size() << endl;
			unique_lock<mutex> locker(mu);
			cout << "Locker zamkniety" << endl;
			cond.wait(locker);
			cout << "Warunek odebrany USUWAMY" << endl;
			certainBug->isAlive = false;
			bugsGen.Bugs.erase(remove(bugsGen.Bugs.begin(), bugsGen.Bugs.end(), certainBug), bugsGen.Bugs.end());
			certainBug = NULL;
			delete certainBug;
			
			cout << "Robak usuniety, jest ich: "<<bugsGen.Bugs.size() << endl;
			
			break;

		}
	}
	cout << "THREAD ZAKONCZONY" << endl;

}

