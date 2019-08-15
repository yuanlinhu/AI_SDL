#include "AStar.hpp"
#include "Block.hpp"

static int ArrayCostG[3][3] =
{
	{ 14, 10, 14},
	{ 10, 0, 10 },
	{ 14, 10, 14 },
};

int AStar::calculateG(Block* a, Block* b)
{
	if (nullptr == a || nullptr == b)
	{
		return -1;
	}

	int deltaRow = (a->m_RowIndex - b->m_RowIndex) + 1;
	int deltaCol = (a->m_ColIndex - b->m_ColIndex) + 1;

	return ArrayCostG[deltaRow][deltaCol];
}

int AStar::calculateH(Block* a, Block* b)
{
	if (nullptr == a || nullptr == b)
	{
		return -1;
	}

	int deltaRow = (a->m_RowIndex - b->m_RowIndex);
	int deltaCol = (a->m_ColIndex - b->m_ColIndex);

	return 10 * (abs(deltaRow) + abs(deltaCol));
}


