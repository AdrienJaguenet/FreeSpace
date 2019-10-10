#include "DamageComponent.hpp"

class DestructibleDamageComponent : public DamageComponent
{
private:
	int health;
public:
	DestructibleDamageComponent(int health);
	void OnDamage(Entity& e, int d);
};
