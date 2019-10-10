#include "PhysicsSystem.hpp"

#include "Scene.hpp"

#include <cmath>

void PhysicsSystem::Update(int dt)
{
  for (auto& e : scene.GetEntities()) {
	if (scene.GetPhysicsComponent(e)) {
	  auto& pc = *scene.GetPhysicsComponent(e);
	  pc.vel.x = pc.speed * sinf(pc.yaw);
	  pc.vel.y = pc.speed * -cosf(pc.yaw);
	  pc.pos.x += pc.vel.x * dt;
	  pc.pos.y += pc.vel.y * dt;
	}
  }
}
