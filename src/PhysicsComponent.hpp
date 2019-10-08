#pragma once

#include "Scene.hpp"

class PhysicsComponent
{
  private:
  public:
	virtual void Update(int dt, Scene& scene, Entity& entity) = 0;
};

