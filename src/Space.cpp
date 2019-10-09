#include "Space.hpp"

#include <iostream>

#include <SFML/Graphics.hpp>

Space::Space(sf::RenderWindow& window) :
	scene(window),
	window(window)
{

}

void Space::Update()
{
	scene.Update(15);
}

void Space::Render()
{
	Entity& player = scene.GetEntity(player_id);
	camera.x = player.GetPhysicsComponent().pos.x - window.getSize().x / 2;
	camera.y = player.GetPhysicsComponent().pos.y - window.getSize().y / 2;
	window.clear(sf::Color::Black);
	scene.Render(camera);
}

void Space::Load()
{
	player_id = scene.SpawnPlayer();
	for (int i(0); i < 10; ++i) {
		scene.SpawnRock(rand() % 150, rand() % 150);
	}
}

