//
//  Game.hpp
//  AI_SDL_mac
//
//  Created by yuanlinhu on 2019/8/10.
//  Copyright © 2019 yuanlinhu. All rights reserved.
//

#ifndef BTNode_hpp
#define BTNode_hpp

#include "Macros.hpp"

enum BTNodeType
{
	BTNT_NULL = 0,
	
	BTNT_ROOT,		//根节点
	BTNT_LEAF,		//节点		执行逻辑

	BTNT_SEQUENCE,	//顺序
	BTNT_SELECT,	//选择


	BTNT_MAX,
};

class BTNode
{
public:
	BTNode(BTNodeType type);
	
	void addChild(BTNode* node);
	bool check();

	bool run();

private:
	BTNodeType m_type;

	list<BTNode*>		m_childNode;

private:
	BTNode() = default;
    
};







#endif //BTNode_hpp
