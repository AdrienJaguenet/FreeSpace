#include "InputSystem.hpp"

#include "ClientScene.hpp"

InputSystem::InputSystem(ClientScene& scene) :
	scene(scene)
{

}

void InputSystem::StartThrusting()
{
	for (auto& e : scene.GetEntities()) {
		if (scene.GetPhysicsComponent(e) and scene.GetInputComponent(e)) {
			scene.GetPhysicsComponent(e)->speed = 200;
		}
	}
}

void InputSystem::StopThrusting()
{
	for (auto& e : scene.GetEntities()) {
		if (scene.GetPhysicsComponent(e) and scene.GetInputComponent(e)) {
			scene.GetPhysicsComponent(e)->speed = 0;
		}
	}
}

void InputSystem::StartBoost()
{
	for (auto& e : scene.GetEntities()) {
		if (scene.GetPhysicsComponent(e) and scene.GetInputComponent(e)) {
			scene.GetPhysicsComponent(e)->speed *= 2;
		}
	}
}

void InputSystem::StopBoost()
{
	for (auto& e : scene.GetEntities()) {
		if (scene.GetPhysicsComponent(e) and scene.GetInputComponent(e)) {
			scene.GetPhysicsComponent(e)->speed /= 2;
		}
	}
}

void InputSystem::LookAt(float x, float y)
{
	for (auto& e : scene.GetEntities()) {
		if (scene.GetPhysicsComponent(e) and scene.GetInputComponent(e)) {
			auto& pc = *scene.GetPhysicsComponent(e);
			float dx = x - pc.pos.x, dy = y - pc.pos.y;
			pc.yaw = atan2f(dx, -dy);
		}
	}
}

void InputSystem::Fire()
{
	for (auto& e : scene.GetEntities()) {
		if (scene.GetInputComponent(e)) {
			scene.FireWeapon(e);
		}
	}
}

