#pragma once
#include "control.h"

enum DROP_ITEM_LIST_TYPES {
	DROP_BASE_CLASS = 10,
	DROP_ID_CLASS = 11,
	DROP_BIN_CLASS = 12
};

enum DROP_TYPE {
	NULL_EL,
	LEFT_SIDE,
	DOWN_SIDE 
};

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

	bool Hover() {
		return hover;
	}

	void Block(bool value) {
		block = value;
	}

	bool Block() {
		return block;
	}
} Item;

class DropDownList : public Control {
private:
	vector <Item*> List;
	SDL_Rect* item_sizes;

	bool show_list;

	int flag_select;
	int drop_type;

public:

	DropDownList(SDL_Renderer* _renderer, SDL_Rect _sizes, SDL_Rect _itemSizes, int _drop_type, string _font, int _font_size, int _text_align) : Control(_renderer, _sizes, _font, _font_size, _text_align)
	{
		drop_type = _drop_type;
		*item_sizes = _itemSizes;
		
		show_list = false;
	};

public:

	void render();

	Item* add(string text, int flag);

	void open(bool value);
	bool open();

	int checkItemHover(int x, int y);

	void setValue(string value);
	string getValue();

	int getFlag();
	const vector <Item*>* getItems();

	void clear();

	DropDownList* deleteItems();
};