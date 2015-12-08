/*
 * ActionSender.cpp
 *
 *  Created on: Nov 30, 2015
 *      Author: daniel
 */

#include "ActionSender.h"

#include "Action.h"
#include "ActionListener.h"

namespace ast
{

ActionSender::ActionSender()
{
	// TODO Auto-generated constructor stub

}

ActionSender::~ActionSender()
{
	// TODO Auto-generated destructor stub
}

void ActionSender::send(const Action& action)
{
	std::cout << "ActionSender::send" << std::endl;
	for(ActionListener* l: lpListeners)
	{
		std::cout << "Sending one action" << std::endl;
		l->onAction(action);
	}
}

void ActionSender::addSubscriber(ActionListener* lpListener)
{
	this->lpListeners.push_back(lpListener);
}

} /* namespace ast */
