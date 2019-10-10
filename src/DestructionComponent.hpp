#pragma once

#include "Entity.hpp"
#include "Scene.hpp"

class DestructionComponent
{
public:
  virtual void OnDestroy(Entity& e, Scene& scene) {}
};

