//
//  Game.hpp
//  AI_SDL_mac
//
//  Created by yuanlinhu on 2019/8/10.
//  Copyright © 2019 yuanlinhu. All rights reserved.
//

#ifndef BTNode_Sequence_hpp
#define BTNode_Sequence_hpp

#include "Macros.hpp"
#include "BTNode.hpp"


class BTNode_Sequence : public BTNode
{
public:
	BTNode_Sequence(GameObject* objParent);
	
	virtual bool check() override;
	virtual bool run(int delta) override;
};







#endif //BTNode_Sequence_hpp
