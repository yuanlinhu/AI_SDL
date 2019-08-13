
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
	newTrigger->setMaxIndex(10);
	newTrigger->setTimer(500);
	//newTrigger->startTimer();
	m_triggerList.push_back(newTrigger);
}

void TriggerMgr::update(Game* game)
{
	for (auto &tmp : m_triggerList)
	{
		tmp->update(game);
	}

	for (list<Trigger *>::iterator iter = m_triggerList.begin(); iter != m_triggerList.end(); ++iter)
	{
		if ((*iter)->canErase())
		{
			m_triggerList.erase(iter);
			break;
		}
	}
}

void TriggerMgr::render()
{
	for (auto &tmp : m_triggerList)
	{
		tmp->render(m_render);
	}
}

