
#include "AI.hpp"
#include "BTNode.hpp"
#include "BTNode_Sequence.hpp"

AI::AI(AI_Type type, GameObject* objParent)
{
	m_objParent = objParent;
	m_Type = type;

	m_rootNode = new BTNode_Sequence(objParent);
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

void AI::addNodeToRoot(BTNode* node)
{
	m_rootNode->addChild(node);
}
