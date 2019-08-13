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

class Font;

class GameObjectMgr;


class Game
{
public:
    Game();
    ~Game();
    
	void go();

    void init(const char* title, int x, int y, int w, int h, bool full_screen);
    
    void handleEvents();
    void update(Uint32 delta);
    void render();
    void clean();
    
	//SDL_Texture* RenderText(std::string message, std::string fontFile,
	//	SDL_Color color, int fontSize);

    bool running();

	bool setNeedHighCPU(bool b) { m_needHighCPU = b; }
    
public:
	void setViewPort();

public:
	void loadGameObj();
    

	//模拟高延迟逻辑
	void HighCpuFunc();

private:
	void handleKeyboard(SDL_Event& event);



private:
	
	int	m_countedFrames = 0;
    bool m_is_running = false;
    SDL_Window *m_window;
	SDL_Renderer* m_render;
	GameObjectMgr*	m_gameObjMgr;
	bool	m_needHighCPU = false;

	//SDL_Texture*		m_font_texture;
	//SDL_Rect		m_font_rect;

	Font*			m_FpsFont;
};







#endif /* Game_hpp */
