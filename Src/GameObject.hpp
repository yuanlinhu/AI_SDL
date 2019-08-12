
#ifndef Game_Object_hpp
#define Game_Object_hpp

#include "Macros.hpp"

class GameObject
{
public:

	GameObject(SDL_Renderer* render);
	void init(int x, int y, int w, int h, string path);
	~GameObject();

	void render(SDL_Renderer* render);
	void update();


private:
	SDL_Texture *	m_Texture;
	SDL_Rect		m_rect;
	SDL_Renderer*	m_render;
};




#endif	//Game_Object_hpp