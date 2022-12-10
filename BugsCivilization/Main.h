#include <mutex>
#include <SFML/Graphics.hpp>
#include "MapBlock.h"
#include "MapGen.h"
#include "BugsGen.h"
#include <time.h>
#include <iostream>
#include <conio.h>
#include <windows.h>

int howManyBugs, counter = 0;
mutex mu;
unique_lock<mutex> locker;
condition_variable cond;

	void liveTimer(BugsContent*, BugsGen&);








