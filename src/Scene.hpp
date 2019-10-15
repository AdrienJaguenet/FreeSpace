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
#include "ResourceComponent.hpp"
#include "ResourceCollectorComponent.hpp"
#include "AIComponent.hpp"
#include "TeamComponent.hpp"
#include "WeaponComponent.hpp"
#include "ProjectileComponent.hpp"

#include "PhysicsSystem.hpp"
#include "GraphicsSystem.hpp"
#include "InputSystem.hpp"
#include "HealthSystem.hpp"
#include "ResourceCollectSystem.hpp"
#include "AISystem.hpp"
#include "WeaponSystem.hpp"
#include "ProjectileSystem.hpp"

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
	std::vector<std::unique_ptr<ResourceComponent>> resources;
	std::vector<std::unique_ptr<ResourceCollectorComponent>> collectors;
	std::vector<std::unique_ptr<AIComponent>> ais;
	std::vector<std::unique_ptr<TeamComponent>> teams;
	std::vector<std::unique_ptr<WeaponComponent>> weapons;
	std::vector<std::unique_ptr<ProjectileComponent>> projectiles;

	std::vector<Entity> toDelete;


	PhysicsSystem physicsSystem;
	GraphicsSystem graphicsSystem;
	InputSystem inputSystem;
	HealthSystem healthSystem;
	ResourceCollectSystem collectSystem;
	AISystem aiSystem;
	WeaponSystem weaponSystem;
	ProjectileSystem projectileSystem;

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
	std::unique_ptr<ResourceComponent>& GetResourceComponent(const Entity& key)
	{
		return resources[key];
	}
	std::unique_ptr<ResourceCollectorComponent>& GetResourceCollectorComponent(const Entity& key)
	{
		return collectors[key];
	}
	std::unique_ptr<AIComponent>& GetAIComponent(const Entity& key)
	{
		return ais[key];
	}
	std::unique_ptr<TeamComponent>& GetTeamComponent(const Entity& key)
	{
		return teams[key];
	}
	std::unique_ptr<HealthComponent>& GetHealthComponent(const Entity& key)
	{
		return healths[key];
	}
	std::unique_ptr<WeaponComponent>& GetWeaponComponent(const Entity& key)
	{
		return weapons[key];
	}
	std::unique_ptr<ProjectileComponent>& GetProjectileComponent(const Entity& key)
	{
		return projectiles[key];
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
	/* spawns weedium */
	void SpawnOrangium(float x, float y);
	/* spawns greenine */
	void SpawnGreenine(float x, float y);
	void SpawnPirate(float x, float y);
	void SpawnProjectile(float x, float y, float yaw, float speed, int dmg,  float ttl, const Entity& from);
	void KillEntity(const Entity& e);

	void FireWeapon(const Entity& e);
	void Update(int dt);
	void Render(Camera& camera);
	sf::RenderTarget& GetRenderTarget()
	{
		return window;
	}
};

