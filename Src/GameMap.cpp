
#include "GameMap.hpp"
#include "BlockMgr.hpp"

GameMap::GameMap()
{
	m_BlockMgr = new BlockMgr();
}

void GameMap::init(int mapW, int mapH)
{
	m_BlockMgr->init(500, 600, 50, 50);
}
