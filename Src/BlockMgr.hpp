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

	Block* getBlockByPoint(int x, int y);

	void resetSelect();

	void get9GridBlockListByPoint(int x, int y, vector<Block*>& outList);
	void get9GridBlockList(Block* curBlock, vector<Block*>& outList);

	void update(Uint32 delta);

	void render();

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