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
  hudText.setCharacterSize(24);
  hudText.setFillColor(sf::Color::White);
  
}

void Space::Update(int dt)
{
	scene.Update(dt);
}

void Space::Render()
{
	Entity& player = scene.GetEntity(player_id);
	camera.x = player.GetPhysicsComponent().pos.x - window.getSize().x / 2;
	camera.y = player.GetPhysicsComponent().pos.y - window.getSize().y / 2;
	window.clear(sf::Color::Black);
	scene.Render(camera);
	RenderHUD();
}

void Space::RenderHUD()
{
  Entity& player = scene.GetEntity(player_id);

  // C++ bullshit
  std::ostringstream ss;
  ss << "X: " << (int)player.GetPhysicsComponent().pos.x
     << std::endl << "Y: "<< (int)player.GetPhysicsComponent().pos.y

  std::string str = ss.str();
  
  hudText.setString(str);
  window.draw(hudText);
}

void Space::Load()
{
	player_id = scene.SpawnPlayer();
	for (int i(0); i < 10; ++i) {
		scene.SpawnRock(rand() % 600, rand() % 600);
	}
}

