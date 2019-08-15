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
	void resetCostG();

	void get9GridBlockListByPoint(int x, int y, vector<Block*>& outList);
	void get9GridBlockList(Block* curBlock, vector<Block*>& outList);

	void update(Uint32 delta);

	void render();

	void findPath(int x, int y, int target_x, int target_y);


	//OpenList º¯Êý
	void AddToOpenList(int costF, Block* block);
	void delBlockFromOpenList(Block* block);
	bool isInOpenList(Block* block);
	Block* getMinCostBlockFromOpenList();

	bool isInCloseList(Block* block);
	void AddToCloseList(int costF, Block* block);


private:
	map<int /*costF*/, list<Block*> > m_OpenList;
	map<int/*blockIndex*/, Block*>	m_ClostList;

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