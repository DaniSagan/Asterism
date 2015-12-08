/*
 * Resources.h
 *
 *  Created on: Dec 5, 2015
 *      Author: daniel
 */

#ifndef ENGINE_RESOURCES_H_
#define ENGINE_RESOURCES_H_

#include <SFML/Graphics.hpp>
#include <stdexcept>

namespace ast
{

class Resources
{
public:
	Resources();
	virtual ~Resources();

	void load();

	const sf::Font& getFont() const;
	const sf::Texture& getShipTexture() const;
	const sf::Texture& getShip2Texture() const;
	const sf::Texture& getBgTexture() const;
	const sf::Texture& getTextureAtlas() const;

protected:
	sf::Font font;
	sf::Texture shipTexture;
	sf::Texture ship2Texture;
	sf::Texture bgTexture;
	sf::Texture textureAtlas;
};

} /* namespace ast */

#endif /* ENGINE_RESOURCES_H_ */
