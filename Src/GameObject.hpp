
#ifndef Game_Object_hpp
#define Game_Object_hpp

#include "Macros.hpp"
#include "Font.hpp"


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

	Point2D& getCurPos() 
	{
		return m_cur_pos;
	}

	void SetTargetPos(int x, int y);

private:
	void SetRandomTargetPos();
	void GetTargetPos(int& x, int& y);



private:
	SDL_Texture *	m_Texture;
	SDL_Rect		m_rect;
	SDL_Renderer*	m_render;

	Font* m_nameFont;
	Font* m_hpFont;

	//ͼƬԭʼ�ߴ�
	int				m_origin_w;
	int				m_origin_h;

	GameObjectType	m_type;

	Point2D		m_cur_pos;
	Point2D		m_target_pos;
	float m_speed = 100.0f;

	string			m_name;
	int				m_hp;
	list<Block*>		m_target_pos_list;

	AI*				m_AI = nullptr;
};




#endif	//Game_Object_hpp