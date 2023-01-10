#pragma once
#include "BugsContent.h"
#include "MapBlock.h"


class Counter
{
public:
	Counter();
	//Counter(int* ,int,int);
	void Update(RenderWindow&,bool,int,int);
	void Update(RenderWindow&,int,int,int);
	void setFont();

	Font font;
	Text text;
	Vector2f pos;
	String varToString;
};

