#include <SFML/Graphics.hpp>
#include "Button.h"

using namespace sf;
class StartMenu {

private:
	void SetUpBG();
	void SetUpButtonsTxt();
	void SetUpSprites(RenderWindow& window);
	bool Hover(RenderWindow&, Sprite);

	Font font;
	Text warning;

	Counter counter;

	Texture txt;
	Texture txtBugsNumber;
	Texture txtWinSize;
	Texture txtPlay;

	Sprite sprite;
	Sprite buttonBugsNumber;
	Sprite buttonWinSize;
	Sprite buttonPlay;

	Vector2i dataForGameState;
	int howManyBugs = 5, winSize = 15;
public:
	Vector2i Open();
	StartMenu();

};