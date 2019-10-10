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
	Entity* player = &(space.GetPlayerEntity());
	switch (e.code) {
	case sf::Keyboard::Key::W:
		space.GetScene().GetInputSystem().StartThrusting();
		break;
	case sf::Keyboard::Key::LShift:
		space.GetScene().GetInputSystem().StartBoost();
		break;

	}
	return GameState::GAME_STATE_RUNNING;
}

GameState SpaceInputManager::OnKeyUp(const sf::Event::KeyEvent& e)
{
	Entity* player = &(space.GetPlayerEntity());
	switch (e.code) {
	case sf::Keyboard::Key::W:
		space.GetScene().GetInputSystem().StopThrusting();
		break;
	case sf::Keyboard::Key::LShift:
		space.GetScene().GetInputSystem().StopBoost();
		break;

	case sf::Keyboard::Key::Space:
		space.GetScene().GetInputSystem().Fire();
		break;
	}

	return GameState::GAME_STATE_RUNNING;
}

GameState SpaceInputManager::OnQuit()
{
	return GameState::GAME_STATE_QUIT;
}

GameState SpaceInputManager::OnMouseMoved(const sf::Event::MouseMoveEvent& e)
{
	space.GetScene().GetInputSystem().LookAt(space.GetCamera().x + e.x, space.GetCamera().y + e.y);
	return GameState::GAME_STATE_RUNNING;
}
