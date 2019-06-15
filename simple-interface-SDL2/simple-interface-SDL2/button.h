#pragma once
#include "control.h"

enum BUTTON_TYPES {
	BUTTON_OK_COUNT_ELEMENT,
	BUTTON_OK_SET_START_VALUE,

	BUTTON_OK_PERFORM_OPERATION,
	BUTTON_QUIT
};

class Button : public Control {
private:
	int type;
public:
	Button(SDL_Renderer* _renderer, SDL_Rect _sizes, string _text, int _type, string _font, int _font_size, int _text_align) : Control(_renderer, _sizes, _font, _font_size, _text_align)
	{
		type = _type;
	};
public:
	void render();
};