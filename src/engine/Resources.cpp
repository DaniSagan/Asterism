/*
 * Resources.cpp
 *
 *  Created on: Dec 5, 2015
 *      Author: daniel
 */

#include "Resources.h"

namespace ast
{

Resources::Resources()
{
	// TODO Auto-generated constructor stub

}

Resources::~Resources()
{
	// TODO Auto-generated destructor stub
}

void Resources::load()
{
	if(!lightFont.loadFromFile("res/font/Open_Sans/OpenSans-Light.ttf"))
	{
		throw std::runtime_error("Font not found");
	}
	if(!font.loadFromFile("res/font/Open_Sans/OpenSans-Regular.ttf"))
	{
		throw std::runtime_error("Font not found");
	}
	if(!shipTexture.loadFromFile("res/img/ship.png"))
	{
		throw std::runtime_error("Texture not found");
	}
	shipTexture.setSmooth(true);
	if(!ship2Texture.loadFromFile("res/img/ship2.png"))
	{
		throw std::runtime_error("Texture not found");
	}
	ship2Texture.setSmooth(true);
	if(!bgTexture.loadFromFile("res/img/bg.jpg"))
	{
		throw std::runtime_error("Texture not found");
	}
	bgTexture.setRepeated(true);
	if(!textureAtlas.loadFromFile("res/img/textures.png"))
	{
		throw std::runtime_error("Texture not found");
	}
	textureAtlas.setSmooth(true);
}

const sf::Font& Resources::getLightFont() const
{
	return lightFont;
}

const sf::Font& Resources::getFont() const
{
	return font;
}

const sf::Texture& Resources::getShipTexture() const
{
	return shipTexture;
}

const sf::Texture& Resources::getShip2Texture() const
{
	return ship2Texture;
}

const sf::Texture& Resources::getBgTexture() const
{
	return bgTexture;
}

const sf::Texture& Resources::getTextureAtlas() const
{
	return textureAtlas;
}

} /* namespace ast */


