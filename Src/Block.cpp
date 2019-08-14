#include "Block.hpp"

Block::Block()
{

}

void Block::setConfig(int blockW, int blockH, int row, int col)
{
	m_BlockW = blockW;
	m_BlockH = blockH;

	m_Row = row;
	m_Col = col;
}

void Block::init(int rowIndex, int colIndex, int index)
{
	m_RowIndex	= rowIndex;
	m_ColIndex	= colIndex;
	m_index		= index;
}

void Block::copy(Block* b)
{
	m_BlockW = b->m_BlockW;
	m_BlockH = b->m_BlockW;

	m_Row = b->m_Row;
	m_Col = b->m_Col;

	m_RowIndex = b->m_RowIndex;
	m_ColIndex = b->m_ColIndex;
	m_index = b->m_index;
}
