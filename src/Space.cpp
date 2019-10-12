#include "Space.hpp"

#include <iostream>
#include <sstream>
#include <iomanip>

#include <SFML/Graphics.hpp>

Space::Space(sf::RenderWindow& window) :
	scene(window),
	window(window)
{
	hudFont.loadFromFile("res/pixelplay.ttf");
	hudText.setFont(hudFont);
	hudText.setCharacterSize(16);
	hudText.setColor(sf::Color::White);

}

void Space::Update(int dt)
{
	scene.Update(dt);
}

void Space::Render()
{
	camera.x = scene.GetPhysicsComponent(player)->pos.x - window.getSize().x / 2;
	camera.y = scene.GetPhysicsComponent(player)->pos.y - window.getSize().y / 2;
	window.clear(sf::Color::Black);
	scene.Render(camera);
	RenderHUD();
}

void Space::RenderHUD()
{
	// C++ bullshit
	std::ostringstream ss;

	std::string str = ss.str();

	hudText.setString(str);
	window.draw(hudText);
}

void Space::Load()
{
	player = scene.SpawnPlayer();
	for (int i(0); i < 5; ++i) {
		scene.SpawnOrangium(rand() % 6000, rand() % 6000);
		scene.SpawnGreenine(rand() % 6000, rand() % 6000);
	}
}

