#include "StateMove.h"
#include "../GameObject.hpp"
#include "Telegram.h"
#include "MessageDispatcher.h"


StateMove* StateMove::Instance()
{
	static StateMove ins;
	return &ins;
}

void StateMove::Enter(GameObject* obj)
{

}

void StateMove::update(GameObject* obj, int delta)
{
#if 1
	Vector2D& curPos = obj->getCurPos();
	Vector2D& targetPos = obj->getTargetPos();
	if (curPos == targetPos)
	{
		return;
	}

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
#endif

#if 0
	Vector2D& curPos = obj->getCurPos();
	curPos += obj->getVel0city() * delta;
#endif
}

void StateMove::Exit(GameObject* obj)
{

}
bool StateMove::OnMessage(GameObject* obj, const Telegram& msg)
{
	switch (msg.MsgId)
	{
	case MI_Follow:
	{
		break;
	}
	case MI_Follow_Stop:
	{
		break;
	}
	default:
		break;
	}
	return true;
}