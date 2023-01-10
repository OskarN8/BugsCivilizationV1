#include "Counter.h"

Counter::Counter() {

	setFont();
	text.setFont(font);
	text.setCharacterSize(19);
	//text.setColor(Color::White);
	text.setOutlineColor(Color::Black);
	text.setOutlineThickness(4);
}

void Counter::setFont() {
	font.loadFromFile("fonts/minecraft_font.ttf");
}

void Counter::Update(RenderWindow& win,int var,int x ,int y) {
	pos = Vector2f(x, y);
	text.setPosition(pos);

	varToString = to_string(var);
	text.setString(varToString);
	win.draw(text);
}

void Counter::Update(RenderWindow& win, bool var, int x, int y) {
	pos = Vector2f(x, y);
	text.setPosition(pos);

	varToString = to_string(var);
	text.setString(varToString);
	win.draw(text);
}