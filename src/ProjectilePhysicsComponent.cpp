#include "ProjectilePhysicsComponent.hpp"

void ProjectilePhysicsComponent::Update(int dt, Scene& sc, Entity& e)
{
	this->ProjectilePhysicsComponent(dt, sc, e);
	ttl -= dt;
	if (ttl < 0) {
		e.Destroy();
	}
}
