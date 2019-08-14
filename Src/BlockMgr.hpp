#ifndef BlockMgr_HPP
#define BlockMgr_HPP

#include "Macros.hpp"




class BlockMgr
{
public:
	BlockMgr();

	void init(int mapW, int mapH, int blockW, int blockH);

	Block* getBlock(int rowIndex, int colIndex);
	void addBlock(int rowIndex, int colIndex, BlockType type);


private:
	int					m_MapW = 0;
	int					m_MapH = 0;
	int					m_BlockW = 0;
	int					m_BlockH = 0;
	int					m_Row = 0;
	int					m_Col = 0;

	vector<Block*>		m_BlockVec;
	Block**				m_BlockList;
};

#endif	//BlockMgr_HPP