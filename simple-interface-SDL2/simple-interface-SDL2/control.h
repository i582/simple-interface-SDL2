#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include "iostream"
using namespace std;

// Базовый класс для элементов управления
class Control {
protected:
	SDL_Rect* sizes; // размеры элемента
	string label; // текст на элементе
	TTF_Font* font; // шрифт для надписей
	int font_size; // размер шрифта

	SDL_Renderer* renderer;

	bool block; // флаг для блокировки
	bool display; // флаг для отображения
public:
	Control(SDL_Renderer* renderer, SDL_Rect _sizes, string _font, int _font_size);
	~Control();
public:
	virtual void render(); // функция отображения тела элемента
	virtual void renderLabel(string text, SDL_Rect* place); // функция отображения текста элемента

	void Block(bool value); // функция задающая переменной block значение value
	bool Block(); // функция возвращающая текущее значение переменной block

	void Display(bool value); // функция задающая переменной display значение value
	bool Display(); // функция возвращающая текущее значение переменной display

	bool Hover(int x, int y); // функция проверяющая входит ли эта точка в элемент

	virtual void onEvent(SDL_Event* event); // функция отслеживания событий
};