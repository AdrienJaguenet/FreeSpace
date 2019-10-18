#pragma once

#include <vector>
#include <set>

#include <SFML/Graphics.hpp>

#include "Camera.hpp"
#include "Scene.hpp"

#include "InputComponent.hpp"
#include "GraphicComponent.hpp"

#include "GraphicsSystem.hpp"
#include "InputSystem.hpp"

class ClientScene : public Scene
{
private:
	sf::RenderTarget& window;
	std::map<std::string, sf::Texture> textures;
	std::map<std::string, sf::Sprite> sprites;
	sf::Texture LoadTexture(const std::string& path);

	std::set<Entity> ents;
	std::vector<std::unique_ptr<InputComponent>> inputs;
	std::vector<std::unique_ptr<GraphicComponent>> graphics;

	GraphicsSystem graphicsSystem;
	InputSystem inputSystem;

public:
	ClientScene(sf::RenderTarget& window);

	std::unique_ptr<GraphicComponent>& GetGraphicsComponent(const Entity& key)
	{
		return graphics[key];
	}
	std::unique_ptr<InputComponent>& GetInputComponent(const Entity& key)
	{
		return inputs[key];
	}
	InputSystem& GetInputSystem()
	{
		return inputSystem;
	}
	Entity SpawnPlayer();
	void SpawnRock(float x, float y);
	/* spawns weedium */
	void SpawnOrangium(float x, float y);
	/* spawns greenine */
	void SpawnGreenine(float x, float y);
	void SpawnPirate(float x, float y);
	void SpawnProjectile(float x, float y, float yaw, float speed);
	void KillEntity(const Entity& e);
	void FireWeapon(const Entity& e);

	void Update(int dt);
	void Render(Camera& camera);
	sf::RenderTarget& GetRenderTarget()
	{
		return window;
	}
};

