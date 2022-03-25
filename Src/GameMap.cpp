
#include "GameMap.hpp"
#include "BlockMgr.hpp"
#include "GameObjectMgr.hpp"
#include "GameObject.hpp"
#include "Game.hpp"

GameMap::GameMap(Game* parent)
{
	m_BlockMgr = new BlockMgr();
	m_parent = parent;
}
void GameMap::createGameObject(int x, int y)
{
	auto enemy = m_parent->getGameObjMgr()->createGameObject(x, y, 5, 5, "F:\\study\\AI_SDL\\Asset/1.png");
	enemy->setType(GOT_ENEMY);
	enemy->createAI();
}


void GameMap::init(int mapW, int mapH)
{
	m_BlockMgr->init(MAP_WIDTH, MAP_HEIGHT, BLOCK_WIDTH, BLOCK_HEIGHT);
	//m_BlockMgr->addBlock(2, 3, BLT_ROCK);
	//m_BlockMgr->addBlock(3, 5, BLT_ROCK);
	//m_BlockMgr->addBlock(6, 7, BLT_ROCK);

}

void GameMap::update(Uint32 delta)
{
	m_BlockMgr->update(delta);
}

void GameMap::render()
{
	m_BlockMgr->render();
}


BlockMgr* GameMap::getBlockMgr()
{ 
	return m_BlockMgr;
}