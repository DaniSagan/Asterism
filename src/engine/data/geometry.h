/*
 * geometry.h
 *
 *  Created on: Dec 5, 2015
 *      Author: daniel
 */

#ifndef ENGINE_DATA_GEOMETRY_H_
#define ENGINE_DATA_GEOMETRY_H_

#include <cmath>
#include <SFML/Graphics.hpp>

float length(const sf::Vector2f& v);
sf::Vector2f unit(const sf::Vector2f& v);
float dot(const sf::Vector2f& v1, const sf::Vector2f& v2);
float cross(const sf::Vector2f& v1, const sf::Vector2f& v2);
sf::Vector2f rotate(const sf::Vector2f v, float angle);

#endif /* ENGINE_DATA_GEOMETRY_H_ */
