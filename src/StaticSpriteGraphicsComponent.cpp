#include "StaticSpriteGraphicsComponent.hpp"

#include <cmath>

StaticSpriteGraphicsComponent::StaticSpriteGraphicsComponent(sf::Sprite& sprite) :
	sprite(&sprite)
{

}

void StaticSpriteGraphicsComponent::Render(Entity& e, Scene& sc, Camera& c)
{
	sprite->setOrigin(sprite->getLocalBounds().width / 2.f, sprite->getLocalBounds().height / 2.f);
	sprite->setRotation(e.GetPhysicsComponent().yaw * (180.f/M_PI));
	sprite->setPosition(e.GetPhysicsComponent().pos.x + c.x, e.GetPhysicsComponent().pos.y + c.y);
	sprite->setScale(sf::Vector2f(c.scale, c.scale));
	sc.GetRenderTarget().draw(*sprite);
}
