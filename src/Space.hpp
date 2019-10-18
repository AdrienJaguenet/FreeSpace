#pragma once

#include "Camera.hpp"
#include "ClientScene.hpp"

#include <SFML/Graphics.hpp>

class ClientScene;

class Space
{
private:
	ClientScene scene;
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
	ClientScene& GetScene()
	{
		return scene;
	}
};

