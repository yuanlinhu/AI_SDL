#ifndef Block_HPP
#define Block_HPP

#include "Macros.hpp"

//障碍点最小单位


class Block
{
public:
	Block();

	void setConfig(int blockW, int blockH, int row, int col);

	void init(int rowIndex, int colIndex, int index);


	void copy(Block* b);

//private:



	int		m_BlockW = 0;
	int		m_BlockH = 0;
	int		m_Row = 0;
	int		m_Col = 0;
	int		m_RowIndex = 0;
	int		m_ColIndex = 0;
	int		m_index = 0;			//总索引

	//计算出对应的坐标
	int		m_minX = 0;
	int		m_maxX = 0;
	int		m_minY = 0;
	int		m_maxY = 0;
};

#endif	//Block_HPP