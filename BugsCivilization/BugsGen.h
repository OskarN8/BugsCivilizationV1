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
private:
	Texture txt;
	void HungerDeath(BugsContent*);

public:
	vector<BugsContent*> Bugs;
	BugsContent* AddRandomBug(RenderWindow&);
	bool bugsCopulation(BugsContent*);
	void bugsFirstDraw(RenderWindow&, int);
	void Growing(BugsContent*);
	void hungerBehaviour(MapGen&, BugsContent*);
	void LoadTextures();
	void movingPath(RenderWindow&, BugsContent*);
	void OldDeath(BugsContent*);

};

#endif

