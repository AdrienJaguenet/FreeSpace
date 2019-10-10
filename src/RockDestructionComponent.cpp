#include "RockDestructionComponent.hpp"

void RockDestructionComponent::OnDestroy(Entity& e, Scene& sc)
{
  sc.SpawnOrangium(e.GetPhysicsComponent().pos.x, e.GetPhysicsComponent().pos.y);
}
