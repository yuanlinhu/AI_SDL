
#include "GameObject.hpp"
#include "Game.hpp"

GameObject::GameObject(SDL_Renderer* render)
{
	m_render = render;
}

void GameObject::init(int x, int y, int w, int h, string path)
{

	m_rect.x = x;
	m_rect.y = y;
	m_rect.w = w;
	m_rect.h = h;

	SDL_Surface * tmp_surface = IMG_Load(path.c_str());
	if (!tmp_surface) {
		printf("IMG_Load: %s\n", IMG_GetError());
		// handle error
	}

	m_Texture = SDL_CreateTextureFromSurface(m_render, tmp_surface);
	m_origin_w = tmp_surface->w;
	m_origin_h = tmp_surface->h;
	m_type = GOT_ENEMY;


	{
		m_nameFont = new Font(m_render);
		SDL_Color textColor = { 0, 0, 255 };
		m_nameFont->init("LATINWD.TTF", textColor, 20);
	}
	

	{
		m_hpFont = new Font(m_render);
		SDL_Color textColor = { 255, 0, 0 };
		m_hpFont->init("LATINWD.TTF", textColor, 10);
	}
	


	m_hp = 10000;
	m_name = "pika";
}

GameObject::~GameObject()
{

}


void GameObject::render(SDL_Renderer* render)
{
	m_rect.x = m_cur_pos.x;
	m_rect.y = m_cur_pos.y;
	SDL_RenderCopy(m_render, m_Texture, NULL, &m_rect);

	m_nameFont->render();

	m_hpFont->render();
}

void GameObject::update(Uint32 delta)
{
	if (m_cur_pos == m_target_pos)
	{
		//设置随机目标点
		m_target_pos.x = rand() % (WINDOW_WIDTH - m_rect.w);
		m_target_pos.y = rand() % (WINDOW_HEIGHT - m_rect.h);

		cout << "目标为 " << m_target_pos.x << ", " << m_target_pos.y << endl;
	}

	int x_mul = (m_target_pos.x > m_cur_pos.x) ? 1 : -1;
	int y_mul = (m_target_pos.y > m_cur_pos.y) ? 1 : -1;

	x_mul = (m_target_pos.x == m_cur_pos.x) ? 0 : x_mul;
	y_mul = (m_target_pos.y == m_cur_pos.y) ? 0 : y_mul;

	m_cur_pos.x += (x_mul * m_speed * delta) / 1000;
	m_cur_pos.y += (y_mul * m_speed * delta) / 1000;

	stringstream strss;
	strss << m_name << "  hp:" << m_hp;
	m_nameFont->setMessage(strss.str(), m_cur_pos.x + 5, m_cur_pos.y - 20, 70, 20);

	m_hpFont->setPos(m_cur_pos.x + 5, m_cur_pos.y - 30);
}



void GameObject::add_x(int n)
{
	m_rect.x += n;
	if (m_rect.x < 0)
	{
		m_rect.x = 0;
	}

	if (m_rect.x > WINDOW_WIDTH - m_rect.w)
	{
		m_rect.x = WINDOW_WIDTH - m_rect.w;
	}
}

void GameObject::add_y(int n)
{
	m_rect.y += n;
	if (m_rect.y < 0)
	{
		m_rect.y = 0;
	}

	if (m_rect.y > WINDOW_HEIGHT - m_rect.h)
	{
		m_rect.y = WINDOW_HEIGHT - m_rect.h;
	}
}

void GameObject::setType(GameObjectType type)
{
	m_type = type;
}

GameObjectType GameObject::getType()
{
	return m_type;
}

void GameObject::addHP(int hp)
{
	m_hp += hp;

	stringstream strss;
	strss << hp;
	m_hpFont->setMessage(strss.str(), m_cur_pos.x + 5, m_cur_pos.y + 30, 10, 10);
	m_hpFont->setTimer(2);
}