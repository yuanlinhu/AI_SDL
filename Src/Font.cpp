#include "Font.hpp"


Font::Font(SDL_Renderer* render)
{
	m_render = render;
}



void Font::init(std::string fontFile, SDL_Color& color, int fontSize)
{
	string absolute_path = "../Asset/ttf/" + fontFile;
	m_font = TTF_OpenFont(absolute_path.c_str(), fontSize);
	if (m_font == nullptr)
	{
		cout << "Failed to load font: " << fontFile << TTF_GetError() << endl;
	}

	m_color = color;
	m_fontSize = fontSize;

	
}

void Font::setMessage(std::string message)
{
	//Render the message to an SDL_Surface, as that's what TTF_RenderText_X returns
	SDL_Surface *surf = TTF_RenderText_Blended(m_font, message.c_str(), m_color);
	m_fontTexture = SDL_CreateTextureFromSurface(m_render, surf);
	//Clean up unneeded stuff
	//SDL_FreeSurface(surf);
	//TTF_CloseFont(m_font);
}

void Font::setMessage(std::string message, int x, int y, int w, int h)
{
	setMessage(message);
	m_rect.x = x;
	m_rect.y = y;
	m_rect.w = w;
	m_rect.h = h;
}

void Font::setPos(int x, int y)
{
	m_rect.x = x;
	m_rect.y = y;
}

void Font::render()
{
	SDL_SetRenderDrawColor(m_render, 0, 0, 255, 0);

	if (m_dispearTicks > 0)
	{
		int nowTicks = SDL_GetTicks();
		cout << nowTicks - m_dispearTicks<< endl;
		if (nowTicks >= m_dispearTicks)
		{
			//cout << "×ÖÌåÏûÊ§" << endl;
			m_fontTexture = nullptr;
			m_dispearTicks = 0;
		}
	}
	if (nullptr != m_fontTexture)
	{
		SDL_RenderCopy(m_render, m_fontTexture, NULL, &m_rect);
	}
}

void Font::update(Uint32 delta)
{

}

void Font::setTimer(int second)
{
	m_dispearTicks = SDL_GetTicks() + second * 1000;
}

//void Font::addWidth(int w)
//{
//	m_rect.w += w;
//}
//
//void Font::addFontSize(int s)
//{
//	m_fontSize += s;
//}
//void Font::render(std::string message, int x, int y, int w, int h, std::string fontFile,
//	SDL_Color color, int fontSize)
//{
//	//
//	m_rect.x = x;
//	m_rect.y = y;
//	m_rect.w = w;
//	m_rect.h = h;
//	SDL_RenderCopy(m_render, texture, NULL, &m_rect);
//}
//
//void Font::changeMessage(std::string message, int x, int y, int w, int h, std::string fontFile,
//	SDL_Color color, int fontSize)
//{
//	Open the font
//	TTF_Font *font = nullptr;
//	string absolute_path = "../Asset/ttf/" + fontFile;
//	font = TTF_OpenFont(absolute_path.c_str(), fontSize);
//	if (font == nullptr)
//	{
//		cout << "Failed to load font: " << fontFile << TTF_GetError() << endl;
//	}
//
//	Render the message to an SDL_Surface, as that's what TTF_RenderText_X returns
//	SDL_Surface *surf = TTF_RenderText_Blended(font, message.c_str(), color);
//	SDL_Texture *texture = SDL_CreateTextureFromSurface(m_render, surf);
//	Clean up unneeded stuff
//	SDL_FreeSurface(surf);
//	TTF_CloseFont(font);
//}