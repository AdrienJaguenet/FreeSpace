#pragma once

#include "PhysicsComponent.hpp"
#include "GraphicsComponent.hpp"

#include <memory>
#include <string>

#include <SFML/System.hpp>

class Entity
{
private:
	sf::Vector2<float> pos;
	sf::Vector2<float> vel;
	sf::Vector2<float> acc;
	float raw; /* in radians */
	std::unique_ptr<PhysicsComponent> physics;
	std::unique_ptr<GraphicsComponent> graphics;
	std::string name;
public:
	void Update(int dt, Scene& sc);

	std::string& GetName()
	{
		return name;
	}
	void SetName(const std::string& new_name)
	{
		name = new_name;
	}

	PhysicsComponent& GetPhysicsComponent();
	GraphicsComponent& GetGraphicsComponent();

	void SetPhysicsComponent(std::unique_ptr<PhysicsComponent> new_physics)
	{
		physics = new_physics;
	}
	void SetGraphicsComponent(std::unique_ptr<GraphicsComponent> new_graphics)
	{
		graphics = new_graphics;
	};
};

