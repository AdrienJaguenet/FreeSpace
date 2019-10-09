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
	sf::Texture LoadTexture(const std::string& path);
public:
	Space(sf::RenderWindow& window);
	int GetRefreshPeriod()
	{
		return refreshPeriod;
	}
	void Update();
	void Render();
	void Load();
	Entity& GetPlayerEntity()
	{
		return scene.GetEntity(player_id);
	}
};

