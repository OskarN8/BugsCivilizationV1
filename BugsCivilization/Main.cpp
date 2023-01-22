#include "Main.h"

int main()
{
	//HWND hWnd = GetConsoleWindow();
	//ShowWindow(hWnd, SW_HIDE);

	StartMenu startMenu;
	Vector2i data = startMenu.Open();

	GameState gameState;
	gameState.GameStart(data);
}
