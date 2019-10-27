#include "MenuInputManager.hpp"

MenuInputManager::MenuInputManager(Menu &d) :
	menu(d)
{

}

GameState MenuInputManager::OnClick(const sf::Event::MouseButtonEvent& e)
{
	return GameState::GAME_STATE_MENU;
}

GameState MenuInputManager::OnKeyDown(const sf::Event::KeyEvent& e)
{
	return GameState::GAME_STATE_MENU;
}

GameState MenuInputManager::OnKeyUp(const sf::Event::KeyEvent& e)
{
	return GameState::GAME_STATE_MENU;
}

GameState MenuInputManager::OnQuit()
{
	return GameState::GAME_STATE_QUIT;
}

GameState MenuInputManager::OnMouseMoved(const sf::Event::MouseMoveEvent& e)
{
	return GameState::GAME_STATE_MENU;
}
