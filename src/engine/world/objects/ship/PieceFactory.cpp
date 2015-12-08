/*
 * PieceFactory.cpp
 *
 *  Created on: Dec 7, 2015
 *      Author: daniel
 */

#include "PieceFactory.h"

namespace ast
{

Piece PieceFactory::getPiece(Piece::Type type, const sf::Vector2f& origin, int rotation)
{
	if(type == Piece::Type::FULL) return getFullPiece(origin, rotation);
	else if(type == Piece::Type::HALF) return getHalfPiece(origin, rotation);
	else if(type == Piece::Type::COMMAND) return getCommandPiece(origin, rotation);
	else if(type == Piece::Type::FUEL) return getFuelPiece(origin, rotation);
	else if(type == Piece::Type::ENGINE) return getEnginePiece(origin, rotation);
	else return getFullPiece(origin, rotation);
}

Piece PieceFactory::getFullPiece(const sf::Vector2f& origin, int rotation)
{
	Piece res;
	Model model;
	model.getTriangles() =
	{
		Triangle{sf::Vector2f{0.f, 0.f} + origin, sf::Vector2f{1.f, 0.f} + origin, sf::Vector2f{1.f, 1.f} + origin},
		Triangle{sf::Vector2f{0.f, 0.f} + origin, sf::Vector2f{1.f, 1.f} + origin, sf::Vector2f{0.f, 1.f} + origin},
	};
	res.setModel(model);
	return res;
}

Piece PieceFactory::getHalfPiece(const sf::Vector2f& origin, int rotation)
{
	Piece res;
	Triangle triangle1{sf::Vector2f{-0.5f, -0.5f}, sf::Vector2f{0.5f, -0.5f}, sf::Vector2f{0.5f, 0.5f}};
	Triangle triangle2{sf::Vector2f{-0.5f, -0.5f}, sf::Vector2f{0.5f, 0.5f}, sf::Vector2f{-0.5f, 0.5f}};
	Model model;
	model.getTriangles() =
	{
		Triangle{sf::Vector2f{-0.5f, -0.5f} + origin, sf::Vector2f{0.5f, -0.5f} + origin, sf::Vector2f{0.5f, 0.5f} + origin},
		Triangle{sf::Vector2f{-0.5f, -0.5f} + origin, sf::Vector2f{0.5f, 0.5f} + origin, sf::Vector2f{-0.5f, 0.5f} + origin},
	};
	res.setModel(model);
	return res;
}

Piece PieceFactory::getCommandPiece(const sf::Vector2f& origin, int rotation)
{
}

Piece PieceFactory::getFuelPiece(const sf::Vector2f& origin, int rotation)
{
}

Piece PieceFactory::getEnginePiece(const sf::Vector2f& origin, int rotation)
{
}

} /* namespace ast */
