
#include "GameObjectMgr.hpp"
#include "Game.hpp"
#include "GameObject.hpp"


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

void GameObjectMgr::update()
{
	for (auto &tmp : m_obj_list)
	{
		tmp->update();
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

