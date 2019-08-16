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

	void findPath(int x, int y, int target_x, int target_y, list<Block*>& outResultList);


	//OpenList 函数
	void AddToOpenList(Block* block);
	void AddToOpenList(int costF, Block* block);
	void delBlockFromOpenList(Block* block);
	bool isInOpenList(Block* block);

	//获取权重最小的Block， 不负责从openlist里删除，需要调用del函数
	Block* getMinCostBlockFromOpenList();
	Block* getAndDelMinCostBlockFromOpenList();

	bool isInCloseList(Block* block);
	void AddToCloseList(Block* block);

	void sortOpenList();

	Block* randomWalkableBlock();

private:
	map<int /*costF*/, list<Block*> > m_OpenList;
	map<int/*blockIndex*/, Block*>	m_CloseList;

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