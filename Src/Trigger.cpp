#include "Trigger.hpp"
#include "Geometry.hpp"
#include "Game.hpp"
#include "GameObject.hpp"
#include "Math.hpp"

Trigger::Trigger()
{
	m_Type = TRT_NULL;
}

void Trigger::init(TriggerType type, int x, int y)
{
	m_Type = type;
	m_birthPos.x = x;
	m_birthPos.y = y;

	m_Radius = 50;
}

bool Trigger::canErase()
{
	if (m_curIndex > m_maxIndex)
	{
		return true;
	}
	return false;
}

void Trigger::update(Game* game)
{
	if (nullptr == game)
	{
		return;
	}

	if (false == m_Timer.isExpire())
	{
		return;
	}

	std::vector<GameObject *> retObjList;
	game->getObjectByCircle(m_Radius, game->getMousePos(), retObjList);

	for (auto &tmp : retObjList)
	{
		int randHp = Math::getRand(100, 200);
		tmp->addHP(-randHp);
	}

	m_curIndex++;
	m_Timer.restart();
}

void Trigger::render(SDL_Renderer* render)
{
	SDL_SetRenderDrawColor(render, 255 - m_curIndex * 20, 255, 50, 0);
	Geometry::DrawCircle(render, m_Radius, m_birthPos.x, m_birthPos.y);
}

