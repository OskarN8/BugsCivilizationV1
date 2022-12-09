#ifndef BUGSGENH
#define BUGSGENH


#include <SFML/Graphics.hpp>
#include <random>
#include <ctime>
#include <vector>
#include "BugsContent.h"
#include "MapGen.h"
#include <mutex>



class BugsGen
{
public:
	mutex mu;
	unique_lock<mutex> locker;
	condition_variable cond;


	vector<BugsContent*> Bugs;
	Vector2f oldEndPosiotion, endPosition;
	bool needNewEndPosition = true;
	BugsContent* bug;


	void bugsFirstDraw(RenderWindow&, int);
	void movingPath(RenderWindow&, BugsContent*);
	void hungerBehaviour(MapGen&, BugsContent*);
	void bugsHungerDeath(BugsContent*);
	void liveTimer(BugsContent*);
};

#endif

