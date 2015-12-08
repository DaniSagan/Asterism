/*
 * Ship.h
 *
 *  Created on: Dec 3, 2015
 *      Author: daniel
 */

#ifndef ENGINE_WORLD_OBJECTS_SHIP_H_
#define ENGINE_WORLD_OBJECTS_SHIP_H_

#include "RenderableObject.h"
#include "ship/Piece.h"

namespace ast
{

class Ship: public RenderableObject
{
public:
	Ship();
	virtual ~Ship();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void build(const std::vector<Piece>& pieces);

protected:
	std::vector<Piece> pieces;

};

} /* namespace ast */

#endif /* ENGINE_WORLD_OBJECTS_SHIP_H_ */
