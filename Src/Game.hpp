//
//  Game.hpp
//  AI_SDL_mac
//
//  Created by yuanlinhu on 2019/8/10.
//  Copyright © 2019 yuanlinhu. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include "Macros.hpp"

class GameObjectMgr;


class Game
{
public:
    Game();
    ~Game();
    
    void init(const char* title, int x, int y, int w, int h, bool full_screen);
    
    void handleEvents();
    void update();
    void render();
    void clean();
    
    bool running();
    

public:
	void loadGameObj();
    
private:
    bool m_is_running = false;
    SDL_Window *m_window;
	SDL_Renderer* m_render;

	GameObjectMgr*	m_gameObjMgr;

};







#endif /* Game_hpp */
