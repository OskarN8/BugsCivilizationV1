#include "StartMenu.h"

StartMenu::StartMenu() {
	SetUpBG();
	SetUpButtonsTxt();
	
}

Vector2i StartMenu::Open() {

	RenderWindow window(VideoMode(1280, 720), "Bugs Civilization!");
	SetUpSprites(window);
	dataForGameState.x = 5;
	dataForGameState.y = 15;

	while (window.isOpen())
	{
		window.draw(sprite);
		window.draw(buttonBugsNumber);
		window.draw(buttonWinSize);
		window.draw(buttonPlay);
		if (winSize * 50 >= VideoMode::getDesktopMode().height)
		{
			font.loadFromFile("fonts/minecraft_font.ttf");
			warning.setFont(font);
			warning.setCharacterSize(20);
			warning.setOutlineColor(Color::Black);
			warning.setOutlineThickness(4);
			warning.setPosition(window.getSize().x /7, window.getSize().y / 4 );
			warning.setString("Simulation size will be scalled to your screen resolution for better experience");

			window.draw(warning);
			//window.display();
		}

		Event event;
		if (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				exit(0);
			case Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					if (Hover(window, buttonBugsNumber))
					{
						howManyBugs++;
						counter.Update(window, howManyBugs, buttonBugsNumber.getPosition().x+155, buttonBugsNumber.getPosition().y+20);
						window.display();
						Sleep(100);
					}
					if (Hover(window, buttonWinSize))
					{
						winSize++;
						counter.Update(window, winSize, buttonWinSize.getPosition().x + 155, buttonWinSize.getPosition().y + 20);


						window.display();
						Sleep(100);
					}
					if (Hover(window, buttonPlay))
					{
						window.close();
					}
				}
				else if (event.mouseButton.button == sf::Mouse::Right)

				{
					if (Hover(window, buttonBugsNumber))
					{
						if (howManyBugs > 2)
						{
							howManyBugs--;
							counter.Update(window, howManyBugs, buttonBugsNumber.getPosition().x + 155, buttonBugsNumber.getPosition().y + 20);
							dataForGameState.x = howManyBugs;
						}
						else
						{
							font.loadFromFile("fonts/minecraft_font.ttf");
							warning.setFont(font);
							warning.setCharacterSize(20);
							warning.setOutlineColor(Color::Black);
							warning.setOutlineThickness(4);
							warning.setPosition(buttonBugsNumber.getPosition().x + 155, buttonBugsNumber.getPosition().y + 20);
							warning.setString("Minimum bugs count is 2");

							window.draw(warning);
							//window.display();

						}
						window.display();
						Sleep(100);
					}
					if (Hover(window, buttonWinSize))
					{
						if (winSize > 5)
						{
							winSize--;
							counter.Update(window, winSize, buttonWinSize.getPosition().x + 155, buttonWinSize.getPosition().y + 20);
							
						}
						else 
						{
							dataForGameState.y = VideoMode::getDesktopMode().height / 50;
							font.loadFromFile("fonts/minecraft_font.ttf");
							warning.setFont(font);
							warning.setCharacterSize(20);
							warning.setOutlineColor(Color::Black);
							warning.setOutlineThickness(4);
							warning.setPosition(buttonWinSize.getPosition().x + 155, buttonWinSize.getPosition().y + 20);
							warning.setString("Simulation size can t be smaller than 5");

							window.draw(warning);
							//window.display();

						}
						window.display();
						Sleep(100);
					}

				}
			case Event::MouseMoved:
				
				if (Hover(window, buttonBugsNumber))
				{
					buttonBugsNumber.setColor(Color::Green);
				}
				else
				{
					buttonBugsNumber.setColor(Color::White);
				}
				if (Hover(window, buttonWinSize))
				{
					buttonWinSize.setColor(Color::Green);
				}
				else
				{
					buttonWinSize.setColor(Color::White);
				}
				if (Hover(window, buttonPlay))
				{
					buttonPlay.setColor(Color::Green);
				}
				else
				{
					buttonPlay.setColor(Color::White);
				}
			}
		}
		window.display();
	}
	dataForGameState = Vector2i(howManyBugs, winSize);
	if (winSize * 50 >= VideoMode::getDesktopMode().height)
	{
		dataForGameState.y = (VideoMode::getDesktopMode().height / 50) - 2;
	}
	return dataForGameState;
}

void StartMenu::SetUpBG() {
	txt.loadFromFile("images/lavaBG2.jpg");
}

void StartMenu::SetUpButtonsTxt() {
	txtBugsNumber.loadFromFile("images/txtBugsNumber.png");
	txtWinSize.loadFromFile("images/txtWinSize.png");
	txtPlay.loadFromFile("images/txtPlay.png");
}

void StartMenu::SetUpSprites(RenderWindow& window) {
	sprite.setTexture(txt);
	sprite.setPosition(0, 0);

	buttonBugsNumber.setTexture(txtBugsNumber);
	buttonBugsNumber.setPosition(window.getSize().x / 2 - 90, window.getSize().y / 3);

	buttonWinSize.setTexture(txtWinSize);
	buttonWinSize.setPosition(window.getSize().x / 2 - 90, window.getSize().y / 3 + 100);

	buttonPlay.setTexture(txtPlay);
	buttonPlay.setPosition(window.getSize().x / 2 - 90, window.getSize().y / 3 + 200);
}


bool StartMenu::Hover(RenderWindow& window, Sprite button)
{
	if (button.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))))
	{
		return true;
	}
	return false;
}