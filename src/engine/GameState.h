/*
 * GameState.h
 *
 *  Created on: Nov 30, 2015
 *      Author: daniel
 */

#ifndef ENGINE_GAMESTATE_H_
#define ENGINE_GAMESTATE_H_

#include <SFML/Graphics.hpp>

#include "actions/actions.h"
#include "Resources.h"

namespace ast
{

class GameState: public ActionSender, ActionListener
{
public:
	GameState();
	virtual ~GameState();

	virtual void update(float dt) = 0;
	virtual void handleEvent(sf::Event& event) = 0;
	virtual void render(sf::RenderWindow& window, const Resources& resources) const = 0;

	virtual void onAction(const Action& action);

protected:
	sf::View view;
};

} /* namespace ast */

#endif /* ENGINE_GAMESTATE_H_ */
