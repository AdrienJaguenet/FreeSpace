#include "ProjectileCollisionsComponent.hpp"

#include <iostream>

void ProjectileCollisionsComponent::OnCollision(Entity& e, Entity& f)
{
	if (&f == source) {
		return;
	}
	e.Destroy();
	f.OnDamage(damage);
}
