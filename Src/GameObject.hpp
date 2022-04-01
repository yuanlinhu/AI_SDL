
#ifndef Game_Object_hpp
#define Game_Object_hpp

#include "Macros.hpp"
#include "Font.hpp"
#include "Math/Vector2D.h"

class StateMachine;

class GameObject
{
public:

	GameObject(SDL_Renderer* render);
	void init(int x, int y, int w, int h, string path);
	~GameObject();

	void render(SDL_Renderer* render);
	void update(Uint32 delta);

	void add_x(int n);
	void add_y(int n);

	void addHP(int hp);

	void setType(GameObjectType type);
	void createAI();
	GameObjectType getType();

	Vector2D& getCurPos()
	{
		return m_cur_pos;
	}
	Vector2D& GetTargetPos()
	{
		return m_target_pos;
	}


	Vector2D& getVel0city()
	{
		return m_vVelocity;
	}
	

	void setCurPos(int x, int y)
	{
		m_cur_pos.x = x;
		m_cur_pos.y = y;
	}

	Vector2D& getTargetPos()
	{
		return m_target_pos;
	}

	void SetTargetPos(int x, int y);

	float getSpeed() { return m_speed; }

	void set_visible(bool vis) { m_visible = vis; }


	StateMachine*  GetStateMachine() { return m_StateMachine; }
private:
	void SetRandomTargetPos();
	void GetNextTargetPos(int& x, int& y);



private:
	SDL_Texture *	m_Texture;
	SDL_Rect		m_rect;
	SDL_Renderer*	m_render;

	Font* m_nameFont;
	Font* m_hpFont;

	//图片原始尺寸
	int				m_origin_w;
	int				m_origin_h;

	GameObjectType	m_type;

	

	string			m_name;
	int				m_hp;
	list<Block*>		m_target_pos_list;

	//AI*				m_AI = nullptr;

	StateMachine* m_StateMachine = nullptr;

	bool m_visible = true;


	Vector2D		m_cur_pos;
	Vector2D		m_target_pos;
	float m_speed = 100.0f;			//速率

	Vector2D		m_Force;		//力量
	Vector2D		m_vVelocity;		//速度
	double		m_MaxForce;			//力
	double		m_Mass = 1500.0;				//
};




#endif	//Game_Object_hpp