#pragma once

#include "GameState.hpp"
#include "InputManager.hpp"
#include "Snake.hpp"
#include "SnakeInputManager.hpp"

#include <SDL2/SDL.h>
#include <vector>
#include <string>

class Game
{
public:
	GameState state;
	SDL_Window *window;
	SDL_Renderer *renderer;

	Game(std::vector<std::string> &args);
	~Game();
	void Update();
	void ProcessEvent(SDL_Event &e);
	void Quit();
	void Render();

private:
	Snake snake;
	unsigned int latest_tick, delta_tick;
	int offset_x, offset_y;
	SnakeInputManager snake_input_manager;
	InputManager* input_manager;
};
