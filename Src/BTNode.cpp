#include "BTNode.hpp"


BTNode::BTNode(BTNodeType type)
{
	m_type = type;
}

void BTNode::addChild(BTNode* node)
{
	if (nullptr == node)
	{
		return;
	}
	m_childNode.push_back(node);
}

bool BTNode::check()
{
	return true;
}

bool BTNode::run()
{
	return true;
}
