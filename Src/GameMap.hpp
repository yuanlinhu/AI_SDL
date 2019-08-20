#ifndef GameMap_HPP
#define GameMap_HPP

#include "Macros.hpp"

class GameMap
{
public:
	GameMap(Game* parent);

	void createGameObject(int x, int y);

	void init(int mapW, int mapH);

	void update(Uint32 delta);

	void render();

	BlockMgr * getBlockMgr();
private:
	BlockMgr * m_BlockMgr = nullptr;
	Game*		m_parent = nullptr;
};

#endif	//GameMap_HPP