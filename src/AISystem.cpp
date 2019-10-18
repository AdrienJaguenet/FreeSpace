#include "AISystem.hpp"

#include "ServerScene.hpp"

void AISystem::Update(int dt)
{
	float dt_f = dt / 1000.f;
	for (auto& e : sc.GetEntities()) {
		if (sc.GetAIComponent(e)) {
			auto& ai = *sc.GetAIComponent(e);
			bool goForward = false;
			auto& pc_this = *sc.GetPhysicsComponent(e);
			for (auto& f : sc.GetEntities()) {
				if (e != f and sc.GetTeamComponent(f) and sc.GetTeamComponent(e) and sc.GetPhysicsComponent(e) and sc.GetPhysicsComponent(f)) {
					auto& team_id_this = sc.GetTeamComponent(e)->id;
					auto& team_id_other = sc.GetTeamComponent(f)->id;
					auto& pc_other = *sc.GetPhysicsComponent(f);
					if (team_id_this != team_id_other) {
						sf::Vector2f diffVec = pc_this.pos - pc_other.pos;
						float sqdist = diffVec.x * diffVec.x + diffVec.y * diffVec.y;
						if (sqdist <= ai.targetThreshold * ai.targetThreshold) {
							float required_yaw = atan2f(-diffVec.x, diffVec.y);
							if (sqdist > ai.minTargetDistance * ai.minTargetDistance) {
								goForward = true;
							}
							if (required_yaw > pc_this.yaw) {
								pc_this.yaw = std::min(required_yaw + ai.yawChangingRate * dt_f, required_yaw);
							} else if (required_yaw < pc_this.yaw) {
								pc_this.yaw = std::max(required_yaw - ai.yawChangingRate * dt_f, required_yaw);
							}
							if (abs(required_yaw - pc_this.yaw < .5)) { /* when within half a radian of the target, fire */
								sc.FireWeapon(e);
							}
						}
					}
				}
			}
			if (goForward) {
				pc_this.speed = ai.runningSpeed;
			} else {
				pc_this.speed = 0.f;
			}
		}
	}
}

