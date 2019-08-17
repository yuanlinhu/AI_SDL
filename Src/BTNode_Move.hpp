//
//  Game.hpp
//  AI_SDL_mac
//
//  Created by yuanlinhu on 2019/8/10.
//  Copyright © 2019 yuanlinhu. All rights reserved.
//

#ifndef BTNode_Move_hpp
#define BTNode_Move_hpp

#include "Macros.hpp"
#include "BTNode.hpp"


class BTNode_Move : public BTNode
{
public:
	BTNode_Move(GameObject* objParent);
	
	virtual bool check() override;
	virtual bool run(int delta) override;

};







#endif //BTNode_Move_hpp
