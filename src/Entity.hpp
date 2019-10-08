#pragma once

#include "PhysicsComponent.hpp"

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
	std::unique_ptr<PhysicsComponent> physics;
public:
	void Update(int dt, Scene& sc);

	PhysicsComponent& getPhysicsComponent();
	void setPhysicsComponent(std::unique_ptr<PhysicsComponent> new_physics);
};

