#pragma once

#include <SFML/Graphics.hpp>

class Button
{
public:
	Button(std::string text, sf::Rect bounds);
	void Render(sf::RenderWindow& window);
	void IsSelected();

	std::string text;
	sf::Rect bounds;
	bool selected;
};

class Menu
{
public:
	Menu(sf::RenderWindow& window);

	void Update(int dt);
	void Render();
};
