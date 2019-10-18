#pragma once

#include "Entity.hpp"

#include "PhysicComponent.hpp"
#include "HealthComponent.hpp"
#include "ResourceComponent.hpp"
#include "ResourceCollectorComponent.hpp"
#include "TeamComponent.hpp"
#include "WeaponComponent.hpp"

#include "PhysicsSystem.hpp"
#include "ProjectileSystem.hpp"
#include "HealthSystem.hpp"

#include <memory>
#include <set>

class Scene
{
protected:
	int ent_id;
	int ent_count;
	int max_ents;
	std::set<Entity> entities;
	Entity NewEntity();
	std::vector<Entity> toDelete;

	std::vector<std::unique_ptr<PhysicComponent>> physics;
	std::vector<std::unique_ptr<HealthComponent>> healths;
	std::vector<std::unique_ptr<ResourceComponent>> resources;
	std::vector<std::unique_ptr<TeamComponent>> teams;
	std::vector<std::unique_ptr<WeaponComponent>> weapons;
	std::vector<std::unique_ptr<ResourceCollectorComponent>> collectors;
	std::vector<std::unique_ptr<std::string>> names;

	PhysicsSystem physicsSystem;
public:
	Scene();

	std::set<Entity>& GetEntities()
	{
		return entities;
	}
	void KillEntity(const Entity& e);
	void FireWeapon(const Entity& e);

	std::unique_ptr<PhysicComponent>& GetPhysicsComponent(const Entity& key)
	{
		return physics[key];
	}
	std::unique_ptr<ResourceComponent>& GetResourceComponent(const Entity& key)
	{
		return resources[key];
	}
	std::unique_ptr<HealthComponent>& GetHealthComponent(const Entity& key)
	{
		return healths[key];
	}
	std::unique_ptr<WeaponComponent>& GetWeaponComponent(const Entity& key)
	{
		return weapons[key];
	}
	std::unique_ptr<TeamComponent>& GetTeamComponent(const Entity& key)
	{
		return teams[key];
	}
	std::unique_ptr<std::string>& GetName(const Entity& key)
	{
		return names[key];
	}
	std::unique_ptr<ResourceCollectorComponent>& GetResourceCollectorComponent(const Entity& key)
	{
		return collectors[key];
	}

};

