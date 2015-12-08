/*
 * Ship.cpp
 *
 *  Created on: Dec 3, 2015
 *      Author: daniel
 */

#include "Ship.h"

namespace ast
{

Ship::Ship()
{
	// TODO Auto-generated constructor stub

}

Ship::~Ship()
{
	// TODO Auto-generated destructor stub
}

void Ship::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
}

void Ship::build(const std::vector<Piece>& pieceList)
{
	float totalMass = 0.f;
	for(const Piece& p: pieceList)
	{
		totalMass += p.getModel().getMass();
	}
	mass = totalMass;

	sf::Vector2f tempBarycenter{0.f, 0.f};
	for(const Piece& p: pieceList)
	{
		tempBarycenter += p.getModel().getBarycenter();
	}

	for(const Piece& p: pieceList)
	{
		pieces.push_back(p);
	}
}

} /* namespace ast */


