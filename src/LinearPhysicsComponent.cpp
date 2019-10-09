#include "LinearPhysicsComponent.hpp"

#include <iostream>
#include <cmath>

void LinearPhysicsComponent::Update(int dt, Scene& scene, Entity& entity)
{
	this->PhysicsComponent::Update(dt, scene, entity);
	float dt_f = (float) dt / 1000.f;

	vel.x = frontThrust * sinf(yaw) + sideThrust * -cosf(yaw);
	vel.y = frontThrust * -cosf(yaw) + sideThrust * cosf(yaw);
	pos.x += dt_f * vel.x;
	pos.y += dt_f * vel.y;
}

