#include "Space.hpp"

#include <iostream>
#include <sstream>
#include <iomanip>

#include <SFML/Graphics.hpp>

Space::Space(sf::RenderWindow& window) :
	scene(window),
	window(window),
	resourceHudDisplay(sf::Vector2f(50, 50))
{
	hudFont.loadFromFile("res/pixelplay.ttf");
	hudText.setFont(hudFont);
	hudText.setCharacterSize(16);
	hudText.setColor(sf::Color::White);
	uiBackground.loadFromFile("res/ui_bg.jpg");
	uiHorizontalBorder.loadFromFile("res/ui_border.jpg");
	orangiumIconTexture.loadFromFile("res/orangium_icon.png");
	greenineIconTexture.loadFromFile("res/greenine_icon.png");
	orangiumIcon.setTexture(orangiumIconTexture);
	greenineIcon.setTexture(greenineIconTexture);
	uiBackground.setRepeated(true);
	uiHorizontalBorder.setRepeated(true);

	resourceHudDisplay.setFillColor(sf::Color::Black);
	resourceHudDisplay.setOutlineColor(sf::Color::White);
	resourceHudDisplay.setOutlineThickness(2.f);
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
	resourceHudDisplay.setPosition(sf::Vector2f(20, window.getSize().y - 114));
	orangiumIcon.setPosition(sf::Vector2f(29, window.getSize().y - 105));
	window.draw(resourceHudDisplay);
	window.draw(orangiumIcon);
	resourceHudDisplay.setPosition(sf::Vector2f(20, window.getSize().y - 59));
	greenineIcon.setPosition(sf::Vector2f(29, window.getSize().y - 50));
	window.draw(resourceHudDisplay);
	window.draw(greenineIcon);
}

void Space::Load()
{
	player = scene.SpawnPlayer();
	for (int i(0); i < 5; ++i) {
		scene.SpawnOrangium(rand() % 3000, rand() % 3000);
		scene.SpawnGreenine(rand() % 3000, rand() % 3000);
	}
}

