#pragma once

#include "PhysicsComponent.hpp"
#include "GraphicsComponent.hpp"
#include "CollisionsComponent.hpp"
#include "DamageComponent.hpp"
#include "DestructionComponent.hpp"

#include <memory>
#include <string>

#include <SFML/System.hpp>

class PhysicsComponent;
class GraphicsComponent;
class CollisionsComponent;
class DamageComponent;
class DestructionComponent;

class Entity
{
private:
	std::unique_ptr<PhysicsComponent> physics;
	std::unique_ptr<GraphicsComponent> graphics;
	std::unique_ptr<CollisionsComponent> collisions;
	std::unique_ptr<DamageComponent> damages;
	std::unique_ptr<DestructionComponent> destructions;
	std::string name;

	bool stagedForDestruction;
	Scene& scene;
public:
	Entity(Scene& scene);
	void Update(int dt, Scene& sc);

	std::string& GetName()
	{
		return name;
	}
	void SetName(const std::string& new_name)
	{
		name = new_name;
	}

	PhysicsComponent& GetPhysicsComponent()
	{
		return *physics;
	}
	GraphicsComponent& GetGraphicsComponent()
	{
		return *graphics;
	}
	CollisionsComponent& GetCollisionsComponent()
	{
		return *collisions;
	}
	DamageComponent& GetDamageComponent()
	{
		return *damages;
	}

	void SetPhysicsComponent(std::unique_ptr<PhysicsComponent> new_physics)
	{
		physics = std::move(new_physics);
	}
	void SetGraphicsComponent(std::unique_ptr<GraphicsComponent> new_graphics)
	{
		graphics = std::move(new_graphics);
	};
	void SetCollisionsComponent(std::unique_ptr<CollisionsComponent> new_collisions)
	{
		collisions = std::move(new_collisions);
	};

	void SetDamageComponent(std::unique_ptr<DamageComponent> new_damages)
	{
		damages = std::move(new_damages);
	}
	void SetDestructionComponent(std::unique_ptr<DestructionComponent> new_destructions)
	{
		destructions = std::move(new_destructions);
	}


	void Render(Scene& scene, Camera& camera);
	void Update(Scene& scene, int dt);

	bool IsThrusting();

	void StartThrusting();
	void StopThrusting();
	void StartBoost();
	void StopBoost();

	void Destroy();

	void OnCollision(Entity& e);
	void OnDamage(int d);

	bool CollidesWith(Entity& e);
	bool IsStagedForDestruction()
	{
		return stagedForDestruction;
	}
};

