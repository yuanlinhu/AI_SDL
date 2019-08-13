#include "Font.hpp"


Font::Font()
{

}

void Font::init(std::string message, std::string fontFile,
	SDL_Color color, int fontSize)
{
	TTF_Font *font = nullptr;
	string absolute_path = "../Asset/ttf/" + fontFile;
	font = TTF_OpenFont(absolute_path.c_str(), fontSize);
	if (font == nullptr)
	{
		cout << "Failed to load font: " << fontFile << TTF_GetError() << endl;
	}

	//Render the message to an SDL_Surface, as that's what TTF_RenderText_X returns
	SDL_Surface *surf = TTF_RenderText_Blended(font, message.c_str(), color);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(m_render, surf);
	//Clean up unneeded stuff
	SDL_FreeSurface(surf);
	TTF_CloseFont(font);

	return texture;
}

void Font::render()
{

}
