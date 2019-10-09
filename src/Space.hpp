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
	int player_id;
	sf::RenderWindow& window;
	Camera camera;
	sf::Font hudFont;
	sf::Text hudText;
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
		return scene.GetEntity(player_id);
	}
	Scene& GetScene()
	{
		return scene;
	}
};

