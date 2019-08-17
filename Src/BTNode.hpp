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
