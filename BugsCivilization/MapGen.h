#ifndef MAPGENH
#define MAPGENH

#include <vector>
#include <SFML/Graphics.hpp>
#include <random>
#include <ctime>
#include "MapBlock.h"

using namespace std;
using namespace sf;
class MapGen
{
private:
	int counter = 0;
	vector<MapBlock*> Blocks;

public:
	int gridLength = 10;
	vector<vector<MapBlock*>> MapBlocks2D;

	void MapFirstDraw(RenderWindow&);
	void MapDrawUpdate(RenderWindow&);

};

#endif
