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
		player->StartThrusting();
		break;
	case sf::Keyboard::Key::LShift:
		player->StartBoost();
		break;

	}
	return GameState::GAME_STATE_RUNNING;
}

GameState SpaceInputManager::OnKeyUp(const sf::Event::KeyEvent& e)
{
	Entity* player = &(space.GetPlayerEntity());
	switch (e.code) {
	case sf::Keyboard::Key::W:
		player->StopThrusting();
		break;
	case sf::Keyboard::Key::LShift:
		player->StopBoost();
		break;

	case sf::Keyboard::Key::Space:
		space.GetScene().ShootProjectile(*player);
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
	Entity* player = &(space.GetPlayerEntity());
	float dx = space.GetCamera().x + e.x - player->GetPhysicsComponent().pos.x;
	float dy = space.GetCamera().y + e.y - player->GetPhysicsComponent().pos.y;
	player->GetPhysicsComponent().yaw = atan2f(dx, -dy);
	return GameState::GAME_STATE_RUNNING;
}
