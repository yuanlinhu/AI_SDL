#include "StateRandomMove.h"
#include "../GameObject.hpp"

StateRandomMove* StateRandomMove::Instance()
{
	static StateRandomMove ins;
	return &ins;
}

void StateRandomMove::Enter(GameObject* obj)
{

}

void StateRandomMove::update(GameObject* obj, int delta)
{
	Point2D& curPos = obj->getCurPos();
	Point2D& targetPos = obj->getTargetPos();

	if (curPos == targetPos)
	{
		int x = rand() % MAP_WIDTH;
		int y = rand() % MAP_HEIGHT;
		obj->SetTargetPos(x, y);
	}
	else
	{
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
}

void StateRandomMove::Exit(GameObject* obj)
{

}
bool StateRandomMove::OnMessage(GameObject* obj, const Telegram& msg)
{
	return true;
}