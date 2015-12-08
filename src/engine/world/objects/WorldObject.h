/*
 * WorldObject.h
 *
 *  Created on: Dec 3, 2015
 *      Author: daniel
 */

#ifndef ENGINE_WORLD_OBJECTS_WORLDOBJECT_H_
#define ENGINE_WORLD_OBJECTS_WORLDOBJECT_H_

#include "../../actions/actions.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "AppliedForce.h"
#include "../../data/geometry.h"

namespace ast
{

class WorldObject: public ActionSender
{
public:
	WorldObject();
	virtual ~WorldObject();

	virtual void update(float dt);

	int getId() const;
	void setId(int id);
	sf::Vector2f getPosition() const;
	void setPosition(sf::Vector2f position);
	sf::Vector2f getVelocity() const;
	void setVelocity(sf::Vector2f velocity);
	void applyForce(const sf::Vector2f& force, const sf::Vector2f& position);
	float getAngle() const;
	void setAngle(float angle);
	float getAngularVelocity() const;
	void setAngularVelocity(float angularVelocity);
	float getInertiaMoment() const;
	void setInertiaMoment(float inertiaMoment);
	sf::Vector2f getLinearVelocity() const;
	void setLinearVelocity(sf::Vector2f linearVelocity);
	float getMass() const;
	void setMass(float mass);

protected:
	int ID;
	sf::Vector2f position;
	sf::Vector2f linearVelocity;
	float angularVelocity;
	float angle;
	float mass;
	float inertiaMoment;
	std::vector<AppliedForce> forces;
};

} /* namespace ast */

#endif /* ENGINE_WORLD_OBJECTS_WORLDOBJECT_H_ */
