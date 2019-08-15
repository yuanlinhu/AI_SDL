#include "Block.hpp"
#include "Font.hpp"
#include "AStar.hpp"

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

	//ÉèÖÃÕÏ°­Îï
	m_type = (BlockType)blockBitMap[colIndex][rowIndex];


	{
		m_costGFont = new Font(g_render);
		SDL_Color textColor = { 0, 0, 0 };
		m_costGFont->init("LATINWD.TTF", textColor, 10);
	}
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
	//×èµ²µã
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
	//×èµ²µã
	if (0 != m_select)
	{
		int n = 5;
		if (1 == m_select)
		{
			SDL_SetRenderDrawColor(g_render, 220, 100, 0, 0);
		}
		else
		{
			SDL_SetRenderDrawColor(g_render, 100, 0, 100, 0);
		}

		SDL_Rect  rect;
		rect.w = (m_maxX - m_minX) / 3;
		rect.h = (m_maxY - m_minY) / 3;
		rect.x = m_minX + rect.w;
		rect.y = m_minY + rect.h;
		
		SDL_RenderFillRect(g_render, &rect);


		
		
	}
}


void Block::render()
{
	renderFrame();
	renderBlock();
	renderSelect();
	renderCostH();
}

void Block::renderCostH()
{
	int n = 10;
	SDL_SetRenderDrawColor(g_render, 220, 0, 220, 0);
	SDL_Rect  rect;
	rect.x = m_minX + n;
	rect.y = m_maxY - n;
	rect.w = (m_maxX - m_minX) / 5;
	rect.h = (m_maxY - m_minY) / 5;
	stringstream strss;
	strss << m_costG;
	m_costGFont->setMessage(strss.str(), rect.x, rect.y, rect.w, rect.h);
	m_costGFont->render();
}

int Block::getCostF()
{
	return m_costG + m_costH;
}

bool Block::isObtacle()
{
	if (BLT_NULL != m_type)
	{
		return true;
	}
	return false;
}

void Block::setParent(Block* parent)
{ 
	m_parent = parent; 
}

Block* Block::getParent()
{ 
	return m_parent; 
}

void Block::calculateG(Block* curBlock)
{
	int costG = AStar::calculateG(this, curBlock);
	setCostG(costG);
}

void Block::calculateH(Block* tarBlock)
{
	m_costH = AStar::calculateH(this, tarBlock);
}

int Block::getCostG()
{
	return m_costG;
}

void Block::setCostG(int val)
{
	m_costG = val;
}