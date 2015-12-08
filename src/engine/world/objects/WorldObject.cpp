/*
 * WorldObject.cpp
 *
 *  Created on: Dec 3, 2015
 *      Author: daniel
 */

#include "WorldObject.h"

namespace ast
{

WorldObject::WorldObject():
		ID(0), angularVelocity(0.f), angle(0.f), mass(1.f), inertiaMoment(1.f)
{
	// TODO Auto-generated constructor stub

}

WorldObject::~WorldObject()
{
	// TODO Auto-generated destructor stub
}

int WorldObject::getId() const
{
	return ID;
}

void WorldObject::setId(int id)
{
	ID = id;
}

sf::Vector2f WorldObject::getPosition() const
{
	return position;
}

void WorldObject::setPosition(sf::Vector2f position)
{
	this->position = position;
}

sf::Vector2f WorldObject::getVelocity() const
{
	return linearVelocity;
}

void WorldObject::setVelocity(sf::Vector2f velocity)
{
	this->linearVelocity = velocity;
}

void WorldObject::update(float dt)
{
	for(const AppliedForce& f: forces)
	{
		std::cout << "calculating forces" << std::endl;
		sf::Vector2f tForce = rotate(f.force, angle);
		sf::Vector2f tPosition = rotate(f.position, angle);
		sf::Vector2f linearForce = unit(tPosition)*dot(tPosition, tForce);
		float torque = cross(tPosition, tForce);
		linearVelocity += tForce / mass;
		angularVelocity += torque / inertiaMoment;
	}
	position += linearVelocity * dt;
	angle += angularVelocity * dt;
	forces.clear();
}

void WorldObject::applyForce(const sf::Vector2f& force, const sf::Vector2f& position)
{
	this->forces.push_back(AppliedForce{force, position});
}

float WorldObject::getAngle() const
{
	return angle;
}

void WorldObject::setAngle(float angle)
{
	this->angle = angle;
}

float WorldObject::getAngularVelocity() const
{
	return angularVelocity;
}

void WorldObject::setAngularVelocity(float angularVelocity)
{
	this->angularVelocity = angularVelocity;
}

float WorldObject::getInertiaMoment() const
{
	return inertiaMoment;
}

void WorldObject::setInertiaMoment(float inertiaMoment)
{
	this->inertiaMoment = inertiaMoment;
}

sf::Vector2f WorldObject::getLinearVelocity() const
{
	return linearVelocity;
}

void WorldObject::setLinearVelocity(sf::Vector2f linearVelocity)
{
	this->linearVelocity = linearVelocity;
}

float WorldObject::getMass() const
{
	return mass;
}

void WorldObject::setMass(float mass)
{
	this->mass = mass;
}

} /* namespace ast */


