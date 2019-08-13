
#include "TriggerMgr.hpp"
#include "Trigger.hpp"


TriggerMgr::TriggerMgr(SDL_Renderer* render)
{
	m_render = render;
}

void TriggerMgr::createTrigger(TriggerType type, int x, int y)
{
	Trigger* newTrigger = new Trigger();
	newTrigger->init(type, x, y);
	m_triggerList.push_back(newTrigger);
}

void TriggerMgr::update(Game* game)
{
	for (auto &tmp : m_triggerList)
	{
		tmp->update(game);
	}
}

void TriggerMgr::render()
{
	for (auto &tmp : m_triggerList)
	{
		tmp->render(m_render);
	}
}

