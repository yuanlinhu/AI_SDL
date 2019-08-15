#ifndef GameMap_HPP
#define GameMap_HPP

#include "Macros.hpp"

class GameMap
{
public:
	GameMap();

	void init(int mapW, int mapH);

	void update(Uint32 delta);

	void render();

	BlockMgr * getBlockMgr();
private:
	BlockMgr * m_BlockMgr;
};

#endif	//GameMap_HPP