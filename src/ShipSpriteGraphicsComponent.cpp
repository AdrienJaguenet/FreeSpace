#include "ShipSpriteGraphicsComponent.hpp"

#include <iostream>

ShipSpriteGraphicsComponent::ShipSpriteGraphicsComponent(sf::Sprite& sprite_static, sf::Sprite& sprite_running):
	StaticSpriteGraphicsComponent(sprite_static),
	sprite_static(&sprite_static),
	sprite_running(&sprite_running)
{
}

void ShipSpriteGraphicsComponent::Render(Entity& e, Scene& sc, Camera& c)
{
	this->StaticSpriteGraphicsComponent::Render(e, sc, c);
}

void ShipSpriteGraphicsComponent::OnMoveEntity(Entity& e)
{
	if (e.IsRunning()) {
		sprite = sprite_running;
	} else {
		sprite = sprite_static;
	}
}
