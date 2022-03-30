#pragma once

#include "State.h"


class StateMove : public State
{
public:
	static StateMove* Instance();

	virtual void Enter(GameObject* obj) override;
	virtual void update(GameObject* obj, int delta) override;
	virtual void Exit(GameObject* obj) override;
	virtual bool OnMessage(GameObject* obj, const Telegram& msg) override;
};
