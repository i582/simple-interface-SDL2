#include "iostream"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "vector"

#include "Color.h"

#include "../control_elements/base_control.h"
#include "../control_elements/button.h"
#include "../control_elements/input.h"
#include "../control_elements/itemList.h"
#include "../control_elements/label.h"
#include "../control_elements/dropDownList.h"
#include "../control_elements/textField.h"

#include "../string_classes/String.h"
#include "../string_classes/ID_String.h"
#include "../string_classes/BIN_String.h"

using namespace std;


enum BUTTON_TYPES {
	BUTTON_OK_COUNT_ELEMENT,
	BUTTON_OK_SET_START_VALUE,

	BUTTON_OK_PERFORM_OPERATION,
	BUTTON_QUIT
};

enum STRING_CLASS_ID {
	STRING_BASE,
	STRING_ID,
	STRING_BIN
};

enum DROP_ITEM_LIST_TYPES {
	NULL_ELE,

	DROP_BASE_CLASS,
	DROP_ID_CLASS,
	DROP_BIN_CLASS
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

enum INPUT_TYPES {
	INPUT_COUNT_ELEMENT,
	INPUT_START_VALUE,

	INPUT_SYMBOL_INDEX_OF
};

enum TEXT_FIELD_TYPES {
	
};

class Interface {
private:
	bool running;

	SDL_Window* window;
	SDL_Renderer* renderer;

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
	void mouseMotion(SDL_Event* event);

	void quit();

public:
	int onExecute();

};
