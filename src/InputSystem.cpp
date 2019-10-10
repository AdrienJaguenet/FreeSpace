#include "InputSystem.hpp"

#include "Scene.hpp"

InputSystem::InputSystem(Scene& scene) :
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
	  scene.GetPhysicsComponent(e)->speed = 200;
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
	  scene.GetPhysicsComponent(e)->yaw = atan2f(-x, y);
	}
  }
}

void InputSystem::Fire()
{
}

