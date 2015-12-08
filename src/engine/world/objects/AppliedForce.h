/*
 * AppliedForce.h
 *
 *  Created on: Dec 5, 2015
 *      Author: daniel
 */

#ifndef ENGINE_WORLD_OBJECTS_APPLIEDFORCE_H_
#define ENGINE_WORLD_OBJECTS_APPLIEDFORCE_H_

#include <SFML/Graphics.hpp>

namespace ast
{

class AppliedForce
{
public:
	AppliedForce(const sf::Vector2f& force, const sf::Vector2f& position);
	virtual ~AppliedForce();

	sf::Vector2f force;
	sf::Vector2f position;
};

} /* namespace ast */

#endif /* ENGINE_WORLD_OBJECTS_APPLIEDFORCE_H_ */
