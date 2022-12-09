#include <SFML/Graphics.hpp>
#include "Main.h"
#include "MapBlock.h"
#include "MapGen.h"
#include "BugsGen.h"
#include <time.h>
#include <iostream>
#include <conio.h>
#include <windows.h>



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

		mapGen.MapDrawUpdate(window);
		for (BugsContent* i : bugsGen.Bugs)
		{
			if(i != NULL) bugsGen.movingPath(window, i);
			if (i != NULL) bugsGen.hungerBehaviour(mapGen, i);
				
			

			//{
			//	bugsGen.bugsHungerDeath(i);
			//}
		}

		Sleep(1);
		window.display();

	}
	return 0;
}


