/*
 * Piece.cpp
 *
 *  Created on: Dec 6, 2015
 *      Author: daniel
 */

#include "Piece.h"

namespace ast
{

Piece::Piece()
{
	// TODO Auto-generated constructor stub

}

Piece::~Piece()
{
	// TODO Auto-generated destructor stub
}

const Model& Piece::getModel() const
{
	return model;
}

void Piece::setModel(const Model& model)
{
	this->model = model;
}

int Piece::getRotation() const
{
	return rotation;
}

void Piece::setRotation(int rotation)
{
	this->rotation = rotation;
}

const sf::IntRect& Piece::getTextureRect() const
{
	return textureRect;
}

void Piece::setTextureRect(const sf::IntRect& textureRect)
{
	this->textureRect = textureRect;
}

Piece::Type Piece::getType() const
{
	return type;
}

void Piece::setType(Type type)
{
	this->type = type;
}

} /* namespace ast */


