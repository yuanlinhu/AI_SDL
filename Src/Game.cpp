//
//  Game.cpp
//  AI_SDL_mac
//
//  Created by yuanlinhu on 2019/8/10.
//  Copyright © 2019 yuanlinhu. All rights reserved.
//



#include "Game.hpp"

#include "SDL_image.h"

SDL_Surface *image;
SDL_Texture *texture;

Game::Game()
{
    
}

Game::~Game()
{
    
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
        m_is_running = true;
    }
    


	//IMG_Init(IMG_INIT_JPG);
	//IMG_Init(IMG_INIT_PNG);
	//IMG_Init(IMG_INIT_TIF);
	//IMG_Init(IMG_INIT_WEBP);
	// load sample.png into image
	image = IMG_Load("../Asset/1.bmp");
	if (!image) {
		printf("IMG_Load: %s\n", IMG_GetError());
		// handle error
	}

	texture = SDL_CreateTextureFromSurface(m_render, image);

	//texture

	int jj = 0;
    
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    
    switch (event.type) {
        case SDL_QUIT:
            m_is_running = false;
            break;
            
        default:
            break;
    }
}

void Game::update()
{
    
}

void Game::render()
{
    SDL_RenderClear(m_render);
    
	SDL_RenderCopy(m_render, texture, nullptr, nullptr);
    SDL_RenderPresent(m_render);
}

void Game::clean()
{
    SDL_DestroyRenderer(m_render);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

bool Game::running()
{
    return m_is_running;
}
