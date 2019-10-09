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
	return GameState::GAME_STATE_RUNNING;
}

GameState SpaceInputManager::OnKeyUp(const sf::Event::KeyEvent& e)
{
	Entity* player = &(space.GetPlayerEntity());
	switch (e.code) {
	case sf::Keyboard::Key::W:
		player->StopMovingUpwards();
		break;

	case sf::Keyboard::Key::S:
		player->StopMovingDownwards();
		break;

	case sf::Keyboard::Key::A:
		player->StopMovingLeftwards();
		break;

	case sf::Keyboard::Key::D:
		player->StopMovingRightwards();
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
