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

bool operator<(const sf::Vector2i& v1, const sf::Vector2i& v2)
{
	int l1 = pow(v1.x, 2) + pow(v1.y, 2);
	int l2 = pow(v2.x, 2) + pow(v2.y, 2);
	float a1 = atan2(v1.y, v1.x);
	float a2 = atan2(v2.y, v2.x);
	if(l1 == l2)
	{
		return a1 < a2;
	}
	else
	{
		return l1 < l2;
	}
}

sf::IntRect getGridRect(int cellSize, const sf::Vector2i position)
{
	return sf::IntRect{position.x*cellSize, position.y*cellSize, cellSize, cellSize};
}

/*
 * geometry.cpp
 *
 *  Created on: Dec 5, 2015
 *      Author: daniel
 */




