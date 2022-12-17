#include "Main.h"

using namespace std;

int main()
{

	RenderWindow window(VideoMode(600, 500), "Bugs Civilization!");
	MapGen mapGen;
	BugsGen bugsGen;



	howManyBugs = 5;
	// <PART 1> - MAP AND BUGS FIST GENERATION
	bugsGen.LoadTextures();
	window.clear();
	mapGen.MapFirstDraw(window);

	bugsGen.bugsFirstDraw(window, howManyBugs);
	window.setFramerateLimit(20);

	Button btnChildren("children", "children");
	Button btnResistance("resistance", "hungerResistance");
	Button btnMaxAge("maxage", "maxAge");
	Button btnMaxCanCopulateSeconds("maxcopulate", "maxCanCopulateSeconds");
	Button btnMaxLifeSeconds("livetimer", "maxLifeSeconds");
	Button btnRenewSeconds("floorrenew", "renewSeconds");

	btnChildren.SetPos(0, 450);
	btnResistance.SetPos(100, 450);
	btnMaxAge.SetPos(200, 450);
	btnMaxCanCopulateSeconds.SetPos(300, 450);
	btnMaxLifeSeconds.SetPos(400, 450);
	btnRenewSeconds.SetPos(500, 450);

	btnChildren.Draw(window);
	btnResistance.Draw(window);
	btnMaxAge.Draw(window);
	btnMaxCanCopulateSeconds.Draw(window);
	btnMaxLifeSeconds.Draw(window);
	btnRenewSeconds.Draw(window);



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

					if (btnChildren.Hover(window))
					{
						btnChildren.EditUp(bugsGen, mapGen);
					}
					if (btnResistance.Hover(window))
					{
						btnResistance.EditUp(bugsGen, mapGen);
					}
					if (btnMaxAge.Hover(window))
					{
						btnMaxAge.EditUp(bugsGen, mapGen);
					}
					if (btnMaxCanCopulateSeconds.Hover(window))
					{
						btnMaxCanCopulateSeconds.EditUp(bugsGen, mapGen);
					}
					if (btnMaxLifeSeconds.Hover(window))
					{
						btnMaxLifeSeconds.EditUp(bugsGen, mapGen);
					}
					if (btnRenewSeconds.Hover(window))
					{
						btnRenewSeconds.EditUp(bugsGen, mapGen);
					}

				}
				else if (event.mouseButton.button == sf::Mouse::Right)

				{
					if (btnChildren.Hover(window))
					{
						btnChildren.EditDown(bugsGen, mapGen);
					}
					if (btnResistance.Hover(window))
					{
						btnResistance.EditDown(bugsGen, mapGen);
					}
					if (btnMaxAge.Hover(window))
					{
						btnMaxAge.EditDown(bugsGen, mapGen);
					}
					if (btnMaxCanCopulateSeconds.Hover(window))
					{
						btnMaxCanCopulateSeconds.EditDown(bugsGen, mapGen);
					}
					if (btnMaxLifeSeconds.Hover(window))
					{
						btnMaxLifeSeconds.EditDown(bugsGen, mapGen);
					}
					if (btnRenewSeconds.Hover(window))
					{
						btnRenewSeconds.EditDown(bugsGen, mapGen);
					}
				}
			case Event::MouseMoved:
				
				if (btnChildren.Hover(window))
				{
					btnChildren.sprite.setColor(Color::Green);
				}
				else
				{
					btnChildren.sprite.setColor(Color::White);
				}

				if (btnResistance.Hover(window))
				{
					btnResistance.sprite.setColor(Color::Green);
				}
				else
				{
					btnResistance.sprite.setColor(Color::White);
				}

				if (btnMaxAge.Hover(window))
				{
					btnMaxAge.sprite.setColor(Color::Green);
				}
				else
				{
					btnMaxAge.sprite.setColor(Color::White);
				}

				if (btnMaxCanCopulateSeconds.Hover(window))
				{
					btnMaxCanCopulateSeconds.sprite.setColor(Color::Green);
				}
				else
				{
					btnMaxCanCopulateSeconds.sprite.setColor(Color::White);
				}

				if (btnMaxLifeSeconds.Hover(window))
				{
					btnMaxLifeSeconds.sprite.setColor(Color::Green);
				}
				else
				{
					btnMaxLifeSeconds.sprite.setColor(Color::White);
				}

				if (btnRenewSeconds.Hover(window))
				{
					btnRenewSeconds.sprite.setColor(Color::Green);
				}
				else
				{
					btnRenewSeconds.sprite.setColor(Color::White);
				}

			}
		}

		unique_lock<mutex> locker(mu);
		cout << "Zablokowany moment poruszania" << endl;
		mapGen.MapDrawUpdate(window);

		btnChildren.Draw(window);
		btnResistance.Draw(window);
		btnMaxAge.Draw(window);
		btnMaxCanCopulateSeconds.Draw(window);
		btnMaxLifeSeconds.Draw(window);
		btnRenewSeconds.Draw(window);

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

		if (certainBug->readyToCopulate == false && certainBug->lifeSeconds < certainBug->maxCanCopulateSeconds)
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

