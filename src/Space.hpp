#pragma once

#include "Scene.hpp"

#include <SFML/Graphics.hpp>

class Scene;

class Space
{
private:
	Scene scene;
	int refreshPeriod = 25;
	int player_id;
	sf::RenderWindow& window;
public:
	Space(sf::RenderWindow& window);
	int GetRefreshPeriod()
	{
		return refreshPeriod;
	}
	void Update();
	void Render();
	void Load();
};

