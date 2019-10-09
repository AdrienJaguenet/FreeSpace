#pragma once

#include "Camera.hpp"
#include "Scene.hpp"

#include <SFML/Graphics.hpp>

class Scene;

class Space
{
private:
	Scene scene;
	int refreshPeriod = 25;
	sf::RenderWindow& window;
	Camera camera;
	sf::Font hudFont;
	sf::Text hudText;
	Entity* player;
public:
	Space(sf::RenderWindow& window);
	int GetRefreshPeriod()
	{
		return refreshPeriod;
	}
	void Update(int dt);
	void Render();
	void RenderHUD();
	void Load();
	Camera& GetCamera()
	{
		return camera;
	}
	Entity& GetPlayerEntity()
	{
		return *player;
	}
	Scene& GetScene()
	{
		return scene;
	}
};

