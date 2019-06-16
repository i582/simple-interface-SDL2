#pragma once
#include "control.h"

class Button : public Control {
private:
	int type;
public:
	Button(SDL_Rect _sizes, string _text, int _type, string _font, int _font_size, int _text_align) : Control(_sizes, _text, _font, _font_size, _text_align)
	{
		type = _type;
	};
public:
	void render();
};