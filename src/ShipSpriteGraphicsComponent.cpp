#include "ShipSpriteGraphicsComponent.hpp"

#include <iostream>

ShipSpriteGraphicsComponent::ShipSpriteGraphicsComponent(sf::Sprite& sprite_static, sf::Sprite& sprite_thrusting):
	StaticSpriteGraphicsComponent(sprite_static),
	sprite_static(&sprite_static),
	sprite_thrusting(&sprite_thrusting)
{
}

void ShipSpriteGraphicsComponent::Render(Entity& e, Scene& sc, Camera& c)
{
	this->StaticSpriteGraphicsComponent::Render(e, sc, c);
}

void ShipSpriteGraphicsComponent::OnMoveEntity(Entity& e)
{
	if (e.IsThrusting()) {
		sprite = sprite_thrusting;
	} else {
		sprite = sprite_static;
	}
}
