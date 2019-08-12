//
//  main.cpp
//  AI_SDL_mac
//
//  Created by yuanlinhu on 2019/8/10.
//  Copyright © 2019 yuanlinhu. All rights reserved.
//

#include <iostream>
#include "Game.hpp"

int main(int argc, char * argv[]) {
    
    Game game;
    
    game.init("AI_SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, false);
    while(game.running())
    {
        game.handleEvents();
        game.update();
        game.render();
    }
    
    game.clean();
    
    return 0;
}
