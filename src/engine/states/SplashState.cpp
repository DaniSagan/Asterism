/*
 * SplashState.cpp
 *
 *  Created on: Dec 8, 2015
 *      Author: daniel
 */

#include "SplashState.h"

namespace ast
{

SplashState::SplashState():
		totalTime(0.f)
{
	// TODO Auto-generated constructor stub

}

SplashState::~SplashState()
{
	// TODO Auto-generated destructor stub
}

void SplashState::update(float dt)
{
	totalTime += dt;
	if(totalTime > 6.f)
	{
		send(Action{dynamic_cast<ActionSender*>(this), (int)ActionID::FINISHED});
	}
}

void SplashState::handleEvent(sf::Event& event)
{
}

void SplashState::render(sf::RenderWindow& window,
		const Resources& resources) const
{
	window.setView(
			sf::View{
				sf::FloatRect{0.f, 0.f, static_cast<float>(window.getSize().x), static_cast<float>(window.getSize().y)}
			}
	);
	float color = 0.f;
	if(totalTime < 2.f)
	{
		color = 255.f/2.f * totalTime;
	}
	else if(totalTime < 4.f)
	{
		color = 255.f;
	}
	else
	{
		color = 255.f - 255.f/2.f * (totalTime - 4.f);
	}
	window.clear(sf::Color::Black);
	sf::Text text;
	text.setFont(resources.getLightFont());
	text.setCharacterSize(64);
	text.setColor(sf::Color{static_cast<char>(color), static_cast<char>(color), static_cast<char>(color)});
	text.setString("DaniSagan Labs");
	sf::Vector2f textSize{text.getLocalBounds().width, text.getLocalBounds().height};
	text.setPosition(sf::Vector2f{(window.getSize().x - textSize.x)/2, (window.getSize().y - textSize.y)/2});
	window.draw(text);
	window.display();
}

} /* namespace ast */
