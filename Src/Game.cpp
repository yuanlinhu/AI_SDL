//
//  Game.cpp
//  AI_SDL_mac
//
//  Created by yuanlinhu on 2019/8/10.
//  Copyright © 2019 yuanlinhu. All rights reserved.
//


#include "GameObject.hpp"
#include "Game.hpp"


//SDL_Surface *image;
//SDL_Texture *texture;
//SDL_Surface *gHelloWorld;
//SDL_Texture *hello_texture;


GameObject* gameObj;

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

		IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);

        m_is_running = true;
    }
    

	gameObj = new GameObject(m_render);
	gameObj->init(0, 0, 100, 100, "../Asset/grass.jpg");


	//IMG_Init(IMG_INIT_JPG);
	//IMG_Init(IMG_INIT_PNG);
	//IMG_Init(IMG_INIT_TIF);
	//IMG_Init(IMG_INIT_WEBP);
	// load sample.png into image
	//image = IMG_Load("../Asset/grass.jpg");
	//if (!image) {
	//	printf("IMG_Load: %s\n", IMG_GetError());
	//	// handle error
	//}

	//texture = SDL_CreateTextureFromSurface(m_render, image);

	//gHelloWorld = SDL_LoadBMP("../Asset/1.bmp");
	//if (gHelloWorld == NULL)
	//{
	//	printf("Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError());
	//}

	//hello_texture = SDL_CreateTextureFromSurface(m_render, gHelloWorld);

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
	gameObj->update();
}

void Game::render()
{
    SDL_RenderClear(m_render);
    
	//Top left corner viewport
	SDL_Rect topLeftViewport;
	topLeftViewport.x = 0;
	topLeftViewport.y = 0;
	topLeftViewport.w = 50;
	topLeftViewport.h = 50;
	//SDL_RenderSetViewport(m_render, &topLeftViewport);

	//{
	//	SDL_Rect srcrect;
	//	srcrect.x = 0;
	//	srcrect.y = 0;
	//	srcrect.w = 100;
	//	srcrect.h = 100;

	//	SDL_RenderCopy(m_render, texture, NULL, &srcrect);
	//}

	//{
	//	SDL_Rect srcrect;
	//	srcrect.x = 200;
	//	srcrect.y = 200;
	//	srcrect.w = 100;
	//	srcrect.h = 100;

	//	SDL_RenderCopy(m_render, hello_texture, NULL, &srcrect);
	//}
	
	
	//SDL_SetRenderDrawColor(m_render, 0x00, 0x00, 0xFF, 0xFF);
	//SDL_RenderDrawLine(m_render, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2);

	gameObj->render(m_render);

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
