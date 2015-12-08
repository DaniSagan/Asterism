/*
 * GameEngine.h
 *
 *  Created on: Nov 30, 2015
 *      Author: daniel
 */

#ifndef ENGINE_GAMEENGINE_H_
#define ENGINE_GAMEENGINE_H_

#include <memory>

#include "actions/actions.h"
#include "GameState.h"
#include "states/SplashState.h"
#include "states/StartState.h"
#include "states/PlayState.h"
#include "states/EditorState.h"
#include "Resources.h"
#include <SFML/Graphics.hpp>

namespace ast
{

class GameEngine: public ActionListener
{
public:
	GameEngine();
	virtual ~GameEngine();

	void run();
	void update();
	void handleInput();
	void render();
	void changeState(GameState* newState);
	void onAction(const Action& action);

protected:
	bool running;
	sf::RenderWindow window;
	GameState* lpState;

	SplashState splashState;
	StartState startState;
	PlayState playState;
	EditorState editorState;

	Resources resources;

	sf::Clock clock;
};

} /* namespace ast */

#endif /* ENGINE_GAMEENGINE_H_ */
