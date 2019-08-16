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
#include "Font.hpp"
#include "Geometry.hpp"
#include "TriggerMgr.hpp"
#include "Trigger.hpp"
#include "GameMap.hpp"
#include "BlockMgr.hpp"
#include "Block.hpp"
#include "AStar.hpp"

//SDL_Surface *message = NULL;
//TTF_Font *font = NULL;
//字体的颜色



//SDL_Surface *image;
//SDL_Texture *texture;
//SDL_Surface *gHelloWorld;
//SDL_Texture *hello_texture;


//GameObject* gameObj;

SDL_Renderer* g_render;

Game::Game()
{
	srand((unsigned int)time(NULL));
	m_gameObjMgr = new GameObjectMgr();
	m_GameMap = new GameMap();
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

	static Uint32 lastTicks = SDL_GetTicks();
	while (running())
	{
		startTicks = SDL_GetTicks();
		handleEvents();
		update(startTicks - lastTicks);
		render();
		m_countedFrames++;

		endTicks = SDL_GetTicks();
		ellapseTicks = endTicks - startTicks;
		lastTicks = SDL_GetTicks();
		if (ellapseTicks < 1000 / FRAMES_PER_SECOND)
		{
			//休眠一段时间，时长为当前帧的剩余时间。
			SDL_Delay((1000 / FRAMES_PER_SECOND) - ellapseTicks);
		}

		m_Fps = int(m_countedFrames / ((SDL_GetTicks() - frameTick) / 1000.f));
		//cout << "ellapseTicks: " << ellapseTicks << endl;
		//cout << "Frame: " << int(m_countedFrames / ((SDL_GetTicks() - frameTick) / 1000.f)) << endl;

		//int fps = int(m_countedFrames / ((SDL_GetTicks() - frameTick) / 1000.f));
		

		
	}

	clean();
}

void Game::loadGameObj()
{
	
	//m_gameObjMgr->createGameObject(0, 0, 100, 100, "../Asset/grass.jpg");

	//m_gameObjMgr->createGameObject(150, 0, 100, 100, "../Asset/grass.jpg");
	
	m_GameMap->init(0, 0);

	auto player = m_gameObjMgr->createGameObject(100, 100, 50, 50, "../Asset/player.jpg");
	player->setType(GOT_PLAYER);



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

		//
		IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);

		//初始化SDL_ttf
		if (TTF_Init() == -1)
		{
			
		}

    }

	g_render = m_render;
	m_FpsFont = new Font(m_render);
	SDL_Color textColor = { 255, 0, 0 };
	m_FpsFont->init("LATINWD.TTF", textColor, 10);
	//m_font_texture = RenderText("nihao", "arial.TTF", textColor, 20);
	//font = TTF_OpenFont("lazy.ttf", 28);
	//message = TTF_RenderText_Solid(font, "The quick brown fox jumps over the lazy dog", textColor);

	//设置窗口标题
	//SDL_WM_SetCaption("TTF Test",NULL);

	setViewPort();

	m_gameObjMgr->setRender(m_render);
	m_triggerMgr = new TriggerMgr(m_render);

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
			handleMouseDown(x, y);
			break;
		}
		case SDL_MOUSEBUTTONUP:
		{
			int x = 0;
			int y = 0;
			SDL_GetMouseState(&x, &y);
			handleMouseUp(x, y);
			break;
		}
		case SDL_MOUSEMOTION:
		{
			int x = 0;
			int y = 0;
			SDL_GetMouseState(&x, &y);
			handleMouseMotion(x, y);
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
void Game::handleMouseDown(int x, int y)
{
	//SDL_SetRenderDrawColor(m_render, 0xFF, 0, 0x00, 0xFF);
	//Geometry::DrawCircle(m_render, 10, x, y);
	//Geometry::DrawRect(m_render, x, y, 100, 50);

	m_MousePos.x = x;
	m_MousePos.y = y;

	//m_triggerMgr->createTrigger(TRT_AREA, x, y);

	{
		BlockMgr * blockMgr = m_GameMap->getBlockMgr();
		Block* block = blockMgr->getBlockByPoint(x, y);
		Block* scr_block = blockMgr->getBlockByPoint(1, 1);
		

		blockMgr->resetSelect();
		blockMgr->resetCostG();
		vector<Block*> vec;
		blockMgr->get9GridBlockList(block, vec);
		for (auto& tmp : vec)
		{
			int costG = AStar::calculateG(block, tmp);
			tmp->setCostG(costG);
			int RowIndex = tmp->m_RowIndex;
			int ColIndex = tmp->m_ColIndex;
			cout << "RowIndex : " << RowIndex << ", ColIndex : " << ColIndex << ", costG: " << costG << endl;
			tmp->setSelect(2);
		}

		if (nullptr != block)
		{
			int costH = AStar::calculateH(scr_block, block);
			cout << "costH : " << costH << endl;
			block->setSelect(1);
		}

		list<Block*> outResultList;
		blockMgr->findPath(0, 0, x, y, outResultList);

		int kk = 0;
	}
	
}

void Game::handleMouseUp(int x, int y)
{

}

void Game::handleMouseMotion(int x, int y)
{

}


void Game::handleKeyboard(SDL_Event& event)
{
	GameObject* player = m_gameObjMgr->getPlayer();
	if (nullptr == player)
	{
		return;
	}
	int speed = 5;
	switch (event.key.keysym.sym)
	{
		case SDLK_w:
		{
			player->add_y(-speed);
			break;
		}
		case SDLK_s:
		{
			player->add_y(speed);
			break;
		}
		case SDLK_a:
		{
			player->add_x(-speed);
			break;
		}
		case SDLK_d:
		{
			player->add_x(speed);
			break;
		}
		case SDLK_g:
		{
			player->addHP(speed);
			break;
		}
		case SDLK_h:
		{
			player->addHP(-speed);
			break;
		}
		case SDLK_z:
		{
			player->addHP(-speed);
			break;
		}
	}
}

void Game::update(Uint32 delta)
{
	//cout << "delta: " << delta << endl;
	HighCpuFunc();
	m_FpsFont->update(delta);
	m_triggerMgr->update(this);
	m_gameObjMgr->update(delta);
	m_GameMap->update(delta);

	stringstream strss;
	strss << "fps:" << m_Fps;
	m_FpsFont->setMessage(strss.str(), 200, 10, 50, 20);

}

void Game::render()
{
	SDL_SetRenderDrawColor(m_render, 255, 255, 255, 0xFF);
    SDL_RenderClear(m_render);
	
	m_FpsFont->render();

	m_GameMap->render();

	
	m_triggerMgr->render();
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


void Game::HighCpuFunc()
{
	if (false == m_needHighCPU)
	{
		return;
	}
	long tick = SDL_GetTicks();
	long  i = 0;

	long d = 1000000;	//约 200ms
	long c = 0;
	float x = 0, y = 0;

	
	for (long i = 0; i < d; ++i)
	{
		x = (float)rand() / RAND_MAX;
		y = (float)rand() / RAND_MAX;
		if (sqrt(x * x + y * y) <= 1)
		{
			//++c;
		}
	}
	acos(-1.0);
	//cout << setiosflags(ios::fixed) << setprecision(20) << acos(-1.0) << endl;
	cout << "tick: " << SDL_GetTicks() - tick << endl;
}

void Game::getObjectByCircle(int radius, Point2D& pos, std::vector<GameObject *>& retObjList)
{
	return m_gameObjMgr->getObjectByCircle(radius, pos, retObjList);
}

//SDL_Texture* Game::RenderText(std::string message, std::string fontFile,
//	SDL_Color color, int fontSize)
//{
//	//Open the font
//	TTF_Font *font = nullptr;
//	string absolute_path = "../Asset/ttf/" + fontFile;
//	font = TTF_OpenFont(absolute_path.c_str(), fontSize);
//	if (font == nullptr)
//	{
//		cout << "Failed to load font: " << fontFile << TTF_GetError() << endl;
//	}
//
//	//Render the message to an SDL_Surface, as that's what TTF_RenderText_X returns
//	SDL_Surface *surf = TTF_RenderText_Blended(font, message.c_str(), color);
//	SDL_Texture *texture = SDL_CreateTextureFromSurface(m_render, surf);
//	//Clean up unneeded stuff
//	SDL_FreeSurface(surf);
//	TTF_CloseFont(font);
//
//	return texture;
//}
