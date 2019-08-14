#ifndef GameMap_HPP
#define GameMap_HPP

#include "Macros.hpp"

class GameMap
{
public:
	GameMap();

	void init(int mapW, int mapH);


private:
	BlockMgr * m_BlockMgr;
};

#endif	//GameMap_HPP