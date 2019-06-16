#pragma once
#include "control.h"

class Label : public Control {
private:
	// none
public:
	Label(SDL_Rect _sizes, string _new_string, string _font, int _font_size, int _text_align) : Control(_sizes, _new_string, _font, _font_size, _text_align)
	{};
public:
	void render();
	void setText(string text);
};