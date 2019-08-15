
#include "BlockMgr.hpp"
#include "Block.hpp"


//Block		g_BlockArray[11][15];

BlockMgr::BlockMgr()
{

}

void BlockMgr::init(int mapW, int mapH, int blockW, int blockH)
{
	m_MapW = mapW;
	m_MapH = mapH;
	m_BlockW = blockW;
	m_BlockH = blockH;
	m_Row = mapW / blockW;
	m_Col = mapH / blockH;

	m_Row = ((mapW % blockW) > 0) ? m_Row + 1 : m_Row;
	m_Col = ((mapH % blockH) > 0) ? m_Col + 1 : m_Col;

	//m_BlockList = new Block*[m_Col];
	for (int i = 0; i < m_Row; i++)
	{
		//m_BlockList[i] = new Block();
	}

	//int nsize = sizeof(**m_BlockList);


	int index = 0;
	for (int i =0; i < m_Row; i++)
	{
		for (int j = 0; j < m_Col; j++)
		{
			//Block* newBlock = &(m_BlockList[i][j]);

			Block* newBlock = new Block();
			newBlock->setConfig(mapW, mapH, m_BlockW, m_BlockH, m_Row, m_Col);
			newBlock->init(i, j, index);
			m_BlockVec.push_back(newBlock);
			index++;

			//Block* tmp = &(g_BlockArray[i][j]);
			//tmp->copy(newBlock);
		}
	}

	for (int i = 0; i < m_Row; i++)
	{
		for (int j = 0; j < m_Col; j++)
		{
			int tmpIndex = i * m_Col + j;
			Block * tmpBlock = getBlock(i, j);//m_BlockVec[i*m_Col + j];
			if (tmpBlock->m_RowIndex != i )
			{
				int jj = 0;
				jj++;
			}
			if (tmpBlock->m_ColIndex != j)
			{
				int jj = 0;
				jj++;
			}

			if (tmpBlock->m_index != tmpIndex)
			{
				int jj = 0;
				jj++;
			}
		}
	}

	int kk = 0;
	kk++;
}

Block* BlockMgr::getBlock(int rowIndex, int colIndex)
{
	//if (rowIndex >= m)
	//{

	//}

	int index = rowIndex * m_Col + colIndex;
	if (index < 0 || index > m_BlockVec.size())
	{
		return nullptr;
	}

	return m_BlockVec[rowIndex*m_Col + colIndex];
}

Block* BlockMgr::getBlockByPoint(int x, int y)
{
	int x_index = x / m_BlockW;
	int y_index = y / m_BlockH;

	//x_index = ((x % m_BlockW) > 0) ? x_index + 1 : x_index;
	//y_index = ((y % m_BlockH) > 0) ? y_index + 1 : y_index;

	Block* blk = getBlock(x_index, y_index);

	cout << "x: " << x << ", y:" << y << endl;
	cout << "x_index: " << x_index << ", y_index:" << y_index << ", blk:" << blk->m_index << endl;
	return getBlock(x_index, y_index);
}

void BlockMgr::addBlock(int rowIndex, int colIndex, BlockType type)
{
	Block* tmp = getBlock(rowIndex, colIndex);
	if (nullptr != tmp)
	{
		//tmp->setType(type);
	}
}

void BlockMgr::update(Uint32 delta)
{

}

void BlockMgr::render()
{
	for (auto &tmp : m_BlockVec)
	{
		(tmp)->render();
	}

	//SDL_SetRenderDrawColor(g_render, 255, 255, 50, 0);
	//SDL_Rect  rect;
	//rect.x = 100;
	//rect.y = 100;
	//rect.w = 100;
	//rect.h = 100;
	//SDL_RenderFillRect(g_render, &rect);
}
