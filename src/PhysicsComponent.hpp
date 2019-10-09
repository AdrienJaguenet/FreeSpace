#pragma once

#include "Scene.hpp"

#include <SFML/System.hpp>

class Scene;
class Entity;

class PhysicsComponent
{
private:
public:
	bool solid;
	float frontThrust;
	float sideThrust;
	float yaw; /* in radians */
	sf::Vector2<float> pos;
	sf::Vector2<float> vel;
	sf::Vector2<float> acc;
	sf::Rect<float> body;
	virtual void Update(int dt, Scene& scene, Entity& entity) {
	  body.left = pos.x;
	  body.top = pos.y;
	}
	/* A collides into B */
	virtual void OnCollision(Entity& a, Entity& b) = 0;
};

