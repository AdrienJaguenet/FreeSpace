#include "ServerScene.hpp"

ServerScene::ServerScene() :
	projectiles(max_ents),
	ais(max_ents),
	aiSystem(*this),
	collectSystem(*this),
	projectileSystem(*this),
	weaponSystem(*this)
{

}

Entity ServerScene::AddPlayer()
{

}

Entity ServerScene::SpawnPirate()
{
	Entity e = NewEntity();
	ais[e] = std::make_unique<AIComponent>();
	ais[e]->targetThreshold = 1000.f;
	ais[e]->runningSpeed = 150.f;
	ais[e]->yawChangingRate = 1.f;
	ais[e]->minTargetDistance = 200.f;
	return e;
}

Entity ServerScene::SpawnProjectile(float x, float y, float yaw, float speed, int dmg, float ttl, const Entity& from)
{
	Entity e = NewEntity();
	physics[e] = std::make_unique<PhysicComponent>();
	projectiles[e] = std::make_unique<ProjectileComponent>();
	physics[e]->pos.x = x;
	physics[e]->pos.y = y;
	physics[e]->yaw = yaw;
	physics[e]->speed = speed;
	projectiles[e]->damage = dmg;
	projectiles[e]->origin = &from;
}

void ServerScene::Update(int dt)
{
	physicsSystem.Update(dt);
	aiSystem.Update(dt);
	weaponSystem.Update(dt);
	for (auto e : entities) {
		bool collides(false);
		for (auto f : entities) {
			if (e != f) {
				if (physics[e] && physics[f]) {
					auto distvec = physics[e]->pos - physics[f]->pos;
					float sqdist = (distvec.x * distvec.x) + (distvec.y * distvec.y);
					float radiusSum = physics[e]->radius + physics[f]->radius;
					if (sqdist <= (radiusSum) * (radiusSum)) {
						/* trigger collision */
						/* for debug purposes */
						collides = true;
						collectSystem.OnCollide(e, f);
						projectileSystem.OnCollide(e, f);
					}
				}
			}
		}
		physics[e]->isColliding = collides;
	}
	for (auto& e : toDelete) {
		entities.erase(e);
		physics[e] = nullptr;
		healths[e] = nullptr;
		projectiles[e] = nullptr;
		resources[e] = nullptr;
		collectors[e] = nullptr;
		weapons[e] = nullptr;
	}
	toDelete.clear();
}

void ServerScene::FireWeapon(const Entity& e)
{

}

