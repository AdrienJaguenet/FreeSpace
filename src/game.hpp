#pragma once

#include "GameState.hpp"
#include "InputManager.hpp"

#include "Space.hpp"
#include "SpaceInputManager.hpp"

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
	unsigned int latest_tick, delta_tick;
	int offset_x, offset_y;
	Space space;
	InputManager* input_manager;
	SpaceInputManager space_input_manager;
};
