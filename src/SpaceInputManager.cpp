#include "SpaceInputManager.hpp"

SpaceInputManager::SpaceInputManager(Space &d) :
	space(d)
{

}

GameState SpaceInputManager::OnClick(const sf::Event::MouseButtonEvent& e)
{

}

GameState SpaceInputManager::OnKeyDown(const sf::Event::KeyEvent& e)
{
	switch (e.code) {
	case sf::Keyboard::Key::W:
		player->MoveUpwards();
		break;

	case sf::Keyboard::Key::S:
		player->MoveDownwards();
		break;

	case sf::Keyboard::Key::A:
		player->MoveLeftwards();
		break;

	case sf::Keyboard::Key::D:
		player->MoveRightwards();
		break;
	}
}

GameState SpaceInputManager::OnQuit()
{

}
