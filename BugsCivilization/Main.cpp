#include "Main.h"

using namespace std;

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

	Button btn("btn", "children");
	btn.SetPos(450, 450);
	btn.Draw(window);


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
			switch (event.type)
			{
			case Event::Closed:
				window.close();
			case Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left)
				
				{
					if (btn.Hover(window))
					{
						btn.EditUp(bugsGen, mapGen);
					}
				}
				else if (event.mouseButton.button == sf::Mouse::Right)

				{
					if (btn.Hover(window))
					{
						btn.EditDown(bugsGen,mapGen);
					}
				}
			case Event::MouseMoved:
				if (btn.Hover(window))
				{
					btn.sprite.setColor(Color::Green);
				}
				else
				{
					btn.sprite.setColor(Color::White);
				}
			}
		}

		unique_lock<mutex> locker(mu);
		cout << "Zablokowany moment poruszania" << endl;
		mapGen.MapDrawUpdate(window);
		btn.Draw(window);
		if (bugsGen.Bugs.size() > 0)
		{
			vector<BugsContent*> actualBugs = bugsGen.Bugs;
			for (BugsContent* i : actualBugs)
			{

				if (i != NULL)bugsGen.movingPath(window, i);


				if (i != NULL && bugsGen.bugsCopulation(i) == true)
				{
					for (int y = 1; y <= i->children;y++)
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

		bugsGen.Growing(certainBug);

		if (certainBug->readyToCopulate == false)
		{
			certainBug->copulateSeconds++;
			if (certainBug->copulateSeconds % 5 == 0)
			{
				certainBug->readyToCopulate = true;
			}
		}

		else if (certainBug->lifeSeconds > certainBug->maxLifeSeconds)
		{
			cout << "Mamy 7 SEKUND | Robakow jest: " << bugsGen.Bugs.size() << endl;
			unique_lock<mutex> locker(mu);
			cout << "Locker zamkniety" << endl;
			cond.wait(locker);
			cout << "Warunek odebrany USUWAMY" << endl;
			bugsGen.OldDeath(certainBug);
			cout << "Robak usuniety, jest ich: " << bugsGen.Bugs.size() << endl;

			break;

		}
	}
	cout << "THREAD ZAKONCZONY" << endl;

}

