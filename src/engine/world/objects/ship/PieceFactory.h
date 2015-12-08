/*
 * PieceFactory.h
 *
 *  Created on: Dec 7, 2015
 *      Author: daniel
 */

#include "Piece.h"

#ifndef ENGINE_WORLD_OBJECTS_SHIP_PIECEFACTORY_H_
#define ENGINE_WORLD_OBJECTS_SHIP_PIECEFACTORY_H_

namespace ast
{

class PieceFactory
{
public:
	static Piece getPiece(Piece::Type type, const sf::Vector2f& origin, int rotation);

protected:
	static Piece getFullPiece(const sf::Vector2f& origin, int rotation);
	static Piece getHalfPiece(const sf::Vector2f& origin, int rotation);
	static Piece getCommandPiece(const sf::Vector2f& origin, int rotation);
	static Piece getFuelPiece(const sf::Vector2f& origin, int rotation);
	static Piece getEnginePiece(const sf::Vector2f& origin, int rotation);
};

} /* namespace ast */

#endif /* ENGINE_WORLD_OBJECTS_SHIP_PIECEFACTORY_H_ */
