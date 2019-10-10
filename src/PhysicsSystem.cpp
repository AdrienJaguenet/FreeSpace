#include "PhysicsSystem.hpp"

#include "Scene.hpp"

#include <cmath>

void PhysicsSystem::Update(int dt)
{
	for (auto& e : scene.GetEntities()) {
		if (scene.GetPhysicsComponent(e)) {
			auto& pc = *scene.GetPhysicsComponent(e);
			float dt_f = dt / 1000.f;
			pc.vel.x = pc.speed * sinf(pc.yaw);
			pc.vel.y = pc.speed * -cosf(pc.yaw);
			pc.pos.x += pc.vel.x * dt_f;
			pc.pos.y += pc.vel.y * dt_f;
		}
	}
}
