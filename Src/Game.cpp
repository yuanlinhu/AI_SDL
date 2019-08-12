//
//  Game.cpp
//  AI_SDL_mac
//
//  Created by yuanlinhu on 2019/8/10.
//  Copyright © 2019 yuanlinhu. All rights reserved.
//



#include "Game.hpp"
#include "GameObject.hpp"
#include "GameObjectMgr.hpp"


//SDL_Surface *image;
//SDL_Texture *texture;
//SDL_Surface *gHelloWorld;
//SDL_Texture *hello_texture;


//GameObject* gameObj;

Game::Game()
{
	m_gameObjMgr = new GameObjectMgr();
}

Game::~Game()
{
    
}

void Game::go()
{
	init("AI_SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, false);

	Uint32 frameTick = SDL_GetTicks();
	Uint32 startTicks = 0;
	Uint32 endTicks = 0;
	Uint32 ellapseTicks = 0;
	while (running())
	{
		startTicks = SDL_GetTicks();
		handleEvents();
		update();
		render();
		m_countedFrames++;

		endTicks = SDL_GetTicks();
		ellapseTicks = endTicks - startTicks;
		if (ellapseTicks < 1000 / FRAMES_PER_SECOND)
		{
			//休眠一段时间，时长为当前帧的剩余时间。
			SDL_Delay((1000 / FRAMES_PER_SECOND) - ellapseTicks);
		}

		cout << "Frame: " << int(m_countedFrames / ((SDL_GetTicks() - frameTick) / 1000.f)) << endl;
	}

	clean();
}

void Game::loadGameObj()
{
	
	m_gameObjMgr->createGameObject(0, 0, 100, 100, "../Asset/grass.jpg");

	m_gameObjMgr->createGameObject(150, 0, 100, 100, "../Asset/grass.jpg");

	m_gameObjMgr->createGameObject(100, 100, 100, 100, "../Asset/grass.jpg");
}

void Game::init(const char* title, int x, int y, int w, int h, bool full_screen)
{
    int flags = 0;
    if(full_screen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        m_window = SDL_CreateWindow(title, x, y, w, h, flags);
        
		m_render = SDL_CreateRenderer(m_window, -1, 0);
        
        SDL_SetRenderDrawColor(m_render, 255, 255, 255, 255);

		IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);

    }

	setViewPort();

	m_gameObjMgr->setRender(m_render);

	loadGameObj();

	m_is_running = true;
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    
    switch (event.type) {
        case SDL_QUIT:
            m_is_running = false;
            break;
		case SDL_MOUSEBUTTONDOWN:
		{
			int x = 0;
			int y = 0;
			SDL_GetMouseState(&x, &y);
			break;
		}
		case SDL_MOUSEBUTTONUP:
		{
			int x = 0;
			int y = 0;
			SDL_GetMouseState(&x, &y);
			break;
		}
		case SDL_MOUSEMOTION:
		{
			int x = 0;
			int y = 0;
			SDL_GetMouseState(&x, &y);
			break;
		}
		case SDL_KEYDOWN:
		{
			handleKeyboard(event);
			break;
		}
        default:
            break;
    }
}

void Game::handleKeyboard(SDL_Event& event)
{
	switch (event.key.keysym.sym)
	{
	case SDLK_1:
	{
		break;
	}
	case SDLK_DOWN:
	{
		break;
	}
	case SDLK_LEFT:
	{
		break;
	}
	case SDLK_RIGHT:
	{
		break;
	}
	}
}

void Game::update()
{
	m_gameObjMgr->update();
}

void Game::render()
{
    SDL_RenderClear(m_render);
    

	m_gameObjMgr->render();
    SDL_RenderPresent(m_render);
}

void Game::clean()
{
    SDL_DestroyRenderer(m_render);
    SDL_DestroyWindow(m_window);
	IMG_Quit();
    SDL_Quit();
}

bool Game::running()
{
    return m_is_running;
}

void Game::setViewPort()
{
	SDL_Rect topRightViewport;
	topRightViewport.x = 0;
	topRightViewport.y = 0;
	topRightViewport.w = WINDOW_WIDTH;
	topRightViewport.h = WINDOW_HEIGHT;
	SDL_RenderSetViewport(m_render, &topRightViewport);
}
