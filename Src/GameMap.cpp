
#include "GameMap.hpp"
#include "BlockMgr.hpp"

GameMap::GameMap()
{
	m_BlockMgr = new BlockMgr();
}

void GameMap::init(int mapW, int mapH)
{
	m_BlockMgr->init(800, 600, 50, 50);
	m_BlockMgr->addBlock(2, 3, BLT_ROCK);
	m_BlockMgr->addBlock(3, 5, BLT_ROCK);
	m_BlockMgr->addBlock(6, 7, BLT_ROCK);

}

void GameMap::update(Uint32 delta)
{

}

void GameMap::render()
{
	m_BlockMgr->render();
}
