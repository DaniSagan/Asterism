/*
 * ActionListener.cpp
 *
 *  Created on: Nov 30, 2015
 *      Author: daniel
 */

#include "ActionListener.h"

#include "ActionSender.h"
#include "Action.h"

namespace ast
{

ActionListener::ActionListener()
{
	// TODO Auto-generated constructor stub

}

ActionListener::~ActionListener()
{
	// TODO Auto-generated destructor stub
}

void ActionListener::subscribe(ActionSender* lpSender)
{
	lpSenders.push_back(lpSender);
	lpSender->addSubscriber(this);
}

} /* namespace ast */
