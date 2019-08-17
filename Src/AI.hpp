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



class AI
{
public:
	AI(AI_Type type, GameObject* objParent);
	virtual void init() {}
	virtual void update(Uint32 delta) {}

	void setCurPos(int x, int y);
	void setTargetPos(int x, int y);

	void addNodeToRoot(BTNode* node);

	BTNode* getRootNode() 
	{
		return m_rootNode;
	}

	GameObject* getObjParent()
	{
		return  m_objParent;
	}
		
private:
	AI() = default;


private:
	BTNode*		m_rootNode = nullptr;
	AI_Type		m_Type;
	Point2D		m_cur_pos;
	Point2D		m_target_pos;
	GameObject* m_objParent;


};







#endif //AI_hpp
