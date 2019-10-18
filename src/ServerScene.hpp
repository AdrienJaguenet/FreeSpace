#pragma once

#include "Scene.hpp"

#include "AIComponent.hpp"
#include "ProjectileComponent.hpp"

#include "PhysicsSystem.hpp"
#include "ResourceCollectSystem.hpp"
#include "AISystem.hpp"
#include "WeaponSystem.hpp"

class ServerScene : public Scene
{
private:
	std::vector<std::unique_ptr<AIComponent>> ais;
	std::vector<std::unique_ptr<ProjectileComponent>> projectiles;

	AISystem aiSystem;
	ResourceCollectSystem collectSystem;
	ProjectileSystem projectileSystem;
	WeaponSystem weaponSystem;

public:
	ServerScene();

	Entity AddPlayer();
	Entity SpawnPirate();
	Entity SpawnProjectile(float x, float y, float yaw, float speed, int dmg, float ttl, const Entity& from);

	void Update(int dt);
	void FireWeapon(const Entity& e);
	std::unique_ptr<AIComponent>& GetAIComponent(const Entity& key)
	{
		return ais[key];
	}
	std::unique_ptr<ProjectileComponent>& GetProjectileComponent(const Entity& key)
	{
		return projectiles[key];
	}
};

