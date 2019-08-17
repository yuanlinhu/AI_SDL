#include "BTNode.hpp"


BTNode::BTNode(BTNodeType type, GameObject* objParent)
{
	m_type = type;
	m_objParent = objParent;
}

void BTNode::addChild(BTNode* node)
{
	if (nullptr == node)
	{
		return;
	}
	m_childNode.push_back(node);
}

list<BTNode*>& BTNode::getChildNodeList()
{
	return m_childNode;
}

GameObject* BTNode::getObjParent()
{
	return m_objParent;
}