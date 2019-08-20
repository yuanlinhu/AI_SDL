
#ifndef Game_Object_Mgr_hpp
#define Game_Object_Mgr_hpp

#include "Macros.hpp"

class GameObject;

class GameObjectMgr
{
public:


	GameObjectMgr();
	~GameObjectMgr();

public:
	GameObject* createGameObject(int x, int y, int w, int h, string path);
	GameObject* getPlayer();
	GameObject* getObjectByType(GameObjectType type);


	void getObjectByCircle(int radius, Point2D& pos, std::vector<GameObject *>& retObjList);

	std::vector<GameObject*> get_obj_list() { return m_obj_list; }
public:
	void setRender(SDL_Renderer* render);
	void render();
	void update(Uint32 delta);

	

public:
	//static GameObjectMgr *m_pInstance;
	//static GameObjectMgr * inst()
	//{
	//	if (m_pInstance == NULL)  //判断是否第一次调用
	//		m_pInstance = new GameObjectMgr();
	//	return m_pInstance;
	//}

private:
	std::vector<GameObject*>			m_obj_list;
	SDL_Renderer* m_render;
};




#endif	//Game_Object_Mgr_hpp