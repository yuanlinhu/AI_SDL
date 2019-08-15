#ifndef AStar_HPP
#define AStar_HPP

#include "Macros.hpp"

class AStar
{
public:

	static int calculateG(Block* a, Block* b);
	static int calculateH(Block* a, Block* b);
};

#endif	//AStar_HPP