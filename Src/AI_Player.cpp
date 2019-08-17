
#include "AI_Player.hpp"
#include "BTNode.hpp"
#include "BTNode_Sequence.hpp"
#include "BTNode_Move.hpp"

AI_Player::AI_Player(GameObject* objParent)
	:AI(AIT_PLAYER, objParent)
{

}

void AI_Player::init()
{
	BTNode* subSequenceNode = new BTNode_Sequence(getObjParent());
	getRootNode()->addChild(subSequenceNode);

	BTNode* leafMove = new BTNode_Move(getObjParent());

	subSequenceNode->addChild(leafMove);
}

void AI_Player::update(Uint32 delta)
{
	if (getRootNode()->check())
	{
		getRootNode()->run(delta);
	}
}
