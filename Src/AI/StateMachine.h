#pragma once


#include "State.h"


class GameObject;
class State;


class StateMachine
{
public:
	StateMachine() = delete;

	StateMachine(GameObject* obj) : m_pOwner(obj) {}

	

	void Update(int delta)
	{
		if (m_pGlobalState)
		{
			m_pGlobalState->update(m_pOwner, delta);
		}

		if (m_pCurState)
		{
			m_pCurState->update(m_pOwner, delta);
		}
	}

	bool HandleMessage(const Telegram& telegram)
	{

		if (m_pCurState)
		{
			if (m_pCurState->OnMessage(m_pOwner, telegram))
			{
				return true;
			}
		}

		if (m_pGlobalState)
		{
			if (m_pGlobalState->OnMessage(m_pOwner, telegram))
			{
				return true;
			}
		}

		return false;
	}


	void ChangeState(State* newState)
	{
		if (nullptr == newState)
		{
			return;
		}

		if (m_pCurState)
		{
			m_pCurState->Exit(m_pOwner);
		}

		m_pPrevState = m_pCurState;

		m_pCurState = newState;
		m_pCurState->Enter(m_pOwner);
	} 


	void RevertPreviousState()
	{
		ChangeState(m_pPrevState);
	}

private:
	GameObject* m_pOwner = nullptr;

	State* m_pGlobalState = nullptr;
	State* m_pCurState = nullptr;
	State* m_pPrevState = nullptr;

};