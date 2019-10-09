#pragma once

#include "GraphicsComponent.hpp"

class StaticSpriteGraphicsComponent : public GraphicsComponent
{
protected:
	sf::Sprite* sprite;
public:
	StaticSpriteGraphicsComponent(sf::Sprite& sprite);
	void Render(Entity& e, Scene& sc, Camera& c);
};

