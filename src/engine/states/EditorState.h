/*
 * EditorState.h
 *
 *  Created on: Dec 7, 2015
 *      Author: daniel
 */

#ifndef ENGINE_STATES_EDITORSTATE_H_
#define ENGINE_STATES_EDITORSTATE_H_

#include "../GameState.h"
#include <SFML/Graphics.hpp>
#include "../world/objects/ship/PieceFactory.h"
#include <map>
#include "../data/geometry.h"
#include <functional>

namespace ast
{

class EditorState: public GameState
{
public:
	EditorState();
	virtual ~EditorState();

	virtual void update(float dt);
	virtual void handleEvent(sf::Event& event);
	virtual void render(sf::RenderWindow& window, const Resources& resources) const;

	enum ActionID
	{
		EXIT
	};

	void renderShip(sf::RenderWindow& window, const Resources& resources) const;

protected:
	sf::Vector2i cursorPosition;
	std::map<sf::Vector2i, Piece, std::function<bool(const sf::Vector2i&, const sf::Vector2i&)>> pieces;
};

} /* namespace ast */

#endif /* ENGINE_STATES_EDITORSTATE_H_ */
