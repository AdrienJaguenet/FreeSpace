#pragma once

#include "GameState.hpp"
#include "InputManager.hpp"

#include "Space.hpp"
#include "SpaceInputManager.hpp"

#include <SFML/Window.hpp>
#include <vector>
#include <string>

class Game
{
public:
	GameState state;

	Game(std::vector<std::string> &args);
	void Update();
	void ProcessEvent(sf::Event &e);
	void Quit();
	void Render();
	sf::Window& getWindow() { return window; }

private:
	sf::Window window;
	sf::Clock clock;
	unsigned int latest_tick, delta_tick;
	int offset_x, offset_y;
	Space space;
	InputManager* input_manager;
	SpaceInputManager space_input_manager;
};
