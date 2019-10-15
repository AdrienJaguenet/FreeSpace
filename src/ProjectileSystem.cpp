#include "ProjectileSystem.hpp"

#include "Scene.hpp"

#include <iostream>

void ProjectileSystem::OnCollide(Entity& e, Entity&f)
{
	if (sc.GetProjectileComponent(e) and sc.GetHealthComponent(f)) {
		auto& pc = *sc.GetProjectileComponent(e);
		auto& hc = *sc.GetHealthComponent(f);
		if (*pc.origin == f) {
			return;
		}
		hc.hp -= pc.damage;
		std::cerr << f << " left with " << hc.hp << std::endl;;
		if (hc.hp <= 0) {
			sc.KillEntity(f);
		}
		sc.KillEntity(e);
	}
}

