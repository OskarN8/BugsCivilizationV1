#include "Main.h"



int main()
{

	RenderWindow window(VideoMode(1000, 1000), "Bugs Civilization!");


	MapGen mapGen;
	BugsGen bugsGen;

	howManyBugs = 10;

	// <PART 1> - MAP AND BUGS FIST GENERATION
	window.clear();
	mapGen.MapFirstDraw(window);
	bugsGen.bugsFirstDraw(window, howManyBugs);

	for (BugsContent* i : bugsGen.Bugs)
	{
		new thread(&liveTimer,i, ref(bugsGen));
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
		int l = 0;
		for (BugsContent* i : bugsGen.Bugs)
		{

			cout <<"Iteruje robaka " << l << endl;
				bugsGen.movingPath(window, i);
				bugsGen.hungerBehaviour(mapGen, i);
				l++;
		}
		
		locker.unlock();
		cond.notify_all();
		Sleep(1);
		window.display();

	}
	return 0;
}

void liveTimer(BugsContent* certainBug, BugsGen& bugsGen)
{
	Sleep(3000);
	unique_lock<mutex> locker(mu);
	cout << "Locker timera zamkniety " << endl;
	cond.wait(locker);
	cout << "Timer po warunku " << endl;


	bugsGen.Bugs.erase(remove(bugsGen.Bugs.begin(), bugsGen.Bugs.end(), certainBug), bugsGen.Bugs.end());


	cout << bugsGen.Bugs.size() << endl;
	//for (auto i : bugsGen.Bugs)
	//{
	//	cout << i << endl;
	//}

	delete certainBug;
	certainBug = NULL;


	cout << "koniec timera " << endl;

}

