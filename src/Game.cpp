#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>

#include "Game.hpp"
#include "Util.hpp"

Game::Game(std::vector<std::string>& args) :
	space_input_manager(space),
	menu_input_manager(menu),
	input_manager(&menu_input_manager),
	window(sf::VideoMode(1000, 800), "FreeSpace"),
	space(window),
	menu(window)
{
	srand(time(NULL));

	space.Load();

	this->state = GAME_STATE_MENU;
}

void Game::ProcessEvent(sf::Event &e)
{
	switch(e.type) {
	case sf::Event::Closed:
		state = input_manager->OnQuit();
		break;
	case sf::Event::KeyPressed:
		state = input_manager->OnKeyDown(e.key);
		break;
	case sf::Event::KeyReleased:
		state = input_manager->OnKeyUp(e.key);
		break;
	case sf::Event::MouseMoved:
		state = input_manager->OnMouseMoved(e.mouseMove);
		break;
	default:
		break;
	}
}

void Game::Update(int dt)
{
	if (state == GAME_STATE_RUNNING)
		space.Update(dt);
	else if (state == GAME_STATE_MENU)
		menu.Update(dt);
}

void Game::Render()
{
	if (state == GAME_STATE_RUNNING)
		space.Render();
	else if (state == GAME_STATE_MENU)
		menu.Render();
	window.display();
}

