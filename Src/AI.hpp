//
//  Game.hpp
//  AI_SDL_mac
//
//  Created by yuanlinhu on 2019/8/10.
//  Copyright © 2019 yuanlinhu. All rights reserved.
//

#ifndef AI_hpp
#define AI_hpp

#include "Macros.hpp"

enum BTNodeType
{
	BTNT_NULL = 0,
	
	BTNT_ROOT,		//根节点

	BTNT_SEQUENCE,	//顺序
	BTNT_SELECT,	//选择


	BTNT_MAX,
};

class AI
{
public:

private:

	list<BTNode*>		m_childNode;

private:
	AI() = default;
    
};







#endif //AI_hpp
