#include "ProjectileCollisionsComponent.hpp"

#include <iostream>

void ProjectileCollisionsComponent::OnCollision(Entity& e, Entity& f)
{
  if (&f == source) {
	return;
  }
	std::cerr << "ProjectileCollisionsComponent::OnCollision()" << std::endl;
	e.Destroy();
	f.OnDamage(damage);
}
