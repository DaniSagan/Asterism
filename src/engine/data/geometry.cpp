#include "geometry.h"

float length(const sf::Vector2f& v)
{
	return sqrt(pow(v.x, 2) + pow(v.y, 2));
}


sf::Vector2f unit(const sf::Vector2f& v)
{
	return v/length(v);
}


float dot(const sf::Vector2f& v1, const sf::Vector2f& v2)
{
	return v1.x*v2.x + v1.y*v2.y;
}


float cross(const sf::Vector2f& v1, const sf::Vector2f& v2)
{
	return v1.x*v2.y - v1.y*v2.x;
}

sf::Vector2f rotate(const sf::Vector2f v, float angle)
{
	return sf::Vector2f{
		v.x*cos(angle) - v.y*sin(angle),
		v.x*sin(angle) + v.y*cos(angle)
	};
}

/*
 * geometry.cpp
 *
 *  Created on: Dec 5, 2015
 *      Author: daniel
 */




