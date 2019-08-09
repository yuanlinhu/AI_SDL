#pragma once

#include "SDL_events.h"

class Dot
{
private:
	//圆点的X，Y坐标
	int x, y;

	//圆点分别在X，Y方向上的速度分量
	int xVel, yVel;

public:
	//初始化变量
	Dot();

	//接收键盘输入并改变圆点的速度
	void handle_input(SDL_Event& e);

	//溜圆点函数
	void move();

	//显示原点
	void show();
};