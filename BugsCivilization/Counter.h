#pragma once
#include "BugsContent.h"
#include "MapBlock.h"


class Counter
{
private:
	void setFont();

	Font font;
	Text text;
	Vector2f pos;
	String varToString;
public:
	Counter();
	void Update(RenderWindow&, bool, int, int);
	void Update(RenderWindow&, int, int, int);
};

