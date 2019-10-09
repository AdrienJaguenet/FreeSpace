#pragma once

#include <SFML/Window.hpp>

#include "GameState.hpp"

class InputManager
{
public:
	virtual GameState OnClick(const sf::Event::MouseButtonEvent& e) = 0;
	virtual GameState OnKeyDown(const sf::Event::KeyEvent& e) = 0;
	virtual GameState OnKeyUp(const sf::Event::KeyEvent& e) = 0;
	virtual GameState OnQuit() = 0;
};

