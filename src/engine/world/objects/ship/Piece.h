/*
 * Piece.h
 *
 *  Created on: Dec 6, 2015
 *      Author: daniel
 */

#ifndef ENGINE_WORLD_OBJECTS_SHIP_PIECE_H_
#define ENGINE_WORLD_OBJECTS_SHIP_PIECE_H_

#include "Model.h"
#include <SFML/Graphics.hpp>

namespace ast
{

class Piece
{
public:
	Piece();
	virtual ~Piece();

	enum Type
	{
		NONE,
		COMMAND,
		FULL,
		HALF,
		FUEL,
		ENGINE
	};

	const Model& getModel() const;
	void setModel(const Model& model);
	int getRotation() const;
	void setRotation(int rotation);
	const sf::IntRect& getTextureRect() const;
	void setTextureRect(const sf::IntRect& textureRect);
	Type getType() const;
	void setType(Type type);

protected:
	int rotation;
	Type type;
	Model model;
	sf::IntRect textureRect;
};

} /* namespace ast */

#endif /* ENGINE_WORLD_OBJECTS_SHIP_PIECE_H_ */
