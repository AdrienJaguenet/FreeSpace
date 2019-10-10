#pragma once

#include "DestructionComponent.hpp"

class RockDestructionComponent : public DestructionComponent
{
  public:
	void OnDestroy(Entity& e, Scene& sc);
};

