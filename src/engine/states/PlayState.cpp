/*
 * PlayState.cpp
 *
 *  Created on: Dec 5, 2015
 *      Author: daniel
 */

#include "PlayState.h"

namespace ast
{

PlayState::PlayState():
		zoom(1.f)
{


}

PlayState::~PlayState()
{
	// TODO Auto-generated destructor stub
}

void PlayState::update(float dt)
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		world.getShip().applyForce(sf::Vector2f{0.f, 1.f}, sf::Vector2f{1.f, -1.0f});
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		world.getShip().applyForce(sf::Vector2f{0.f, 1.f}, sf::Vector2f{-1.f, -1.0f});
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		world.getShip().applyForce(sf::Vector2f{0.f, -1.f}, sf::Vector2f{-1.f, -1.0f});
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::C))
	{
		world.getShip().applyForce(sf::Vector2f{0.f, -1.f}, sf::Vector2f{1.f, -1.0f});
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		world.getShip().applyForce(sf::Vector2f{1.f, 0.f}, sf::Vector2f{-1.f, 0.0f});
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		world.getShip().applyForce(sf::Vector2f{-1.f, 0.f}, sf::Vector2f{1.f, 0.0f});
	}
	//world.getShip().applyForce(sf::Vector2f{0.f, 1.f}, sf::Vector2f{1.f, -0.1f});
	world.getShip().update(dt);
	std::cout << world.getShip().getPosition().x << ", " << world.getShip().getPosition().y << std::endl;
}

void PlayState::handleEvent(sf::Event& event)
{
	if(event.type == sf::Event::KeyPressed)
	{
		if(event.key.code == sf::Keyboard::Escape)
		{
			send(Action{dynamic_cast<ActionSender*>(this), (int)ActionID::EXIT});
		}
	}
	else if(event.type == sf::Event::Closed)
	{
		send(Action{dynamic_cast<ActionSender*>(this), (int)ActionID::EXIT});
	}
	else if(event.type == sf::Event::MouseWheelMoved)
	{
		zoom *= (1.f - static_cast<float>(event.mouseWheel.delta)*0.02f);
	}
}

void PlayState::render(sf::RenderWindow& window, const Resources& resources) const
{
	window.clear(sf::Color::Black);
	/*sf::RectangleShape shape(sf::Vector2f{20, 20});
	shape.setPosition(world.getShip().getPosition().x, -world.getShip().getPosition().y);
	shape.rotate(world.getShip().getAngle()*180.f/M_PI);
	shape.setFillColor(sf::Color::White);
	shape.setOrigin(10, 10);*/
	sf::View view = sf::View(sf::Vector2f{world.getShip().getPosition().x, -world.getShip().getPosition().y}, sf::Vector2f(window.getSize()));
	view.zoom(zoom);
	window.setView(view);
	//window.draw(shape);

	//background
	sf::Sprite bgSprite;
	bgSprite.setTexture(resources.getBgTexture());
	bgSprite.setOrigin(sf::Vector2f{1 << 14, 1 << 14});
	bgSprite.setPosition(sf::Vector2f{world.getShip().getPosition().x, -world.getShip().getPosition().y});
	bgSprite.setTextureRect(sf::IntRect{0, 0, 1 << 15, 1 << 15});
	bgSprite.setScale(zoom, zoom);
	window.draw(bgSprite);


	sf::Sprite sprite;
	sprite.setTexture(resources.getShipTexture());
	sprite.setPosition(world.getShip().getPosition().x, -world.getShip().getPosition().y);
	sprite.setOrigin(resources.getShipTexture().getSize().x/2, resources.getShipTexture().getSize().y/2);
	sprite.setRotation(-world.getShip().getAngle()*180.f/M_PI);
	window.draw(sprite);

	sf::Sprite ship2Sprite;
	ship2Sprite.setTexture(resources.getShip2Texture());
	ship2Sprite.setPosition(world.getShip2().getPosition().x, -world.getShip2().getPosition().y);
	ship2Sprite.setOrigin(resources.getShip2Texture().getSize().x/2, resources.getShip2Texture().getSize().y/2);
	ship2Sprite.setRotation(-world.getShip2().getAngle()*180.f/M_PI);
	window.draw(ship2Sprite);

	window.display();
}

} /* namespace ast */
