#pragma once
#include "control.h"

enum INPUT_TYPES {
	INPUT_COUNT_ELEMENT,
	INPUT_START_VALUE,

	INPUT_SYMBOL_INDEX_OF
};

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