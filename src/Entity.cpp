#include "Entity.hpp"

void Entity::MoveUpwards()
{
	this->GetPhysicsComponent().vel.y = 1.f;
	graphics->OnMoveEntity(*this);
}

void Entity::MoveDownwards()
{
	this->GetPhysicsComponent().vel.y = -1.f;
	graphics->OnMoveEntity(*this);
}

void Entity::MoveLeftwards()
{
	this->GetPhysicsComponent().vel.x = -1.f;
	graphics->OnMoveEntity(*this);
}

void Entity::MoveRightwards()
{
	this->GetPhysicsComponent().vel.x = 1.f;
	graphics->OnMoveEntity(*this);
}

void Entity::StopMovingUpwards()
{
	if (physics->vel.y > 0.f) {
		physics->vel.y = 0.f;
	}
	graphics->OnMoveEntity(*this);
}

void Entity::StopMovingDownwards()
{
	if (physics->vel.y < 0.f) {
		physics->vel.y = 0.f;
	}
	graphics->OnMoveEntity(*this);
}

void Entity::StopMovingLeftwards()
{
	if (physics->vel.x > 0.f) {
		physics->vel.x = 0.f;
	}
	graphics->OnMoveEntity(*this);
}

void Entity::StopMovingRightwards()
{
	if (physics->vel.x < 0.f) {
		physics->vel.x = 0.f;
	}
	graphics->OnMoveEntity(*this);
}

void Entity::Render(Scene& scene, Camera& camera)
{
	graphics->Render(*this, scene, camera);
}

bool Entity::IsRunning()
{
	return physics->vel.x != 0.f or physics->vel.y != 0.f;
}
