#pragma once

#include "StaticSpriteGraphicsComponent.hpp"

class ShipSpriteGraphicsComponent : public StaticSpriteGraphicsComponent
{
private:
	sf::Sprite *sprite_static, *sprite_thrusting;
public:
	ShipSpriteGraphicsComponent(sf::Sprite& sprite_static, sf::Sprite& sprite_thrusting);
	void Render(Entity& e, Scene& sc, Camera& c);
	void OnMoveEntity(Entity& e);
};

