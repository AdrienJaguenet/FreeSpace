#include "GraphicsSystem.hpp"

#include <cmath>
#include <iostream>

#include "Camera.hpp"
#include "Scene.hpp"

void GraphicsSystem::Render(Camera& c, Scene& sc)
{
	sf::CircleShape collision_box;
	collision_box.setOutlineColor(sf::Color::Green);
	collision_box.setFillColor(sf::Color(0.f, 0.f, 0.f, 0.f));
	collision_box.setOutlineThickness(2.f);
	for (auto& e : sc.GetEntities()) {
		if (sc.GetGraphicsComponent(e) && sc.GetPhysicsComponent(e)) {
			auto& gc = *sc.GetGraphicsComponent(e);
			auto& pc = *sc.GetPhysicsComponent(e);
			sf::Sprite* sprite = gc.sprites[0];
			switch (gc.renderingType) {
			case GraphicComponent::RenderingType::RENDERING_STATIC:
				sprite = gc.sprites[0];
				break;
			case GraphicComponent::RenderingType::RENDERING_SHIP:
				if (pc.speed > 0.f) {
					sprite = gc.sprites[1];
				} else {
					sprite = gc.sprites[0];
				}
				break;
			}
			sprite->setOrigin(sprite->getLocalBounds().width / 2.f, sprite->getLocalBounds().height / 2.f);
			sprite->setRotation(pc.yaw * 180.f / M_PI);
			sprite->setPosition(pc.pos.x - c.x, pc.pos.y - c.y);
			sprite->setScale(sf::Vector2f(c.scale, c.scale));
			sc.GetRenderTarget().draw(*sprite);
			if (debug) {
				if (pc.isColliding) {
					collision_box.setOutlineColor(sf::Color::Red);
				} else {
					collision_box.setOutlineColor(sf::Color::Green);
				}
				collision_box.setRadius(pc.radius);
				collision_box.setPosition(pc.pos.x - c.x - pc.radius, pc.pos.y - c.y - pc.radius);
				sc.GetRenderTarget().draw(collision_box);
			}
		}
	}
}

