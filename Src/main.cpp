//
//  main.cpp
//  AI_SDL_mac
//
//  Created by yuanlinhu on 2019/8/10.
//  Copyright © 2019 yuanlinhu. All rights reserved.
//

#include <iostream>
#include "Game.hpp"

int main(int argc, char * argv[]) {
    
	map<int, char> m;
	m[11] = 11;
	m[2] = 22;
	m[4] = 33;
	m[1] = 44;

	map<int, char>::const_iterator it = m.begin();
	while (it != m.end())
	{
		cout << it->first << " " << it->second << endl;
		it++;
	}

	it = m.begin();//相当于获取了平衡树最左下面（most left）的结点的迭代器 
	cout << "min " << it->first << " " << it->second << endl;//最小的key值 

	it = m.end();//相当于获取了平衡树最右下面（most right）的结点的迭代器 
	it--;
	cout << "max " << it->first << " " << it->second << endl; //最大的key值 


    Game game;

	game.go();
    
    //game.init("AI_SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, false);
    //while(game.running())
    //{
    //    game.handleEvents();
    //    game.update();
    //    game.render();
    //}
    //
    //game.clean();
    
    return 0;
}
