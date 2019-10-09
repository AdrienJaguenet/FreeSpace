#pragma once

#include "Scene.hpp"

#include <SFML/System.hpp>

class Scene;
class Entity;

class PhysicsComponent
{
private:
public:
	float frontThrust;
	float sideThrust;
	float yaw; /* in radians */
	sf::Vector2<float> pos;
	sf::Vector2<float> vel;
	sf::Vector2<float> acc;
	virtual void Update(int dt, Scene& scene, Entity& entity) = 0;
};

