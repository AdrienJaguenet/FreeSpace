#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "GameState.hpp"
#include "InputManager.hpp"
#include "Space.hpp"
#include "SpaceInputManager.hpp"
#include "MenuInputManager.hpp"

class Game
{
public:
	GameState state;

	Game(std::vector<std::string> &args);
	void Update(int);
	void ProcessEvent(sf::Event &e);
	void Quit();
	void Render();
	sf::RenderWindow& getWindow()
	{
		return window;
	}

private:
	sf::RenderWindow window;
	sf::Clock clock;
	unsigned int delta_tick;
	Space space;
	Menu menu;
	InputManager* input_manager;
	SpaceInputManager space_input_manager;
	MenuInputManager menu_input_manager;
};
