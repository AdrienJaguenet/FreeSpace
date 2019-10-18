#include "WeaponSystem.hpp"
#include "ServerScene.hpp"

#include <iostream>

void WeaponSystem::FireWeapon(const Entity& e)
{
	if (sc.GetPhysicsComponent(e) && sc.GetWeaponComponent(e)) {
		auto& wc = *sc.GetWeaponComponent(e);
		auto& pc = *sc.GetPhysicsComponent(e);
		if (wc.current_cooldown <= 0) {
			sc.SpawnProjectile(pc.pos.x, pc.pos.y, pc.yaw, 700.f, 10, 2.f, e);
			wc.current_cooldown = wc.cooldown;
		}
	}
}

void WeaponSystem::Update(int dt)
{
	float dt_f = dt / 1000.f;
	for (auto& e : sc.GetEntities()) {
		if (sc.GetWeaponComponent(e)) {
			auto& wc = *sc.GetWeaponComponent(e);
			wc.current_cooldown -= dt_f;
		}
	}
}

