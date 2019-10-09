#pragma once

#include "PhysicsComponent.hpp"
#include "GraphicsComponent.hpp"

#include <memory>
#include <string>

#include <SFML/System.hpp>

class PhysicsComponent;
class GraphicsComponent;

class Entity
{
private:
	std::unique_ptr<PhysicsComponent> physics;
	std::unique_ptr<GraphicsComponent> graphics;
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

	void SetPhysicsComponent(std::unique_ptr<PhysicsComponent> new_physics)
	{
		physics = std::move(new_physics);
	}
	void SetGraphicsComponent(std::unique_ptr<GraphicsComponent> new_graphics)
	{
		graphics = std::move(new_graphics);
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

	void Destroy();

	bool IsStagedForDestruction()
	{
		return stagedForDestruction;
	}
};

