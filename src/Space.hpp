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
	sf::Texture playerMiniatureTexture;
	sf::Sprite playerMiniature;
	sf::Sprite orangiumIcon;
	sf::Sprite greenineIcon;
	sf::RectangleShape resourceHudDisplay;
	sf::RectangleShape minimapRectangle;
	sf::RectangleShape healthRectangle;
	Entity player;
	void RenderHUD();
	void RenderMinimap();
	void RenderHealthBar();
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

