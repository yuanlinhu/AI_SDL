
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
	for (int j =0; j < m_Col; j++)
	{
		for (int i = 0; i < m_Row; i++)
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

	for (int j = 0; j < m_Col; j++)
	{
		for (int i = 0; i < m_Row; i++)
		{
			int tmpIndex = i + j * m_Row;
			Block * tmpBlock = getBlock(i, j);//m_BlockVec[i*m_Col + j];
			if (tmpBlock->m_RowIndex != i )
			{
				int jj = 0;
				jj++;
				cout << "error m_RowIndex: " << tmpBlock->m_RowIndex << ", i:" << i << endl;
			}
			if (tmpBlock->m_ColIndex != j)
			{
				int jj = 0;
				jj++;
				cout << "error m_ColIndex: " << tmpBlock->m_ColIndex << ", j:" << j << endl;
			}

			if (tmpBlock->m_index != tmpIndex)
			{
				int jj = 0;
				jj++;
				cout << "error m_index: " << tmpBlock->m_index << ", tmpIndex:" << tmpIndex << endl;
			}
		}
	}

	int kk = 0;
	kk++;
}

void BlockMgr::resetSelect()
{
	for (auto& tmp : m_BlockVec)
	{
		tmp->setSelect(0);
	}
}

Block* BlockMgr::getBlock(int rowIndex, int colIndex)
{
	if ((rowIndex < 0) || (rowIndex >= m_Row))
	{
		return nullptr;
	}

	if ((colIndex < 0) || (colIndex >= m_Col))
	{
		return nullptr;
	}

	int index = rowIndex + colIndex * m_Row;

	return m_BlockVec[index];
}

Block* BlockMgr::getBlockByPoint(int x, int y)
{
	int x_index = x / m_BlockW;
	int y_index = y / m_BlockH;

	//x_index = ((x % m_BlockW) > 0) ? x_index + 1 : x_index;
	//y_index = ((y % m_BlockH) > 0) ? y_index + 1 : y_index;

	Block* blk = getBlock(x_index, y_index);

	cout << "x: " << x << ", y:" << y << endl;
	cout << "x_index: " << x_index << ", y_index:" << y_index << endl;
	if (nullptr != blk)
	{
		cout << " blk:" << blk->m_index << endl;
	}
	return getBlock(x_index, y_index);
}

void BlockMgr::get9GridBlockListByPoint(int x, int y, vector<Block*>& outList)
{
	Block* curBlock = getBlockByPoint(x, y);
	get9GridBlockList(curBlock, outList);
}

void BlockMgr::get9GridBlockList(Block* curBlock, vector<Block*>& outList)
{
	if (nullptr == curBlock)
	{
		return;
	}

	outList.clear();
	int curRowIndex = curBlock->m_RowIndex;
	int curColIndex = curBlock->m_ColIndex;
	for (int i = -1; i <= 1; ++i)
	{
		for (int j = -1; j <= 1; ++j)
		{

			Block* tmpBlock = getBlock(curRowIndex + i, curColIndex + j);
			if (nullptr != tmpBlock)
			{
				outList.push_back(tmpBlock);
			}
		}
	}
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
