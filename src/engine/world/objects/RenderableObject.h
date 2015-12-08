/*
 * RenderableObject.h
 *
 *  Created on: Dec 3, 2015
 *      Author: daniel
 */

#ifndef ENGINE_WORLD_OBJECTS_RENDERABLEOBJECT_H_
#define ENGINE_WORLD_OBJECTS_RENDERABLEOBJECT_H_

#include "WorldObject.h"

namespace ast
{

class RenderableObject: public WorldObject, sf::Drawable
{
public:
	RenderableObject();
	virtual ~RenderableObject();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};

} /* namespace ast */

#endif /* ENGINE_WORLD_OBJECTS_RENDERABLEOBJECT_H_ */
