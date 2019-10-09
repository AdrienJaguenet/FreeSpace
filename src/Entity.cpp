#include "Entity.hpp"

void Entity::MoveUpwards()
{
	this->GetPhysicsComponent().vel.y = 1.f;
}

void Entity::MoveDownwards()
{
	this->GetPhysicsComponent().vel.y = -1.f;
}

void Entity::MoveLeftwards()
{
	this->GetPhysicsComponent().vel.x = -1.f;
}

void Entity::MoveRightwards()
{
	this->GetPhysicsComponent().vel.x = 1.f;
}

void Entity::Render(Scene& scene, Camera& camera)
{
	graphics->Render(*this, scene, camera);
}
