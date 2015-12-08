/*
 * ActionListener.h
 *
 *  Created on: Nov 30, 2015
 *      Author: daniel
 */

#ifndef ENGINE_ACTIONS_ACTIONLISTENER_H_
#define ENGINE_ACTIONS_ACTIONLISTENER_H_

#include <vector>

namespace ast
{

class Action;
class ActionSender;

class ActionListener
{

public:
	ActionListener();
	virtual ~ActionListener();

	void subscribe(ActionSender* lpSender);
	virtual void onAction(const Action& action) = 0;

protected:
	std::vector<ActionSender*> lpSenders;
};

} /* namespace ast */

#endif /* ENGINE_ACTIONS_ACTIONLISTENER_H_ */
