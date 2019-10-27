#pragma once

#include <cmath>

#include "Menu.hpp"
#include "InputManager.hpp"

class MenuInputManager : public InputManager
{
private:
	Menu& menu;
public:
	MenuInputManager(Menu &d);
	GameState OnClick(const sf::Event::MouseButtonEvent& e);
	GameState OnKeyDown(const sf::Event::KeyEvent& e);
	GameState OnKeyUp(const sf::Event::KeyEvent& e);
	GameState OnMouseMoved(const sf::Event::MouseMoveEvent& e);
	GameState OnQuit();
};

