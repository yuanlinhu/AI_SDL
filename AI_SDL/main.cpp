#include <iostream>
#include <SDL.h>
#include <time.h>
#include "Entity.h"
#include "macro.h"
#include "Map.h"

using namespace std;

bool init();
void kill();
bool load();
bool loop();

// Variables to hold our window and surfaces
SDL_Window* window;
SDL_Surface* winSurface;
SDL_Surface* image1;
SDL_Surface* image2;
SDL_Renderer *render;

Entity gEntity;
Map		gMap;

//SDL_Rect* rectangle;

//static const float fps_60 = 16.666f;
//static const float fps_30 = fps_60 * 2;

//֡�ʵ�����
//Timer fps;

void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL)
{
	//Holds offsets
	SDL_Rect offset;

	//Get offsets
	offset.x = x;
	offset.y = y;

	//Blit
	SDL_BlitSurface(source, clip, destination, &offset);
}



int DxGetFPS()
{
	static float  fps = 0;
	static int    frameCount = 0;
	static float  currentTime = 0.0f;//��ǰʱ��
	static float  lastTime = 0.0f;//����ʱ��

	frameCount++;//ÿ����һ��Get_FPS()������֡��+1
	currentTime = clock() * 0.001f;//��ȡϵͳʱ��,��ת������Ϊ��λ
								   //������һ�룬�ͽ���һ��FPS�ļ���ͳ���ʱ��ĸ��£�����֡��ֵ����
	if (currentTime - lastTime > 1.0f) //��ʱ�������1����
	{
		fps = (float)frameCount / (currentTime - lastTime);//������1���ӵ�FPSֵ
		lastTime = currentTime; //����ǰʱ��currentTime��Ϊ��һ��Ļ�׼ʱ��
		frameCount = 0;//������֡��frameCountֵ����
	}
	return (int)fps;
}









const int DOT_WIDTH = 10;
const int DOT_HEIGHT = 10;

//class Dot
//{
//private:
//	//Բ���X��Y����
//	int x, y;
//
//	//Բ��ֱ���X��Y�����ϵ��ٶȷ���
//	int xVel, yVel;
//
//public:
//	//��ʼ������
//	Dot();
//
//	//���ռ������벢�ı�Բ����ٶ�
//	void handle_input(SDL_Event& e);
//
//	//��Բ�㺯��
//	void move();
//
//	//��ʾԭ��
//	void show();
//};
//
//Dot::Dot()
//{
//	//��ʼ������
//	x = 0;
//	y = 0;
//
//	//��ʼ������
//	xVel = 0;
//	yVel = 0;
//}
//
//void Dot::handle_input(SDL_Event& event)
//{
//	//��һ����������
//	if (event.type == SDL_KEYDOWN)
//	{
//		//�����ٶ�
//		switch (event.key.keysym.sym)
//		{
//		case SDLK_UP: yVel -= DOT_HEIGHT / 2; break;
//		case SDLK_DOWN: yVel += DOT_HEIGHT / 2; break;
//		case SDLK_LEFT: xVel -= DOT_WIDTH / 2; break;
//		case SDLK_RIGHT: xVel += DOT_WIDTH / 2; break;
//		}
//	}
//	//��һ�����̰������ɿ�
//	else if (event.type == SDL_KEYUP)
//	{
//		//�����ٶ�
//		switch (event.key.keysym.sym)
//		{
//		case SDLK_UP: yVel += DOT_HEIGHT / 2; break;
//		case SDLK_DOWN: yVel -= DOT_HEIGHT / 2; break;
//		case SDLK_LEFT: xVel += DOT_WIDTH / 2; break;
//		case SDLK_RIGHT: xVel -= DOT_WIDTH / 2; break;
//		}
//	}
//}
//
//void Dot::move()
//{
//	//��Բ�������ƶ�
//	x += xVel;
//
//	//��Բ������������һ���ߵ�̫Զʱ
//	if ((x < 0) || (x + DOT_WIDTH > SCREEN_WIDTH))
//	{
//		//����ק����
//		x -= xVel;
//	}
//
//	//��Բ�������ƶ�
//	y += yVel;
//
//	//��Բ������������һ���ߵ�̫Զʱ
//	if ((y < 0) || (y + DOT_HEIGHT > SCREEN_HEIGHT))
//	{
//		//ק����
//		y -= yVel;
//	}
//}
//
//void Dot::show()
//{
//	//��ʾԲ��
//	apply_surface(x, y, dot, screen);
//}
//

//void DrawRect(int width, int height, int color = 1)
//{
//	if (color == 0)
//	{
//		SDL.SDL_SetRenderDrawColor(sdlrenderer, 255, 0, 0, 1);// ��
//	}
//	else if (color == 1)
//	{
//		SDL.SDL_SetRenderDrawColor(sdlrenderer, 0, 255, 0, 1);// ��
//	}
//	else if (color == 2)
//	{
//		SDL.SDL_SetRenderDrawColor(sdlrenderer, 0, 0, 255, 1);// ��
//	}
//	rectangle.x = 0;
//	rectangle.y = 0;
//	rectangle.w = width;
//	rectangle.h = height;
//	SDL_RenderFillRect(sdlrenderer, ref rectangle);
//}
//






int main(int argc, char** args) {

	if (!init()) return 1;

	//if (!load()) return 1;

	while (loop()) {
		// wait before processing the next frame
		//SDL_Delay(10);


		Uint64 start = SDL_GetPerformanceCounter();

		// Do event loop

		// Do physics loop

		// Do rendering loop

		gEntity.update();
		gMap.update();


		Uint64 end = SDL_GetPerformanceCounter();

		float elapsedMS = (end - start) / (float)SDL_GetPerformanceFrequency() * 1000.0f;

		// Cap to 60 FPS
		
		SDL_Delay(floor(fps_30 - elapsedMS));

		//float elapsed = (end - start) / (float)SDL_GetPerformanceFrequency();
		//int fps = (int)(1.0f / elapsed);
		cout << "Current FPS: " << DxGetFPS() << endl;
	}

	kill();
	return 0;
}

bool loop() {

	static bool renderImage2;
	SDL_Event e;

	// Blit image to entire window
	//SDL_BlitSurface(image1, NULL, winSurface, NULL);

	while (SDL_PollEvent(&e) != 0) {
		switch (e.type) {
		case SDL_QUIT:
			return false;
		case SDL_KEYDOWN:
			renderImage2 = true;
			break;
		case SDL_KEYUP:
			renderImage2 = false;
			// can also test individual keys, modifier flags, etc, etc.
			break;
		case SDL_MOUSEMOTION:
			// etc.
			break;
		}
	}

	//if (renderImage2) {
	//	// Blit image to scaled portion of window
	//	SDL_Rect dest;
	//	dest.x = 160;
	//	dest.y = 120;
	//	dest.w = 320;
	//	dest.h = 240;
	//	SDL_BlitScaled(image2, NULL, winSurface, &dest);
	//}

	SDL_FillRect(winSurface, NULL, SDL_MapRGB(winSurface->format, 200, 200, 200));

	//render
	gMap.show(winSurface, render);

	gEntity.show(winSurface);

	// Update window
	SDL_UpdateWindowSurface(window);

	return true;
}

bool load() {
	// Temporary surfaces to load images into
	// This should use only 1 temp surface, but for conciseness we use two
	SDL_Surface *temp1, *temp2;

	// Load images
	temp1 = SDL_LoadBMP("test1.bmp");
	temp2 = SDL_LoadBMP("test2.bmp");

	// Make sure loads succeeded
	if (!temp1 || !temp2) {
		cout << "Error loading image: " << SDL_GetError() << endl;
		return false;
	}

	// Format surfaces
	image1 = SDL_ConvertSurface(temp1, winSurface->format, 0);
	image2 = SDL_ConvertSurface(temp2, winSurface->format, 0);

	// Free temporary surfaces
	SDL_FreeSurface(temp1);
	SDL_FreeSurface(temp2);

	// Make sure format succeeded
	if (!image1 || !image2) {
		cout << "Error converting surface: " << SDL_GetError() << endl;
		return false;
	}
	return true;
}

bool init() {
	// See last example for comments
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "Error initializing SDL: " << SDL_GetError() << endl;
		return false;
	}

	window = SDL_CreateWindow("Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_w, window_h, SDL_WINDOW_SHOWN);
	if (!window) {
		cout << "Error creating window: " << SDL_GetError() << endl;
		return false;
	}

	/* Create a Render */
	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (render == nullptr) {
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	winSurface = SDL_GetWindowSurface(window);
	if (!winSurface) {
		cout << "Error getting surface: " << SDL_GetError() << endl;
		return false;
	}

	//SDL_FillRect(winSurface, NULL, SDL_MapRGB(winSurface->format, 128, 128, 128));

	//SDL_Rect rect;
	//rect.x = 100;
	//rect.y = 100;
	//rect.w = 100;
	//rect.h = 100;
	//SDL_FillRect(winSurface, &rect, SDL_MapRGB(winSurface->format, 0, 90, 120));
	//SDL_RenderFillRect(sdlrenderer, ref rectangle);
	//rectangle = new SDL_Rect();

	gEntity.set_random_birth_pos();
	gMap.initMap();
	return true;
}

void kill() {
	// Free images
	SDL_FreeSurface(image1);
	SDL_FreeSurface(image2);

	// Quit
	SDL_DestroyWindow(window);
	SDL_Quit();
}
