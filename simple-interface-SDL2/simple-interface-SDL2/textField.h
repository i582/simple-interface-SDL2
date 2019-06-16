#pragma once
#include "control.h"
#include "vector"

class TextField : public Control {
private:
	vector <string> lines;
public:
	TextField(SDL_Renderer* _renderer, SDL_Rect* _sizes, string _font, int _font_size, int _text_align) : Control(_renderer, _sizes, _font, _font_size, _text_align)
	{};

public:
	void add(string newLine);

	void render();
	void renderText();
};