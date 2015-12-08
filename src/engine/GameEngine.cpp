/*
 * GameEngine.cpp
 *
 *  Created on: Nov 30, 2015
 *      Author: daniel
 */

#include "GameEngine.h"

namespace ast
{

GameEngine::GameEngine():
		running(true), lpState(nullptr)
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	window.create(sf::VideoMode(1024, 600), "Asterism", sf::Style::Close, settings);
	resources.load();

}

GameEngine::~GameEngine()
{
	// TODO Auto-generated destructor stub
}

void GameEngine::run()
{
	changeState(&splashState);
	subscribe(&splashState);
	subscribe(&startState);
	subscribe(&playState);
	subscribe(&editorState);
	while(running)
	{
		update();
		handleInput();
		render();
	}
}

void GameEngine::update()
{
	lpState->update(clock.restart().asSeconds());
}

void GameEngine::handleInput()
{
	sf::Event event;
	while(window.pollEvent(event))
	{
		lpState->handleEvent(event);
	}
}

void GameEngine::render()
{
	lpState->render(window, resources);
}

void GameEngine::changeState(GameState* newState)
{
	lpState = newState;
}

void GameEngine::onAction(const Action& action)
{
	std::cout << "Action received" << std::endl;
	if(action.getSender() == &splashState)
	{
		if(action.getID() == SplashState::ActionID::FINISHED)
		{
			changeState(&startState);
		}
	}
	else if(action.getSender() == &startState)
	{
		if(action.getID() == StartState::ActionID::CLOSE)
		{
			running = false;
		}
		else if(action.getID() == StartState::ActionID::PLAY)
		{
			changeState(&playState);
		}
		else if(action.getID() == StartState::ActionID::EDITOR)
		{
			changeState(&editorState);
		}
	}
	else if(action.getSender() == &playState)
	{
		if(action.getID() == PlayState::ActionID::EXIT)
		{
			changeState(&startState);
		}
	}
	else if(action.getSender() == &editorState)
	{
		if(action.getID() == EditorState::ActionID::EXIT)
		{
			changeState(&startState);
		}
	}
}

} /* namespace ast */
