/*
 * Model.h
 *
 *  Created on: Dec 7, 2015
 *      Author: daniel
 */

#ifndef ENGINE_WORLD_OBJECTS_SHIP_MODEL_H_
#define ENGINE_WORLD_OBJECTS_SHIP_MODEL_H_

#include "../Triangle.h"
#include <numeric>

namespace ast
{

class Model
{
public:
	Model();
	virtual ~Model();

	std::vector<Triangle>& getTriangles();
	float getMass() const;
	sf::Vector2f getBarycenter() const;
	bool contains(const sf::Vector2f& point) const;

protected:
	std::vector<Triangle> triangles;
};

} /* namespace ast */

#endif /* ENGINE_WORLD_OBJECTS_SHIP_MODEL_H_ */
