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
	BTNode(BTNodeType type, GameObject* objParent);
	
	void addChild(BTNode* node);
	
	virtual bool check() = 0;
	virtual bool run(int delta) = 0;

	list<BTNode*>&		getChildNodeList();
	GameObject*			getObjParent();
private:
	BTNodeType m_type;
	GameObject* m_objParent = nullptr;

	list<BTNode*>		m_childNode;

private:
	BTNode() = default;
    
};







#endif //BTNode_hpp
