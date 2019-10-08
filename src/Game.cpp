#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>

#include "Game.hpp"
#include "Util.hpp"

Game::Game(std::vector<std::string>& args) :
	space_input_manager(space),
	input_manager(&space_input_manager),
	window(sf::VideoMode(600, 400), "FreeSpace"),
	space(window)
{
	srand(time(NULL));

	space.Load();

	this->state = GAME_STATE_RUNNING;
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
	default:
		break;
	}
}

void Game::Update()
{
	static int turn_count(0);
	this->delta_tick = clock.restart().asMilliseconds();
	if (delta_tick < space.GetRefreshPeriod()) {
		sf::sleep(sf::milliseconds(space.GetRefreshPeriod() - delta_tick));
		return;
	} else {
		++turn_count;
		space.Update();
	}
}

void Game::Render()
{
	space.Render();
	window.display();
}

