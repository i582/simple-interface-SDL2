#pragma once
#include "control.h"

typedef struct Item {
	Item() {
		text = "";
		hover = false;
		block = false;
		flag = 0;
	}

	string text;
	bool hover;
	int flag;

	bool block;

	void Hover(bool value) {
		hover = value;
	}

	void Block(bool value) {
		block = value;
	}

	bool Hover() {
		return hover;
	}
} Item;

class ItemList : public Control {
private:
	vector <Item*> List;
	SDL_Rect* item_sizes;
	bool show_list;

public:
	ItemList(SDL_Renderer* _renderer, SDL_Rect _sizes, SDL_Rect _item_sizes, string _label, string _font, int _font_size, int _align_type) : Control(_renderer, _sizes, _font, _font_size, _align_type)
	{
		label = _label;
		*item_sizes = _item_sizes;

		show_list = false;
	};

public:
	void render();

	void add(string text, int flag);

	void open(bool value);
	bool open();

	int checkItemHover(int x, int y);
};