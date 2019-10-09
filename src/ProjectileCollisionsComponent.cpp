#include "ProjectileCollisionsComponent.hpp"

void ProjectileCollisionsComponent::OnCollision(Entity& e, Entity& f)
{
	e.Destroy();

	f.OnDamage(damage);
}
