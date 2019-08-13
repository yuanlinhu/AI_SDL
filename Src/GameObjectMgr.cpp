
#include "GameObjectMgr.hpp"
#include "Game.hpp"
#include "GameObject.hpp"
#include "Math.hpp"

GameObjectMgr::GameObjectMgr()
{
	
}

GameObjectMgr::~GameObjectMgr()
{
	m_render = nullptr;
}

void GameObjectMgr::setRender(SDL_Renderer* render)
{
	m_render = render;
}

GameObject* GameObjectMgr::createGameObject(int x, int y, int w, int h, string path)
{
	GameObject * gameObj = new GameObject(m_render);
	gameObj->init(x, y, w, h, path);
	m_obj_list.push_back(gameObj);
	return gameObj;
}

void GameObjectMgr::render()
{
	for (auto &tmp : m_obj_list)
	{
		tmp->render(m_render);
	}
}

void GameObjectMgr::update(Uint32 delta)
{
	for (auto &tmp : m_obj_list)
	{
		tmp->update(delta);
	}
}

GameObject* GameObjectMgr::getPlayer()
{
	return getObjectByType(GOT_PLAYER);
}

GameObject* GameObjectMgr::getObjectByType(GameObjectType type)
{
	GameObject* retInfo = nullptr;
	for (auto &tmp : m_obj_list)
	{
		if (tmp->getType() == type)
		{
			retInfo = tmp;
			break;
		}
	}

	return retInfo;
}

void GameObjectMgr::getObjectByCircle(int radius, Point2D& pos, std::vector<GameObject *>& retObjList)
{
	retObjList.clear();
	for (auto &tmp : m_obj_list)
	{
		if (nullptr == tmp)
		{
			continue;
		}
		bool isIn = Math::isInCircle(tmp->getCurPos().x, tmp->getCurPos().y, pos.x, pos.y, radius);
		if (isIn)
		{
			retObjList.push_back(tmp);
		}
	}
}

