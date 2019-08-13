#include "Geometry.hpp"



void Geometry::DrawCircle(SDL_Renderer *ren, int radius, int mx, int my)
{
	int st = clock(), tx = 0, ty = radius, d = 3 - (radius << 1), x = mx, y = my;
	while (tx < ty) {
		for (int i = x - ty; i <= x + ty; ++i) {
			SDL_RenderDrawPoint(ren, i, y - tx);
			if (tx)
				SDL_RenderDrawPoint(ren, i, y + tx);
		}
		if (d < 0)
			d += (tx << 2) + 6;
		else {
			for (int i = x - tx; i <= x + tx; ++i) {
				SDL_RenderDrawPoint(ren, i, y - ty);
				SDL_RenderDrawPoint(ren, i, y + ty);
			}
			d += ((tx - ty) << 2) + 10, ty--;
		}
		tx++;
	}
	if (tx == ty)
		for (int i = x - ty; i <= x + ty; ++i) {
			SDL_RenderDrawPoint(ren, i, y - tx);
			SDL_RenderDrawPoint(ren, i, y + tx);
		}
	int en = clock();
}

void Geometry::DrawRect(SDL_Renderer *ren, int x, int y, int w, int h)
{
	SDL_SetRenderDrawColor(ren, 0, 0xFF, 0x00, 0);
	SDL_Rect rect = { x, y, w, h };
	SDL_RenderFillRect(ren, &rect);
}