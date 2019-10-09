#pragma once

#include "PhysicsComponent.hpp"
#include "GraphicsComponent.hpp"
#include "CollisionsComponent.hpp"

#include <memory>
#include <string>

#include <SFML/System.hpp>

class PhysicsComponent;
class GraphicsComponent;
class CollisionsComponent;

class Entity
{
private:
	std::unique_ptr<PhysicsComponent> physics;
	std::unique_ptr<GraphicsComponent> graphics;
	std::unique_ptr<CollisionsComponent> collisions;
	std::string name;

	bool stagedForDestruction;
public:
	Entity();
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
	CollisionsComponent& getCollisionsComponent()
	{
		return *collisions;
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

	void Render(Scene& scene, Camera& camera);
	void Update(Scene& scene, int dt);

	bool IsThrusting();

	void MoveUpwards();
	void MoveDownwards();
	void MoveLeftwards();
	void MoveRightwards();

	void StopMovingUpwards();
	void StopMovingDownwards();
	void StopMovingLeftwards();
	void StopMovingRightwards();

	void Destroy()
	{
		stagedForDestruction = true;
	}

	void OnCollision(Entity& e);
	void OnDamage(int d);

	bool CollidesWith(Entity& e);
	bool IsStagedForDestruction()
	{
		return stagedForDestruction;
	}
};

