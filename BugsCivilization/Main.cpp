#include "Main.h"

int main()
{

	StartMenu startMenu;
	Vector2i data = startMenu.Open();

	GameState gameState;
	gameState.GameStart(data);
}
