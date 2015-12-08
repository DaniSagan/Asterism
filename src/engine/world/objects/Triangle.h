/*
 * Triangle.h
 *
 *  Created on: Dec 7, 2015
 *      Author: daniel
 */

#ifndef ENGINE_WORLD_OBJECTS_TRIANGLE_H_
#define ENGINE_WORLD_OBJECTS_TRIANGLE_H_

#include "../../data/geometry.h"
#include <functional>
#include <SFML/Graphics.hpp>

namespace ast
{

class Triangle
{
public:
	Triangle(const sf::Vector2f& v1, const sf::Vector2f& v2, const sf::Vector2f& v3);
	virtual ~Triangle();

	bool contains(const sf::Vector2f& v) const;
	float getDensity() const;
	void setDensity(float density);

	float getArea() const;
	float getMass() const;
	sf::Vector2f getBarycenter() const;

	Triangle& transform(std::function<sf::Vector2f(const sf::Vector2f&)> fn);

protected:
	sf::Vector2f v1;
	sf::Vector2f v2;
	sf::Vector2f v3;
	float density;

};

} /* namespace ast */

#endif /* ENGINE_WORLD_OBJECTS_TRIANGLE_H_ */
