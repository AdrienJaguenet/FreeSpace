#include "game.hpp"
#include "util.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>

Game::Game(std::vector<std::string>& args) :
	offset_x(10),
	offset_y(10),
	snake_input_manager(snake),
	input_manager(&snake_input_manager)
{
	int grid_width(20), grid_height(20);
	this->window = SDL_CreateWindow("FreeSnake", SDL_WINDOWPOS_UNDEFINED,
	                                SDL_WINDOWPOS_UNDEFINED,
	                                grid_width * 32 + offset_x * 2, grid_height * 32 + offset_y * 2 + 20, SDL_WINDOW_OPENGL);

	if (!this->window) {
		std::cerr << "Failed to create SDL window: " << SDL_GetError() << std::endl;
		this->state = GAME_STATE_QUIT;
	}

	this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
	if (!this->window) {
		std::cerr << "Failed to create SDL renderer." << SDL_GetError() << std::endl;
		this->state = GAME_STATE_QUIT;
	}

	srand(time(NULL));

	snake.SetRenderer(renderer);
	snake.Load(grid_width, grid_height);

	this->latest_tick = SDL_GetTicks();
	this->state = GAME_STATE_RUNNING;
}

Game::~Game()
{
	if (this->window)
		SDL_HideWindow(this->window);

	if (this->renderer)
		SDL_DestroyRenderer(this->renderer);

	if (this->window)
		SDL_DestroyWindow(this->window);
}

void Game::ProcessEvent(SDL_Event &e)
{
	switch(e.type) {
	case SDL_QUIT:
		state = input_manager->OnQuit();
		break;
	case SDL_KEYDOWN:
		state = input_manager->OnKeyDown(e.key);
		break;
	default:
		break;
	}
}

void Game::Update()
{
	static int turn_count(0);
	unsigned int new_time = SDL_GetTicks();
	this->delta_tick = new_time - this->latest_tick;
	if (delta_tick < snake.GetRefreshPeriod()) {
		SDL_Delay(snake.GetRefreshPeriod() - delta_tick);
		return;
	} else {
		this->latest_tick = new_time;
		++turn_count;
		snake.Update();
	}
}

void Game::Render()
{
	snake.Render(offset_x, offset_y);
}

