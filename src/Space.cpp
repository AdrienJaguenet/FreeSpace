#include "Space.hpp"

#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>

#include <SFML/Graphics.hpp>

template <typename T>
T clamp(const T& n, const T& lower, const T& upper)
{
	return std::max(lower, std::min(n, upper));
}

Space::Space(sf::RenderWindow& window) :
	scene(window),
	window(window),
	resourceHudDisplay(sf::Vector2f(50, 50))
{
	hudFont.loadFromFile("res/pixelplay.ttf");
	hudText.setFont(hudFont);
	hudText.setCharacterSize(24);
	hudText.setColor(sf::Color::White);
	uiBackground.loadFromFile("res/ui_bg.jpg");
	uiHorizontalBorder.loadFromFile("res/ui_border.jpg");
	orangiumIconTexture.loadFromFile("res/orangium_icon.png");
	greenineIconTexture.loadFromFile("res/greenine_icon.png");
	playerMiniatureTexture.loadFromFile("res/miniature_green.png");
	orangiumIcon.setTexture(orangiumIconTexture);
	greenineIcon.setTexture(greenineIconTexture);
	playerMiniature.setTexture(playerMiniatureTexture);
	uiBackground.setRepeated(true);
	uiHorizontalBorder.setRepeated(true);

	resourceHudDisplay.setFillColor(sf::Color::Black);
	resourceHudDisplay.setOutlineColor(sf::Color::White);
	resourceHudDisplay.setOutlineThickness(2.f);

	minimapRectangle.setFillColor(sf::Color(0.f, 0.f, 0.f, 128.f));
	minimapRectangle.setOutlineColor(sf::Color::White);
	minimapRectangle.setOutlineThickness(2.f);
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

void Space::RenderMinimap()
{
	static int minimapSize(200);
	int playerX = clamp(0.f, scene.GetPhysicsComponent(player)->pos.x * (float) minimapSize / 3000.f, (float) minimapSize),
	    playerY = clamp(0.f, scene.GetPhysicsComponent(player)->pos.y * (float) minimapSize / 3000.f, (float) minimapSize);
	minimapRectangle.setSize(sf::Vector2f(minimapSize, minimapSize));
	minimapRectangle.setPosition(window.getSize().x - minimapSize - 20, window.getSize().y - minimapSize - 20);
	playerMiniature.setPosition(sf::Vector2f(window.getSize().x - minimapSize - 20 + playerX, window.getSize().y - minimapSize - 20 + playerY));
	playerMiniature.setRotation(scene.GetPhysicsComponent(player)->yaw * 180.f / M_PI);
	window.draw(minimapRectangle);
	window.draw(playerMiniature);
}

void Space::RenderHUD()
{
	resourceHudDisplay.setPosition(sf::Vector2f(20, window.getSize().y - 114));
	orangiumIcon.setPosition(sf::Vector2f(29, window.getSize().y - 105));
	hudText.setString(std::to_string(scene.GetResourceCollectorComponent(player)->reserves["orangium"]));
	hudText.setPosition(sf::Vector2f(85, window.getSize().y - 105));
	window.draw(resourceHudDisplay);
	window.draw(orangiumIcon);
	window.draw(hudText);
	resourceHudDisplay.setPosition(sf::Vector2f(20, window.getSize().y - 59));
	greenineIcon.setPosition(sf::Vector2f(29, window.getSize().y - 50));
	hudText.setPosition(sf::Vector2f(85, window.getSize().y - 50));
	hudText.setString(std::to_string(scene.GetResourceCollectorComponent(player)->reserves["greenine"]));
	window.draw(resourceHudDisplay);
	window.draw(greenineIcon);
	window.draw(hudText);
	RenderMinimap();
}

void Space::Load()
{
	player = scene.SpawnPlayer();
	for (int i(0); i < 5; ++i) {
		scene.SpawnOrangium(rand() % 3000, rand() % 3000);
		scene.SpawnGreenine(rand() % 3000, rand() % 3000);
		scene.SpawnPirate(rand() % 3000, rand() % 3000);
	}
}

