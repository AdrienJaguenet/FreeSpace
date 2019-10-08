#pragma once

#include "Scene.hpp"

class Scene;
class Entity;

class PhysicsComponent
{
  private:
  public:
	virtual void Update(int dt, Scene& scene, Entity& entity) = 0;
};

