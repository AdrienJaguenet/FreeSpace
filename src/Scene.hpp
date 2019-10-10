#pragma once

#include <vector>
#include <set>

#include <SFML/Graphics.hpp>

#include "Camera.hpp"
#include "Entity.hpp"

#include "PhysicComponent.hpp"
#include "HealthComponent.hpp"
#include "InputComponent.hpp"
#include "GraphicComponent.hpp"

#include "PhysicsSystem.hpp"
#include "GraphicsSystem.hpp"
#include "InputSystem.hpp"
#include "HealthSystem.hpp"

class Scene
{
private:
	int ent_id;
	int ent_count;
	int max_ents;
	sf::RenderTarget& window;
	std::map<std::string, sf::Texture> textures;
	std::map<std::string, sf::Sprite> sprites;
	sf::Texture LoadTexture(const std::string& path);

	std::set<Entity> ents;
	std::vector<std::unique_ptr<PhysicComponent>> physics;
	std::vector<std::unique_ptr<HealthComponent>> healths;
	std::vector<std::unique_ptr<InputComponent>> inputs;
	std::vector<std::unique_ptr<GraphicComponent>> graphics;


	PhysicsSystem physicsSystem;
	GraphicsSystem graphicsSystem;
	InputSystem inputSystem;
	HealthSystem healthSystem;

	Entity NewEntity();
public:
	Scene(sf::RenderTarget& window);

	std::unique_ptr<PhysicComponent>& GetPhysicsComponent(const Entity& key)
	{
		return physics[key];
	}
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
	std::set<Entity>& GetEntities()
	{
		return ents;
	}
	void SpawnRock(float x, float y);
	/* spawns a projectile */
	void ShootProjectile(Entity& from);
	/* spawns weedium */
	void SpawnOrangium(float x, float y);
	void Update(int dt);
	void Render(Camera& camera);
	sf::RenderTarget& GetRenderTarget()
	{
		return window;
	}
};

