
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
			newBlock->setConfig(m_BlockW, m_BlockH, m_Row, m_Col);
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
	return m_BlockVec[rowIndex*m_Col + colIndex];
}

void BlockMgr::addBlock(int rowIndex, int colIndex, BlockType type)
{

}
