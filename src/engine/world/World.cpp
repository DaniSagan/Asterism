/*
 * World.cpp
 *
 *  Created on: Dec 3, 2015
 *      Author: daniel
 */

#include "World.h"

namespace ast
{

World::World()
{
	ship.setInertiaMoment(10000.f);
	ship.setMass(100.f);

	ship2.setInertiaMoment(10000.f);
	ship2.setMass(100.f);
	ship2.setPosition(sf::Vector2f{200, 0});

}

World::~World()
{
	// TODO Auto-generated destructor stub
}

void World::onAction(const Action& action)
{
}

const Ship& World::getShip() const
{
	return ship;
}

const Ship& World::getShip2() const
{
	return ship2;
}

Ship& World::getShip()
{
	return ship;
}

} /* namespace ast */


