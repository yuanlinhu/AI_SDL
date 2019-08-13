#ifndef Font_HPP
#define Font_HPP

#include "Macros.hpp"

class Font
{
public:
	Font(SDL_Renderer* render);
	void init(std::string fontFile, SDL_Color& color, int fontSize);
	void setMessage(std::string message);
	void setMessage(std::string message, int x, int y, int w, int h);

	void setPos(int x, int y);
	void update(Uint32 delta);
	void render();

	void setTimer(int second);
	void addWidth(int w);
	void addFontSize(int s);

	//void render(std::string message, int x, int y, int w, int h, std::string fontFile,
	//	SDL_Color color, int fontSize);

public:
	string			m_font_path;	//����·��
	TTF_Font*		m_font;			//
	int				m_fontSize;		//�����С
	string			m_message;		//��ʾ����
	SDL_Texture*	m_fontTexture;
	SDL_Color		m_color;			//������ɫ
	SDL_Rect		m_rect;
	SDL_Renderer*	m_render;

	int				m_dispearTicks;
};

#endif	//Font_HPP