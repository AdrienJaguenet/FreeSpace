#include "Entity.hpp"

Entity::Entity() :
	stagedForDestruction(false)
{

}

void Entity::MoveUpwards()
{
	this->GetPhysicsComponent().frontThrust = 250.f;
	graphics->OnMoveEntity(*this);
}

void Entity::MoveDownwards()
{
	this->GetPhysicsComponent().frontThrust = -250.f;
	graphics->OnMoveEntity(*this);
}

void Entity::MoveLeftwards()
{
	this->GetPhysicsComponent().sideThrust = -250.f;
	graphics->OnMoveEntity(*this);
}

void Entity::MoveRightwards()
{
	this->GetPhysicsComponent().sideThrust = 250.f;
	graphics->OnMoveEntity(*this);
}

void Entity::StopMovingUpwards()
{
	this->GetPhysicsComponent().frontThrust = 0.f;
	graphics->OnMoveEntity(*this);
}

void Entity::StopMovingDownwards()
{
	this->GetPhysicsComponent().frontThrust = 0.f;
	graphics->OnMoveEntity(*this);
}

void Entity::StopMovingLeftwards()
{
	this->GetPhysicsComponent().sideThrust= 0.f;
	graphics->OnMoveEntity(*this);
}

void Entity::StopMovingRightwards()
{
	this->GetPhysicsComponent().sideThrust= 0.f;
	graphics->OnMoveEntity(*this);
}

void Entity::Render(Scene& scene, Camera& camera)
{
	graphics->Render(*this, scene, camera);
}

void Entity::Update(Scene& scene, int dt)
{
	physics->Update(dt, scene, *this);
}

bool Entity::IsThrusting()
{
	return physics->frontThrust > 0.f;
}

void Entity::OnCollision(Entity& e)
{
	collisions->OnCollision(*this, e);
	physics->OnCollision(*this, e);
}

void Entity::OnDamage(int d)
{
}

bool Entity::CollidesWith(Entity& e)
{
	return e.GetPhysicsComponent().body.intersects(physics->body) and e.GetPhysicsComponent().solid and physics->solid;
}
