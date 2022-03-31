#pragma once


class GameObject;
struct Telegram;

class State
{
public:

	virtual ~State() {}

	virtual void Enter(GameObject* obj) = 0;
	virtual void update(GameObject* obj, int delta) = 0;
	virtual void Exit(GameObject* obj) = 0;
	virtual bool OnMessage(GameObject* obj, const Telegram& msg) = 0;
};