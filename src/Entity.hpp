#pragma once

#include "PhysicsComponent.hpp"
#include "GraphicsComponent.hpp"

#include <memory>

class Entity
{
private:
	struct {
		float x, y;
	} pos;
	struct {
		float x, y;
	} vel;
	struct {
		float x, y;
	} acc;
	float raw; /* in radians */
	std::unique_ptr<PhysicsComponent> physics;
	std::unique_ptr<GraphicsComponent> graphics;
public:
	void Update(int dt, Scene& sc);

	PhysicsComponent& getPhysicsComponent();
	GraphicsComponent& getGraphicsComponent();

	void setPhysicsComponent(std::unique_ptr<PhysicsComponent> new_physics);
	void setGraphicsComponent(std::unique_ptr<GraphicsComponent> new_graphics);
};

