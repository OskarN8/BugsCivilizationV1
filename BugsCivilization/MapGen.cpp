#include "MapGen.h"


void MapGen::MapFirstDraw(RenderWindow& win)
{
	for (int y = 0; y < gridLengthY; y++)
	{
		for (int x = 0; x < gridLengthX; x++)
		{
			Blocks.push_back(new MapBlock(x * 50, y * 50));
			win.draw(Blocks[counter]->sprite);
			counter++;
		}
		MapBlocks2D.push_back(Blocks);
		Blocks.clear();
		counter = 0;
	}
}

void MapGen::MapDrawUpdate(RenderWindow& win)
{
	for (int y = 0; y < gridLengthY; y++)
	{
		for (int x = 0; x < gridLengthX; x++)
		{
			win.draw(MapBlocks2D[y][x]->sprite);
		}
	}
}


