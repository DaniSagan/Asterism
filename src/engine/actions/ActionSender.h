/*
 * ActionSender.h
 *
 *  Created on: Nov 30, 2015
 *      Author: daniel
 */

#ifndef ENGINE_ACTIONS_ACTIONSENDER_H_
#define ENGINE_ACTIONS_ACTIONSENDER_H_

#include <vector>
#include <iostream>

namespace ast
{

class Action;
class ActionListener;

class ActionSender
{
public:
	ActionSender();
	virtual ~ActionSender();

	void send(const Action& action);
	void addSubscriber(ActionListener* lpListener);

protected:
	std::vector<ActionListener*> lpListeners;
};

} /* namespace ast */

#endif /* ENGINE_ACTIONS_ACTIONSENDER_H_ */
