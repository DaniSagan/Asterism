/*
 * Triangle.cpp
 *
 *  Created on: Dec 7, 2015
 *      Author: daniel
 */

#include "Triangle.h"
#include <functional>

namespace ast
{

Triangle::Triangle(const sf::Vector2f& v1, const sf::Vector2f& v2, const sf::Vector2f& v3):
		v1(v1), v2(v2), v3(v3), density(1.f)
{
	// TODO Auto-generated constructor stub

}

Triangle::~Triangle()
{
	// TODO Auto-generated destructor stub
}

bool Triangle::contains(const sf::Vector2f& v) const
{
	sf::Vector2f w1 = v2 - v1;
	sf::Vector2f w2 = v3 - v1;
	sf::Vector2f p = v - v1;

	float det = w1.x*w2.y - w1.y*w2.x;
	float s = (1.0f/det)*(w2.y*p.x - w2.x*p.y);
	float t = (1.0f/det)*(-w1.y*p.x + w1.x*p.y);

	return (0.f <= s && s <= 1.f) && (0.f <= t && t <= 1.f) && (s+t <= 1.f);
}

float Triangle::getDensity() const
{
	return density;
}

void Triangle::setDensity(float density)
{
	this->density = density;
}

float Triangle::getArea() const
{
	return 0.5 * cross(v2-v1, v3-v2);
}

float Triangle::getMass() const
{
	return density * getArea();
}

sf::Vector2f Triangle::getBarycenter() const
{
	return (1.f/3.f)*(v1 + v2 + v3);
}

Triangle& Triangle::transform(std::function<sf::Vector2f(const sf::Vector2f&)> fn)
{
	v1 = fn(v1);
	v2 = fn(v2);
	v3 = fn(v3);
	return *this;
}

} /* namespace ast */
