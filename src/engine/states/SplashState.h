/*
 * SplashState.h
 *
 *  Created on: Dec 8, 2015
 *      Author: daniel
 */

#ifndef ENGINE_STATES_SPLASHSTATE_H_
#define ENGINE_STATES_SPLASHSTATE_H_

#include "../GameState.h"
#include "../actions/actions.h"
#include <SFML/Graphics.hpp>

namespace ast
{

class SplashState: public GameState
{
public:
	SplashState();
	virtual ~SplashState();

	virtual void update(float dt);
	virtual void handleEvent(sf::Event& event);
	virtual void render(sf::RenderWindow& window, const Resources& resources) const;

	enum ActionID
	{
		FINISHED,
	};

protected:
	float totalTime;

};

} /* namespace ast */

#endif /* ENGINE_STATES_SPLASHSTATE_H_ */
