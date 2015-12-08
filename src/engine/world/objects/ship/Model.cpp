/*
 * Model.cpp
 *
 *  Created on: Dec 7, 2015
 *      Author: daniel
 */

#include "Model.h"

namespace ast
{

Model::Model()
{
	// TODO Auto-generated constructor stub

}

Model::~Model()
{
	// TODO Auto-generated destructor stub
}

std::vector<Triangle>& Model::getTriangles()
{
	return triangles;
}

float Model::getMass() const
{
	float res = 0.f;
	for(Triangle t: triangles)
	{
		res += t.getMass();
	}
	return res;
}

sf::Vector2f Model::getBarycenter() const
{
	sf::Vector2f res{0.f, 0.f};
	float totalMass = getMass();
	for(Triangle t: triangles)
	{
		res += (t.getMass()/totalMass) * t.getBarycenter();
	}
	return res;
}

bool Model::contains(const sf::Vector2f& point) const
{
	for(Triangle t: triangles)
	{
		if(t.contains(point))
		{
			return true;
		}
	}
	return false;
}

} /* namespace ast */
