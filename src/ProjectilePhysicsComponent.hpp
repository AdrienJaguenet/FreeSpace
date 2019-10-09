#pragma once

#include "LinearPhysicsComponent.hpp"

class ProjectilePhysicsComponent : public LinearPhysicsComponent
{
private:
  int ttl;
public:
  ProjectilePhysicsComponent(int ttl) : LinearPhysicsComponent(), ttl(ttl) {}
};

