#ifndef Font_HPP
#define Font_HPP

#include "Macros.hpp"

class Font
{
public:
	Font();
	void init(std::string message, std::string fontFile,
		SDL_Color color, int fontSize);

	void render();

public:
	string		m_font_path;	//����·��
	TTF_Font*	m_font;			//
	int			fontSize;		//�����С
	string		m_message;		//��ʾ����
	SDL_Color color;			//������ɫ
};

#endif	//Font_HPP