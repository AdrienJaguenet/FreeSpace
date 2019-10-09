#include "ProjectilePhysicsComponent.hpp"

void ProjectilePhysicsComponent::Update(int dt, Scene& sc, Entity& e)
{
	this->LinearPhysicsComponent::Update(dt, sc, e);
	ttl -= dt;
	if (ttl < 0) {
		e.Destroy();
	}
}
