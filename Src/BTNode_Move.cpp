

#include "BTNode_Move.hpp"
#include "GameObject.hpp"

BTNode_Move::BTNode_Move(GameObject* objParent)
	: BTNode(BTNT_LEAF, objParent)
{

}

bool BTNode_Move::check()
{
	GameObject* obj = getObjParent();
	if (nullptr == obj)
	{
		return false;
	}

	if (obj->getCurPos() == obj->GetTargetPos())
	{
		return false;
	}

	return true;
}
bool BTNode_Move::run(int delta)
{
	GameObject* obj = getObjParent();
	if (nullptr == obj)
	{
		return false;
	}
	Vector2D& curPos = obj->getCurPos();
	Vector2D& targetPos = obj->getTargetPos();

	int x_mul = (targetPos.x > curPos.x) ? 1 : -1;
	int y_mul = (targetPos.y > curPos.y) ? 1 : -1;

	x_mul = (targetPos.x == curPos.x) ? 0 : x_mul;
	y_mul = (targetPos.y == curPos.y) ? 0 : y_mul;

	float speed = obj->getSpeed();
	int xSept = (x_mul * speed * delta) / 1000;
	int ySept = (y_mul * speed * delta) / 1000;


	int newPosX = curPos.x += xSept;
	int newPosY = curPos.y += ySept;

	obj->setCurPos(newPosX, newPosY);
}