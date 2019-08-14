#ifndef Block_HPP
#define Block_HPP

#include "Macros.hpp"

//障碍点最小单位


class Block
{
public:
	Block();

	void setConfig(int mapW, int mapH, int blockW, int blockH, int rowIndexMax, int colIndexMax);

	void init(int rowIndex, int colIndex, int index);


	void render();

	//void copy(Block* b);

	void setType(BlockType type) { m_type = type; }

//private:

	BlockType m_type;

	int		m_MapW = 0;
	int		m_MapH = 0;
	int		m_BlockW = 0;
	int		m_BlockH = 0;
	
	int		m_RowIndexMax = 0;
	int		m_ColIndexMax = 0;
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