/*
 * EditorState.cpp
 *
 *  Created on: Dec 7, 2015
 *      Author: daniel
 */

#include "EditorState.h"

namespace ast
{

EditorState::EditorState():
		pieces([](const sf::Vector2i& v1, const sf::Vector2i& v2){return v1 < v2;})
{
	// TODO Auto-generated constructor stub

}

EditorState::~EditorState()
{
	// TODO Auto-generated destructor stub
}

void EditorState::update(float dt)
{
}

void EditorState::handleEvent(sf::Event& event)
{
	if(event.type == sf::Event::KeyPressed)
	{
		if(event.key.code == sf::Keyboard::Escape)
		{
			send(Action{dynamic_cast<ActionSender*>(this), (int)ActionID::EXIT});
		}
		else if(event.key.code == sf::Keyboard::W)
		{
			cursorPosition += sf::Vector2i{0, 1};
		}
		else if(event.key.code == sf::Keyboard::S)
		{
			cursorPosition += sf::Vector2i{0, -1};
		}
		else if(event.key.code == sf::Keyboard::A)
		{
			cursorPosition += sf::Vector2i{-1, 0};
		}
		else if(event.key.code == sf::Keyboard::D)
		{
			cursorPosition += sf::Vector2i{1, 0};
		}
		else if(event.key.code == sf::Keyboard::P)
		{
			// Añadir una pieza
			Piece piece = PieceFactory::getPiece(Piece::Type::FULL, static_cast<sf::Vector2f>(cursorPosition) * 32.f, 0);
			pieces[cursorPosition] = piece;
		}
	}
}

void EditorState::render(sf::RenderWindow& window,
		const Resources& resources) const
{
	window.clear(sf::Color(32, 32, 32));

	// world

	window.setView(
			sf::View{
				sf::Vector2f{0.f, 0.f},
				sf::Vector2f{static_cast<float>(window.getSize().x), static_cast<float>(window.getSize().y)}
			}
	);

	renderShip(window, resources);

	sf::RectangleShape cursorRectangle;
	cursorRectangle.setFillColor(sf::Color::Transparent);
	cursorRectangle.setOutlineColor(sf::Color::Red);
	cursorRectangle.setOutlineThickness(1.f);
	cursorRectangle.setOrigin(16.f, 16.f);
	cursorRectangle.setSize(sf::Vector2f{32.f, 32.f});
	cursorRectangle.setPosition(cursorPosition.x*32, -cursorPosition.y*32);

	window.draw(cursorRectangle);


	// UI
	window.setView(
			sf::View{
				sf::FloatRect{0.f, 0.f, static_cast<float>(window.getSize().x), static_cast<float>(window.getSize().y)}
			}
	);
	sf::Text text;
	text.setFont(resources.getFont());
	text.setColor(sf::Color(192, 192, 192));

	text.setCharacterSize(24);
	text.setString("Editor");
	text.setPosition(5, 5);
	window.draw(text);

	window.display();
}

void EditorState::renderShip(sf::RenderWindow& window,
		const Resources& resources) const
{
	for(const auto& p: pieces)
	{
		sf::Sprite sprite;
		sprite.setTexture(resources.getTextureAtlas());
		sprite.setTextureRect(getGridRect(32, sf::Vector2i{0, 0}));
		sprite.setOrigin(16.f, 16.f);
		sprite.setPosition(static_cast<sf::Vector2f>(flipY(p.first) * 32));
		window.draw(sprite);
	}
}

} /* namespace ast */
