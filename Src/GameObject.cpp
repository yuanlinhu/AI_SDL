
#include "GameObject.hpp"
#include "Game.hpp"

GameObject::GameObject(SDL_Renderer* render)
{
	m_render = render;
}

void GameObject::init(int x, int y, int w, int h, string path)
{

	m_rect.x = x;
	m_rect.y = y;
	m_rect.w = w;
	m_rect.h = h;

	SDL_Surface * tmp_surface = IMG_Load("../Asset/grass.jpg");
	if (!tmp_surface) {
		printf("IMG_Load: %s\n", IMG_GetError());
		// handle error
	}

	m_Texture = SDL_CreateTextureFromSurface(m_render, tmp_surface);
}

GameObject::~GameObject()
{

}


void GameObject::render(SDL_Renderer* render)
{
	SDL_RenderCopy(m_render, m_Texture, NULL, &m_rect);
}

void GameObject::update()
{
	m_rect.x += 1;
	m_rect.y += 1;
}