/*
 * Action.h
 *
 *  Created on: Nov 30, 2015
 *      Author: daniel
 */

#ifndef ENGINE_ACTIONS_ACTION_H_
#define ENGINE_ACTIONS_ACTION_H_

namespace ast
{

class ActionSender;

class Action
{

public:
	Action(ActionSender* lpSender, int actionID);
	virtual ~Action();

	ActionSender* getSender() const;
	int getID() const;
protected:
	ActionSender* lpSender;
	int actionID;
};

} /* namespace ast */

#endif /* ENGINE_ACTIONS_ACTION_H_ */
