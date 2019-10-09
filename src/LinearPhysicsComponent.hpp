#pragma once

#include "PhysicsComponent.hpp"

class LinearPhysicsComponent : public PhysicsComponent
{
private:
public:
	void Update(int dt, Scene& scene, Entity& entity);
	void OnCollision(Entity& a, Entity& b) {}
};

