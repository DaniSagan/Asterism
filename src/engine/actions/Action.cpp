/*
 * Action.cpp
 *
 *  Created on: Nov 30, 2015
 *      Author: daniel
 */

#include "Action.h"

#include "ActionSender.h"

namespace ast
{

Action::Action(ActionSender* lpSender, int actionID):
		lpSender(lpSender), actionID(actionID)
{
	// TODO Auto-generated constructor stub

}

Action::~Action()
{
	// TODO Auto-generated destructor stub
}

ActionSender* Action::getSender() const
{
	return lpSender;
}

int Action::getID() const
{
	return actionID;
}

} /* namespace ast */
