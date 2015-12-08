/*
 * StartState.cpp
 *
 *  Created on: Nov 30, 2015
 *      Author: daniel
 */

#include "StartState.h"

namespace ast
{

StartState::StartState()
{
	// TODO Auto-generated constructor stub

}

StartState::~StartState()
{
	// TODO Auto-generated destructor stub
}

void StartState::update(float dt)
{

}

void StartState::handleEvent(sf::Event& event)
{
	if(event.type == sf::Event::KeyPressed)
	{
		if(event.key.code == sf::Keyboard::Escape)
		{
			send(Action{dynamic_cast<ActionSender*>(this), (int)ActionID::CLOSE});
		}
		else if(event.key.code == sf::Keyboard::P)
		{
			send(Action{dynamic_cast<ActionSender*>(this), (int)ActionID::PLAY});
		}
		else if(event.key.code == sf::Keyboard::E)
		{
			send(Action{dynamic_cast<ActionSender*>(this), (int)ActionID::EDITOR});
		}
		else if(event.key.code == sf::Keyboard::X)
		{
			send(Action{dynamic_cast<ActionSender*>(this), (int)ActionID::CLOSE});
		}
	}
	if(event.type == sf::Event::Closed)
	{
		send(Action{dynamic_cast<ActionSender*>(this), (int)ActionID::CLOSE});
	}
}

void StartState::render(sf::RenderWindow& window, const Resources& resources) const
{
	window.clear(sf::Color::White);
	window.setView(
			sf::View{
				sf::FloatRect{0.f, 0.f, static_cast<float>(window.getSize().x), static_cast<float>(window.getSize().y)}
			}
	);
	sf::Text text;
	text.setFont(resources.getLightFont());
	text.setColor(sf::Color(32, 32, 32));
	text.setRotation(0.f);

	text.setCharacterSize(64);

	text.setString("Asterism");
	text.setPosition(300, 160);
	window.draw(text);

	text.setCharacterSize(24);

	text.setString("[P] Play");
	text.setPosition(300, 260);
	window.draw(text);

	text.setString("[E] Editor");
	text.setPosition(300, 300);
	window.draw(text);

	text.setString("[X] Exit");
	text.setPosition(300, 340);
	window.draw(text);

	window.display();
}

} /* namespace ast */
