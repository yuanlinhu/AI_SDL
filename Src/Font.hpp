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
	string		m_font_path;	//字体路径
	TTF_Font*	m_font;			//
	int			fontSize;		//字体大小
	string		m_message;		//显示内容
	SDL_Color color;			//字体颜色
};

#endif	//Font_HPP