#include "GameState.h"

GameState::GameState() {


}

void GameState::GameStart(Vector2i dataForStart) {

	// <PART 0> - OBJECTS CREATING AND SETTING STARTING VALUES

	MapGen mapGen;
	Counter counter;
	BugsGen bugsGen;

	mapGen.gridLength = dataForStart.y;
	howManyBugs = dataForStart.x;

	

	RenderWindow window(VideoMode(mapGen.gridLength*50, mapGen.gridLength * 50), "Bugs Civilization!");
	// <PART 1> - MAP AND BUGS FIST GENERATION + BUTTONS LOADING

	bugsGen.LoadTextures();
	window.clear();


	//if (mapGen.gridLength * 50 > VideoMode::getDesktopMode().height)
	//{
	//	mapGen.gridLength = VideoMode::getDesktopMode().height / 50;
	//	font.loadFromFile("fonts/minecraft_font.ttf");
	//	warning.setFont(font);
	//	warning.setCharacterSize(30);
	//	warning.setOutlineColor(Color::Black);
	//	warning.setOutlineThickness(4);
	//	warning.setPosition(VideoMode::getDesktopMode().width / 3, VideoMode::getDesktopMode().height / 2);
	//	warning.setString("Simulation size scalled to your screen resolution");

	//	window.draw(warning);
	//	window.display();
	//	Sleep(2000);
	//	window.clear();
	//}
	mapGen.MapFirstDraw(window);

	bugsGen.bugsFirstDraw(window, howManyBugs);
	window.setFramerateLimit(20);


	Button btnChildren("children", "children");
	Button btnResistance("resistance", "hungerResistance");
	Button btnMaxAge("maxage", "maxAge");
	Button btnMaxCanCopulateSeconds("maxcopulate", "maxCanCopulateSeconds");
	Button btnMaxLifeSeconds("livetimer", "maxLifeSeconds");
	Button btnRenewSeconds("floorrenew", "renewSeconds");
	Button btnAddNewBug("addnewbug", "addNewBug");

	btnAddNewBug.SetPos(0, window.getSize().y - 350);
	btnChildren.SetPos(0, window.getSize().y - 300);
	btnResistance.SetPos(0, window.getSize().y - 250);
	btnMaxAge.SetPos(0, window.getSize().y - 200);
	btnMaxCanCopulateSeconds.SetPos(0, window.getSize().y - 150);
	btnMaxLifeSeconds.SetPos(0, window.getSize().y - 100);
	btnRenewSeconds.SetPos(0, window.getSize().y - 50);

	btnAddNewBug.Draw(window);
	btnChildren.Draw(window);
	btnResistance.Draw(window);
	btnMaxAge.Draw(window);
	btnMaxCanCopulateSeconds.Draw(window);
	btnMaxLifeSeconds.Draw(window);
	btnRenewSeconds.Draw(window);


	for (BugsContent* i : bugsGen.Bugs)
	{
		new thread(&GameState::liveTimer,this, i, ref(bugsGen));
	}

	// <PART 2> - CIVILIZATION WINDOW MAIN LOOP

	while (window.isOpen())
	{
		Event event;
		if (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
				{
					window.close();
				}
			case Event::Closed:
				window.close();
			case Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					if (btnAddNewBug.Hover(window))
					{
						BugsContent* newBug;
						newBug = bugsGen.AddRandomBug(window);
						new thread(&GameState::liveTimer, this, newBug, ref(bugsGen));
					}
					if (btnChildren.Hover(window))
					{

						btnChildren.EditUp(bugsGen, mapGen, window, counter);
					}
					if (btnResistance.Hover(window))
					{
						btnResistance.EditUp(bugsGen, mapGen, window, counter);
					}
					if (btnMaxAge.Hover(window))
					{
						btnMaxAge.EditUp(bugsGen, mapGen, window, counter);
					}
					if (btnMaxCanCopulateSeconds.Hover(window))
					{
						btnMaxCanCopulateSeconds.EditUp(bugsGen, mapGen, window, counter);
					}
					if (btnMaxLifeSeconds.Hover(window))
					{
						btnMaxLifeSeconds.EditUp(bugsGen, mapGen, window, counter);
					}
					if (btnRenewSeconds.Hover(window))
					{
						btnRenewSeconds.EditUp(bugsGen, mapGen, window, counter);
					}
				}
				else if (event.mouseButton.button == sf::Mouse::Right)

				{
					if (btnChildren.Hover(window))
					{
						btnChildren.EditDown(bugsGen, mapGen, window, counter);
					}
					if (btnResistance.Hover(window))
					{
						btnResistance.EditDown(bugsGen, mapGen, window, counter);
					}
					if (btnMaxAge.Hover(window))
					{
						btnMaxAge.EditDown(bugsGen, mapGen, window, counter);
					}
					if (btnMaxCanCopulateSeconds.Hover(window))
					{
						btnMaxCanCopulateSeconds.EditDown(bugsGen, mapGen, window, counter);
					}
					if (btnMaxLifeSeconds.Hover(window))
					{
						btnMaxLifeSeconds.EditDown(bugsGen, mapGen, window, counter);
					}
					if (btnRenewSeconds.Hover(window))
					{
						btnRenewSeconds.EditDown(bugsGen, mapGen, window, counter);
					}
				}
			case Event::MouseMoved:
				if (btnAddNewBug.Hover(window))
				{
					btnAddNewBug.sprite.setColor(Color::Green);
				}
				else
				{
					btnAddNewBug.sprite.setColor(Color::White);
				}

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
		//cout << "Zablokowany moment poruszania" << endl;
		mapGen.MapDrawUpdate(window);
		btnAddNewBug.Draw(window);
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
						new thread(&GameState::liveTimer,this, bugsGen.Bugs.end()[-y], ref(bugsGen));
					}
				}
				if (i != NULL)bugsGen.hungerBehaviour(mapGen, i);
				btnAddNewBug.Draw(window);
				btnChildren.Draw(window);
				btnResistance.Draw(window);
				btnMaxAge.Draw(window);
				btnMaxCanCopulateSeconds.Draw(window);
				btnMaxLifeSeconds.Draw(window);
				btnRenewSeconds.Draw(window);
			}
		}
		Sleep(1);
		locker.unlock();
		cond.notify_all();
		//cout << "Odblokowany moment poruszania" << endl;
		window.display();
	}
}

void GameState::liveTimer(BugsContent* certainBug, BugsGen& bugsGen)
{
	while (certainBug->isAlive == true)
	{
		Sleep(1000);
		certainBug->lifeSeconds++;
		bugsGen.Growing(certainBug);

		if (certainBug->readyToCopulate == false && certainBug->lifeSeconds < certainBug->maxCanCopulateSeconds)
		{
			certainBug->copulateSeconds++;
			if (certainBug->copulateSeconds % 10 == 0)
			{
				certainBug->readyToCopulate = true;
			}
		}
		else if (certainBug->lifeSeconds > certainBug->maxLifeSeconds)
		{
			//cout << "Po czasie robak usuniety | Robakow jest: " << bugsGen.Bugs.size() << endl;
			unique_lock<mutex> locker(mu);
			//cout << "Locker zamkniety" << endl;
			cond.wait(locker);
			//cout << "Warunek odebrany USUWAMY" << endl;
			bugsGen.OldDeath(certainBug);
			//cout << "Robak usuniety, jest ich: " << bugsGen.Bugs.size() << endl;
			break;
		}
	}
	//cout << "THREAD ZAKONCZONY" << endl;
}
