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

protected:
	sf::Vector2i cursorPosition;
};

} /* namespace ast */

#endif /* ENGINE_STATES_EDITORSTATE_H_ */
