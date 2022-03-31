#pragma once

enum MessageId
{
	MI_Null = 100,

	MI_Attack,			//¹¥»÷
	MI_Follow,			//¸úËæ
	MI_Follow_Stop,		//¸úËæÍ£Ö¹
};



struct Telegram
{
	int SenderId = 0;
	int ReceiverId = 0;

	MessageId MsgId = MI_Null;

	int DispatchTime = 0;
	
	int value = 0;
};

inline bool operator==(const Telegram& t1, const Telegram& t2)
{
	return (fabs(t1.DispatchTime - t2.DispatchTime) < 1) &&
		(t1.SenderId == t2.SenderId) &&
		(t1.ReceiverId == t2.ReceiverId) &&
		(t1.MsgId == t2.MsgId);
}

inline bool operator<(const Telegram& t1, const Telegram& t2)
{
	if (t1 == t2)
	{
		return false;
	}

	else
	{
		return  (t1.DispatchTime < t2.DispatchTime);
	}
}

