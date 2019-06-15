#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include "color.h"
#include "iostream"
using namespace std;

enum TYPE_ALIGN {
	CENTERED_ALIGN,
	LEFT_ALIGN
};

class Control {
protected:
	SDL_Rect* sizes; 
	string label; 
	TTF_Font* font; 
	int font_size; 

	SDL_Renderer* renderer;

	COLOR Colors;

	int text_align;

	bool block; 
	bool display; 
public:
	Control(SDL_Renderer* renderer, SDL_Rect _sizes, string _font, int _font_size, int _text_align);
	~Control();
public:
	virtual void render(); 
	virtual void renderLabel(string text, SDL_Rect* place);

	void Block(bool value); 
	bool Block(); 

	void Display(bool value); 
	bool Display(); 

	bool Hover(int x, int y); 

	virtual void onEvent(SDL_Event* event); 
};