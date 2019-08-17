
#include "AI.hpp"

AI::AI(AI_Type type, GameObject* objParent)
{
	m_objParent = objParent;
	m_Type = type;
}

void AI::setCurPos(int x, int y)
{
	m_cur_pos.x = x;
	m_cur_pos.y = y;
}


void AI::setTargetPos(int x, int y)
{
	m_target_pos.x = x;
	m_target_pos.y = y;
}

