#include "MapGen.h"


void MapGen::MapFirstDraw(RenderWindow& win)
{
	gridLength = 20;



	for (int y = 0; y < gridLength; y++)
	{
		for (int x = 0; x < gridLength; x++)
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
	gridLength = 20;

	for (int y = 0; y < gridLength; y++)
	{
		for (int x = 0; x < gridLength; x++)
		{
			win.draw(MapBlocks2D[x][y]->sprite);
		}
	}
}


