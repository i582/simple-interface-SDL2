#include "iostream"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "vector"

#include "Color.h"

#include "control.h"
#include "button.h"
#include "input.h"
#include "itemList.h"
#include "label.h"
#include "dropDownList.h"
#include "textField.h"

#include "string_classes/String.h"
#include "string_classes/ID_String.h"
#include "string_classes/BIN_String.h"

using namespace std;



enum STRING_CLASS_ID {
	STRING_BASE,
	STRING_ID,
	STRING_BIN
};

enum ITEM_LIST_TYPES {
	NULLELE,

	TEST_STRING_EQUAL,
	TEST_STRING_GET_LENGTH,

	TEST_IDENTIFICATION_OPERATOR_TO_LOWER_CASE,
	TEST_IDENTIFICATION_OPERATOR_EQUAL,
	TEST_IDENTIFICATION_OPERATOR_SUBTRACTION,
	TEST_IDENTIFICATION_INDEX_OF,

	TEST_BINARY_REVERSE,
	TEST_BINARY_SUBTRACTION
};


class Interface {
private:
	bool running;

	SDL_Window* window;
	SDL_Renderer* _renderer;
	SDL_Event event;
	SDL_Texture* texture;

	short screenWidth;
	short screenHeight;

	COLOR Colors;

	// элементы интерфейса
	vector <Button*> Buttons;
	vector <Input*> Inputs;
	vector <ItemList*> ItemLists;
	vector <DropDownList*> DropDownLists;
	vector <Label*> Labels;
	vector <TextField*> TextFields;
	//


	// Элементы приложения
	bool ready_fill_classes;

	int count_ready;
	int count_element;
	vector <String*> ptrBaseClass;
	vector <int> type_ptrBaseClasses;

	int nowOperation;

public:
	Interface();
	Interface(short width, short height);
	~Interface();

private:
	void render();
	void onEvent();

	bool init();
	void setup();

	void mouseButtonDown(SDL_Event* event);
	void mouseButtonUp(SDL_Event* event);

	void quit();

public:
	int onExecute();

};
