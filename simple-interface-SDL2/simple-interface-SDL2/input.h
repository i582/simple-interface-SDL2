#pragma once
#include "control.h"

class Input : public Control {
private:
	bool focus;
public:
	Input(SDL_Rect _sizes, string _font, int _font_size, int _text_align) : Control(_sizes, "", _font, _font_size, _text_align)
	{
		focus = false;
	};
public:
	void render();
	void onEvent(SDL_Event* event);
	void Focus(bool value);
	string getValue();
	void clear();
};