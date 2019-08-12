
#ifndef Game_Object_Mgr_hpp
#define Game_Object_Mgr_hpp

#include "Macros.hpp"

class GameObject;

class GameObjectMgr
{
public:


	GameObjectMgr();
	~GameObjectMgr();

	void setRender(SDL_Renderer* render);

	void createGameObject(int x, int y, int w, int h, string path);

	void render();
	void update();

public:
	//static GameObjectMgr *m_pInstance;
	//static GameObjectMgr * inst()
	//{
	//	if (m_pInstance == NULL)  //�ж��Ƿ��һ�ε���
	//		m_pInstance = new GameObjectMgr();
	//	return m_pInstance;
	//}

private:
	std::vector<GameObject*>			m_obj_list;
	SDL_Renderer* m_render;
};




#endif	//Game_Object_Mgr_hpp