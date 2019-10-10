#include "DestructibleDamageComponent.hpp"

#include <iostream>

DestructibleDamageComponent::DestructibleDamageComponent(int health) :
	health(health)
{

}

void DestructibleDamageComponent::OnDamage(Entity& e, int d)
{
	health -= d;
	if (health <= 0) {
		e.Destroy();
	}
}
