#ifndef TriggerMgr_HPP
#define TriggerMgr_HPP

#include "Macros.hpp"

class Trigger;
enum TriggerType;
class Game;

class TriggerMgr
{
public:
	TriggerMgr(SDL_Renderer* render);

	void createTrigger(TriggerType type, int x, int y);

	void update(Game* game);

	void render();

private:
	//TriggerMgr() = default;

private:
	list<Trigger*>		m_triggerList;
	SDL_Renderer*		m_render;
};

#endif	//TriggerMgr_HPP