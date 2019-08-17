//
//  Game.hpp
//  AI_SDL_mac
//
//  Created by yuanlinhu on 2019/8/10.
//  Copyright © 2019 yuanlinhu. All rights reserved.
//

#ifndef AI_Player_hpp
#define AI_Player_hpp

#include "Macros.hpp"
#include "AI.hpp"


class AI_Player : public AI
{
public:
	AI_Player(GameObject* objParent);
	virtual void init() override;
	virtual void update(Uint32 delta) override;

};




#endif //AI_Player_hpp
