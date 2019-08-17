
#include "BTNode_Sequence.hpp"


BTNode_Sequence::BTNode_Sequence(GameObject* objParent)
	:BTNode(BTNT_SEQUENCE, objParent)
{
}
bool BTNode_Sequence::check()
{
	list<BTNode *>& nodeList = getChildNodeList();
	for (auto& tmp : nodeList)
	{
		if (false == tmp->check())
		{
			return false;
		}
	}

	return true;
}

bool BTNode_Sequence::run(int delta)
{
	list<BTNode *>& nodeList = getChildNodeList();
	for (auto& tmp : nodeList)
	{
		if (false == tmp->run(delta))
		{
			return false;
		}
	}

	return true;
}