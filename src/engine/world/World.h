/*
 * World.h
 *
 *  Created on: Dec 3, 2015
 *      Author: daniel
 */

#ifndef ENGINE_WORLD_WORLD_H_
#define ENGINE_WORLD_WORLD_H_

#include "../actions/actions.h"
#include "objects/WorldObject.h"
#include "objects/Ship.h"
#include <map>

namespace ast
{

class World: public ActionListener, ActionSender
{
public:
	World();
	virtual ~World();

	void onAction(const Action& action);

	const Ship& getShip() const;
	const Ship& getShip2() const;
	Ship& getShip();

protected:
	std::map<int, WorldObject*> lpObjects;

	Ship ship;
	Ship ship2;
};

} /* namespace ast */

#endif /* ENGINE_WORLD_WORLD_H_ */
