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

}

void Space::Render()
{
	window.clear(sf::Color::Black);
	scene.Render(camera);
}

void Space::Load()
{
	player_id = scene.SpawnPlayer();
}

