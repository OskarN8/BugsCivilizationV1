#include <mutex>
#include <SFML/Graphics.hpp>
#include "MapBlock.h"
#include "MapGen.h"
#include "BugsGen.h"
#include "Button.h"
#include <time.h>
#include <iostream>
#include <conio.h>
#include <windows.h>


int howManyBugs;
mutex mu;
unique_lock<mutex> locker;
condition_variable cond;

void liveTimer(BugsContent*, BugsGen&);








