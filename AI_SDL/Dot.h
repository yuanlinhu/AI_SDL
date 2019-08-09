#pragma once

#include "SDL_events.h"

class Dot
{
private:
	//Բ���X��Y����
	int x, y;

	//Բ��ֱ���X��Y�����ϵ��ٶȷ���
	int xVel, yVel;

public:
	//��ʼ������
	Dot();

	//���ռ������벢�ı�Բ����ٶ�
	void handle_input(SDL_Event& e);

	//��Բ�㺯��
	void move();

	//��ʾԭ��
	void show();
};