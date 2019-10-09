#pragma once

#include "Space.hpp"
#include "InputManager.hpp"

class SpaceInputManager : public InputManager
{
private:
	Space& space;
public:
	SpaceInputManager(Space &d);
	GameState OnClick(const sf::Event::MouseButtonEvent& e);
	GameState OnKeyDown(const sf::Event::KeyEvent& e);
	GameState OnKeyUp(const sf::Event::KeyEvent& e);
	GameState OnMouseMoved(const sf::Event::MouseMoveEvent& e);
	GameState OnQuit();
};

