#ifndef BUGSGENH
#define BUGSGENH


#include <SFML/Graphics.hpp>
#include <random>
#include <ctime>
#include <vector>
#include "BugsContent.h"
#include "MapGen.h"
#include <mutex>
#include <string.h>


	


class BugsGen
{
public:

	vector<BugsContent*> Bugs;
	void bugsFirstDraw(RenderWindow&, int);
	void movingPath(RenderWindow&, BugsContent*);
	void hungerBehaviour(MapGen&, BugsContent*);
	void bugsHungerDeath(BugsContent*);
	void bugsCopulation(BugsContent*);
	void CopulationTimer(BugsContent*);

};

#endif

