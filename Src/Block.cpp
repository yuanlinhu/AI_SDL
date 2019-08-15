#include "Block.hpp"

//16 * 12
int blockBitMap[][20] =
{
{ 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 },
{ 0,0,1,0,0, 0,0,1,0,0, 0,0,0,0,0, 0,0,0,0,0 },
{ 0,0,1,0,1, 0,0,1,0,0, 0,0,0,0,0, 0,0,0,0,0 },
{ 0,0,1,0,1, 0,0,1,0,0, 0,0,0,0,0, 0,0,0,0,0 },
{ 0,0,1,0,1, 0,0,1,0,0, 0,0,0,0,0, 1,0,0,0,0 },
{ 0,0,1,0,0, 0,0,0,0,0, 0,0,0,0,0, 1,0,0,0,0 },
{ 0,0,1,0,0, 0,0,0,0,0, 0,0,0,0,0, 1,0,0,0,0 },
{ 0,0,1,0,0, 0,1,1,1,1, 0,0,0,0,0, 1,0,0,0,0 },
{ 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 },
{ 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 2,0,0,0,0 },
{ 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 2,0,0,0,0 },
{ 0,0,0,0,0, 0,0,0,0,0, 0,0,0,2,2, 2,0,0,0,0 },
{ 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 },
{ 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 },
{ 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 },
{ 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 },
{ 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 },
{ 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 },
};

Block::Block()
{

}

void Block::setConfig(int mapW, int mapH, int blockW, int blockH, int rowIndexMax, int colIndexMax)
{
	m_MapW = mapW;
	m_MapH = mapH;

	m_BlockW = blockW;
	m_BlockH = blockH;

	m_RowIndexMax = rowIndexMax;
	m_ColIndexMax = colIndexMax;
}

void Block::init(int rowIndex, int colIndex, int index)
{
	m_RowIndex	= rowIndex;
	m_ColIndex	= colIndex;
	m_index		= index;

	m_minX = m_RowIndex * m_BlockW;
	m_maxX = m_minX + m_BlockW;

	if (m_maxX > m_MapW)
	{
		m_maxX = m_MapW;
	}


	m_minY = m_ColIndex * m_BlockH;
	m_maxY = m_minY + m_BlockH;

	if (m_maxY > m_MapH)
	{
		m_maxY = m_MapH;
	}

	//…Ë÷√’œ∞≠ŒÔ
	m_type = (BlockType)blockBitMap[colIndex][rowIndex];
}

void Block::renderFrame()
{
	SDL_SetRenderDrawColor(g_render, 0, 100, 0, 0);
	SDL_RenderDrawLine(g_render, m_minX, m_minY, m_minX, m_maxY);
	SDL_RenderDrawLine(g_render, m_minX, m_minY, m_maxX, m_minY);
	SDL_RenderDrawLine(g_render, m_maxX, m_maxY, m_maxX, m_minY);
	SDL_RenderDrawLine(g_render, m_maxX, m_maxY, m_minX, m_maxY);
}

void Block::renderBlock()
{
	//◊Ëµ≤µ„
	if (BLT_NULL != m_type)
	{
		int n = 5;
		SDL_SetRenderDrawColor(g_render, 100 * m_type, 200, 200 - 50 * m_type, 0);
		SDL_Rect  rect;
		rect.x = m_minX + n;
		rect.y = m_minY + n;
		rect.w = m_maxX - m_minX - 10;
		rect.h = m_maxY - m_minY - 10;
		SDL_RenderFillRect(g_render, &rect);
	}
}

void Block::renderSelect()
{
	//◊Ëµ≤µ„
	if (0 != m_select)
	{
		int n = 5;
		SDL_SetRenderDrawColor(g_render, 100, 200, 0, 0);
		SDL_Rect  rect;
		rect.x = m_minX + n;
		rect.y = m_minY + n;
		rect.w = m_maxX - m_minX - 10;
		rect.h = m_maxY - m_minY - 10;
		SDL_RenderFillRect(g_render, &rect);
	}
}


void Block::render()
{
	renderFrame();
	renderBlock();
	renderSelect();
}