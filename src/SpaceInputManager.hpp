#pragma once

#include "Space.hpp"
#include "InputManager.hpp"

class SpaceInputManager : public InputManager
{
private:
	Space& space;
	Entity* player;
public:
	SpaceInputManager(Space &d);
	GameState OnClick(const sf::Event::MouseButtonEvent& e);
	GameState OnKeyDown(const sf::Event::KeyEvent& e);
	GameState OnQuit();
	void SetPlayer(Entity* ent)
	{
		player = ent;
	}
};

