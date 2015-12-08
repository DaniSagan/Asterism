//============================================================================
// Name        : Asterism.cpp
// Author      : Daniel Fernández Villanueva
// Version     :
// Copyright   : <>
// Description : Asterism, the game
//============================================================================

#include <iostream>
#include "engine/GameEngine.h"
#include <vector>
#include <functional>

#include "engine/data/functionalUtils.h"

int main() {

	std::vector<int> v(4);
	int count = 0;
	for(int& i: v)
	{
		i = count;
		++count;
	}
	int res = foldl([](int x, int y) -> int {return x+y;}, 0, v);
	std::cout << res << std::endl;


	ast::GameEngine game;
	game.run();
	return 0;
}
