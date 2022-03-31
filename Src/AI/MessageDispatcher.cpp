
#include "MessageDispatcher.h"
#include "../GameObjectMgr.hpp"
#include "Telegram.h"
#include <windows.h>
#include "StateMachine.h"
#include "../GameObject.hpp"

MessageDispatcher* MessageDispatcher::Instance()
{
	static MessageDispatcher ins;
	return &ins;
}

void MessageDispatcher::DispatchMsg(int delay, GameObjectType senderId, GameObjectType recieverId, MessageId msgId, int value /*= 0*/)
{
	GameObject* senderObj = GameObjectMgr::Instance()->getObjectByType((GameObjectType)senderId);
	GameObject* recvObj = GameObjectMgr::Instance()->getObjectByType((GameObjectType)recieverId);
	if (senderObj == nullptr || recvObj == nullptr)
	{
		return;
	}


	Telegram tel;
	tel.SenderId = senderId;
	tel.ReceiverId = recieverId;
	tel.MsgId = msgId;
	tel.DispatchTime = GetTickCount() + delay;
	tel.value = value;
	
	if (delay <= 0)
	{
		HandleMsg(tel);
	}
	else
	{
		mTelegramList.insert(tel);
	}
}

void MessageDispatcher::HandleMsg(const Telegram& tel)
{
	GameObject* recvObj = GameObjectMgr::Instance()->getObjectByType((GameObjectType)tel.ReceiverId);
	if (recvObj == nullptr)
	{
		return;
	}

	recvObj->GetStateMachine()->HandleMessage(tel);
}


void MessageDispatcher::Update()
{
	if (mTelegramList.empty())
	{
		return;
	}

	int nowTicks = GetTickCount();
	for (auto iter = mTelegramList.begin(); iter != mTelegramList.end(); /**/)
	{
		if (iter->DispatchTime >= (nowTicks))
		{
			//¹ýÆÚ
			HandleMsg(*iter);

			iter = mTelegramList.erase(iter);
		}
		else
		{
			iter++;
		}
	}

}
