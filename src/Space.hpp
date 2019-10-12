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
	sf::Texture uiBackground;
	sf::Texture uiHorizontalBorder;
	sf::Texture orangiumIconTexture;
	sf::Texture greenineIconTexture;
	sf::Sprite orangiumIcon;
	sf::Sprite greenineIcon;
	sf::RectangleShape resourceHudDisplay;
	Entity player;
	void RenderHUD();
public:
	Space(sf::RenderWindow& window);
	int GetRefreshPeriod()
	{
		return refreshPeriod;
	}
	void Update(int dt);
	void Render();
	void Load();
	Camera& GetCamera()
	{
		return camera;
	}
	Entity& GetPlayerEntity()
	{
		return player;
	}
	Scene& GetScene()
	{
		return scene;
	}
};

