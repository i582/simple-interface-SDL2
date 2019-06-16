#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include "color.h"
#include "iostream"
#include "vector"
using namespace std;

enum TYPE_ALIGN {
	CENTERED_ALIGN,
	LEFT_ALIGN
};



class Control {
public:
	static SDL_Renderer* renderer;

protected:
	SDL_Rect* sizes; 
	string label; 
	TTF_Font* font; 
	int font_size; 

	COLOR Colors;

	int text_align;

	bool block; 
	bool display; 
public:
	Control(SDL_Rect _sizes, string _label, string _font, int _font_size, int _text_align);
	~Control();
public:
	virtual void render(); 
	virtual void renderLabel(string text, SDL_Rect* place);
	virtual void renderLabel(string text, SDL_Rect* place, int _text_align);

	void Block(bool value); 
	bool Block(); 

	void Display(bool value); 
	bool Display(); 

	bool Hover(int x, int y); 

	virtual void onEvent(SDL_Event* event); 
};