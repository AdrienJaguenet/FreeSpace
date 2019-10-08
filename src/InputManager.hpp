#pragma once

#include <SDL2/SDL.h>
#include "GameState.hpp"

class InputManager
{
public:
	virtual GameState OnClick(const SDL_MouseButtonEvent& e) = 0;
	virtual GameState OnKeyDown(const SDL_KeyboardEvent& e) = 0;
	virtual GameState OnQuit() = 0;
};

