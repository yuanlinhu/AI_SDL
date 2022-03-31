//
//  main.cpp
//  AI_SDL_mac
//
//  Created by yuanlinhu on 2019/8/10.
//  Copyright © 2019 yuanlinhu. All rights reserved.
//

#include <iostream>
#include "Game.hpp"

int main(int argc, char * argv[]) 
{
	srand((unsigned int)time(NULL));

    Game game;
	game.go();
    return 0;
}
