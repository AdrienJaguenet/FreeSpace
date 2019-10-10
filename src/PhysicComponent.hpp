#pragma once

#include <SFML/System.hpp>

struct PhysicComponent
{
  float yaw;
  float radius;
  float speed;
  sf::Vector2f vel;
  sf::Vector2f pos;
};

