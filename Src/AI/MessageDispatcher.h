#pragma once

#include <set>

class GameObject;
struct Telegram;
enum GameObjectType;
enum MessageId;


class MessageDispatcher
{
public:

	static MessageDispatcher* Instance();


	void DispatchMsg(int delay, GameObjectType senderId, GameObjectType recieverId, MessageId msgId, int value = 0);

	//处理消息体
	void HandleMsg(const Telegram& tel);


	void Update();

private:
	std::set<Telegram> mTelegramList;

};