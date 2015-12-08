/*
 * PlayState.h
 *
 *  Created on: Dec 5, 2015
 *      Author: daniel
 */

#ifndef ENGINE_STATES_PLAYSTATE_H_
#define ENGINE_STATES_PLAYSTATE_H_

#include "../world/World.h"
#include <iostream>
#include "../GameState.h"

namespace ast
{

class PlayState: public GameState
{
public:
	PlayState();
	virtual ~PlayState();

	virtual void update(float dt);
	virtual void handleEvent(sf::Event& event);
	virtual void render(sf::RenderWindow& window, const Resources& resources) const;

	enum ActionID
	{
		EXIT
	};

protected:
	World world;
	float zoom;
};

} /* namespace ast */

#endif /* ENGINE_STATES_PLAYSTATE_H_ */
