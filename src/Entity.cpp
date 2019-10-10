#include "Entity.hpp"

Entity::Entity(Scene& scene) :
	stagedForDestruction(false),
	scene(scene)
{

}

void Entity::StartThrusting()
{
	this->GetPhysicsComponent().frontThrust = 250.f;
	graphics->OnMoveEntity(*this);
}

void Entity::StopThrusting()
{
	this->GetPhysicsComponent().frontThrust = 0.f;
	graphics->OnMoveEntity(*this);
}

void Entity::StartBoost()
{
	this->GetPhysicsComponent().frontThrust *= 2.f;
	graphics->OnMoveEntity(*this);
}

void Entity::StopBoost()
{
	this->GetPhysicsComponent().frontThrust /= 2.f;
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
  if (collisions) {
	collisions->OnCollision(*this, e);
  }
  physics->OnCollision(*this, e);
}

void Entity::OnDamage(int d)
{
  if (damages) {
	damages->OnDamage(*this, d);
  }
}

bool Entity::CollidesWith(Entity& e)
{
	return e.GetPhysicsComponent().body.intersects(physics->body);
}

void Entity::Destroy()
{
  stagedForDestruction = true;
  if (destructions) {
	destructions->OnDestroy(*this, scene);
  }
}

