#include "ProjectilePhysicsComponent.hpp"

#include <iostream>

void ProjectilePhysicsComponent::Update(int dt, Scene& sc, Entity& e)
{
	this->LinearPhysicsComponent::Update(dt, sc, e);
	ttl -= dt;
	if (ttl < 0) {
		e.Destroy();
	}
}
