/*
 * StartState.h
 *
 *  Created on: Nov 30, 2015
 *      Author: daniel
 */

#ifndef ENGINE_STATES_STARTSTATE_H_
#define ENGINE_STATES_STARTSTATE_H_

#include "../GameState.h"
#include "../actions/actions.h"
#include <SFML/Graphics.hpp>
#include <iostream>

namespace ast
{

class StartState: public GameState
{
public:
	StartState();
	virtual ~StartState();

	virtual void update(float dt);
	virtual void handleEvent(sf::Event& event);
	virtual void render(sf::RenderWindow& window, const Resources& resources) const;

	enum ActionID
	{
		CLOSE,
		PLAY,
		EDITOR
	};
};

} /* namespace ast */

#endif /* ENGINE_STATES_STARTSTATE_H_ */
