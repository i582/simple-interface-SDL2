#include "interface.h"

int Interface::onExecute()
{
	init();


	SDL_Rect coord = { 520, 80, 0, 20 };
	Label* label = new Label(renderer, coord, "Count of Elements", "fonts/verdana.ttf", 11, LEFT_ALIGN);

	Labels.push_back(label);

	coord = { 520, 130, 160, 20 };
	Button* newButton1 = new Button(
		renderer,
		coord,
		"OK",
		BUTTON_OK_COUNT_ELEMENT,
		"fonts/verdana.ttf", 12, 
		CENTERED_ALIGN
	);
	Buttons.push_back(newButton1);

	coord = { 520, 280, 160, 20 };
	Input* newInput = new Input(renderer, coord, "fonts/verdana.ttf", 12, LEFT_ALIGN);
	
	Inputs.push_back(newInput);

	SDL_Rect mainList1 = { 520, 240, 160, 20 };
	SDL_Rect item1 = { -1, -1, 160, 20 };
	DropDownList* DropDownList2 = new DropDownList(renderer, mainList1, item1, LEFT_SIDE, "fonts/verdana.ttf", 12, LEFT_ALIGN);


	DropDownList2->add("Base class", DROP_BASE_CLASS);
	DropDownList2->add("Identification class", DROP_ID_CLASS);
	DropDownList2->add("Binary string class", DROP_BIN_CLASS);


	DropDownLists.push_back(DropDownList2);

	//SDL_Rect mainList = { 520, 100, 160, 20 };
	//SDL_Rect item = { -1, -1, 30, 20 };
	//DropDownList* DropDownList1 = new DropDownList(renderer, &mainList, &item, LEFT_SIDE, "fonts/verdana.ttf", 12);

	//for (size_t i = 1; i < 11; i++) {
	//	char* num = new char[10];
	//	_itoa(i, num, 10);
	//	DropDownList1->add(num, i + 9);
	//}


	//DropDownLists.push_back(DropDownList1);


	//SDL_Rect rect1 = { 520, 130, 160, 20 };
	//Button* newButton1 = new Button(
	//	renderer,
	//	&rect1,
	//	"OK",
	//	BUTTON_OK_COUNT_ELEMENT,
	//	"fonts/verdana.ttf", 12
	//);
	//Buttons.push_back(newButton1);









	//SDL_Rect coord3 = { 520, 200, 0, 20 };
	//Label* label3 = new Label(renderer, &coord3, "Count of items not set", "fonts/verdana.ttf", 11);

	//Labels.push_back(label3);

	//SDL_Rect coord1 = { 520, 220, 0, 20 };
	//Label* label1 = new Label(renderer, &coord1, "Type", "fonts/verdana.ttf", 11);
	//Labels.push_back(label1);

	//SDL_Rect mainList1 = { 520, 240, 160, 20 };
	//SDL_Rect item1 = { -1, -1, 160, 20 };
	//DropDownList* DropDownList2 = new DropDownList(renderer, &mainList1, &item1, LEFT_SIDE, "fonts/verdana.ttf", 12);


	//DropDownList2->add("Base class", DROP_BASE_CLASS);
	//DropDownList2->add("Identification class", DROP_ID_CLASS);
	//DropDownList2->add("Binary string class", DROP_BIN_CLASS);

	//DropDownList2->blocked();

	//DropDownLists.push_back(DropDownList2);

	//SDL_Rect coord2 = { 520, 260, 0, 20 };
	//Label* label2 = new Label(renderer, &coord2, "Value", "fonts/verdana.ttf", 11);
	//Labels.push_back(label2);

	//SDL_Rect rect = { 520, 280, 160, 20 };
	//Input* newInput = new Input(renderer, &rect, INPUT_COUNT_ELEMENT, "fonts/verdana.ttf", 12);
	//newInput->blocked();
	//Inputs.push_back(newInput);


	//SDL_Rect rect2 = { 520, 310, 160, 20 };
	//Button* newButton2 = new Button(
	//	renderer,
	//	&rect2,
	//	"OK",
	//	BUTTON_OK_SET_START_VALUE,
	//	"fonts/verdana.ttf", 12
	//);
	//newButton2->blocked();
	//Buttons.push_back(newButton2);



	//// ���������� ������ �� ����� �������� //
	//SDL_Rect mainList2 = { 850, 100, 160, 20 };
	//SDL_Rect item2 = { -1, -1, 200, 20 };
	//DropDownList* DropDownList3 = new DropDownList(renderer, &mainList2, &item2, LEFT_SIDE, "fonts/verdana.ttf", 12);

	//DropDownLists.push_back(DropDownList3);







	////##### ����� �������� ��� �������� ######// 


	//SDL_Rect itemList_ItemRect = { -1, -1, 160, 20 };
	//// ���������� ������ ��� �������� ������ //
	//{
	//	SDL_Rect itemListRect1 = { 850, 125, 160, 20 };


	//	ItemList* itemList1 = new ItemList(renderer, &itemListRect1, &itemList_ItemRect, "String", "fonts/verdana.ttf", 12);

	//	itemList1->add("Operator =", TEST_STRING_EQUAL);
	//	itemList1->add("Get length", TEST_STRING_GET_LENGTH);

	//	ItemLists.push_back(itemList1);
	//}

	//// ���������� ������ ��� ������ �������������� //
	//{
	//	SDL_Rect itemListRect2 = { 850, 150, 160, 20 };


	//	ItemList* itemList2 = new ItemList(renderer, &itemListRect2, &itemList_ItemRect, "Identificator", "fonts/verdana.ttf", 12);

	//	itemList2->add("Operator =", TEST_IDENTIFICATION_OPERATOR_EQUAL);
	//	itemList2->add("To lower case", TEST_IDENTIFICATION_OPERATOR_TO_LOWER_CASE);
	//	itemList2->add("Substraction", TEST_IDENTIFICATION_OPERATOR_SUBTRACTION);
	//	itemList2->add("Index of symbol", TEST_IDENTIFICATION_INDEX_OF);

	//	ItemLists.push_back(itemList2);
	//}

	//// ���������� ������ ��� ������ ���������� ������ //
	//{
	//	SDL_Rect itemListRect3 = { 850, 175, 160, 20 };


	//	ItemList* itemList3 = new ItemList(renderer, &itemListRect3, &itemList_ItemRect, "Binary", "fonts/verdana.ttf", 12);

	//	itemList3->add("Reverse", TEST_BINARY_REVERSE);
	//	itemList3->add("Subtraction", TEST_BINARY_SUBTRACTION);

	//	ItemLists.push_back(itemList3);
	//}

	//// ������ ��� ������ ������� �������� //
	//{
	//	SDL_Rect coord4 = { 750, 220, 0, 20 };
	//	Label* label4 = new Label(renderer, &coord4, BY_LEFT, "First operand", "fonts/verdana.ttf", 11);
	//	label4->show(false);
	//	Labels.push_back(label4);

	//	SDL_Rect DropDownList_Rect3 = { 750, 240, 160, 20 };
	//	SDL_Rect item_Rect = { -1, -1, 160, 20 };
	//	DropDownList* DropDownList4 = new DropDownList(renderer, &DropDownList_Rect3, &item_Rect, DOWN_SIDE, "fonts/verdana.ttf", 12);
	//	DropDownList4->hide();
	//	DropDownLists.push_back(DropDownList4);
	//}

	//// ������ ��� ������ ������� �������� //
	//{
	//	SDL_Rect coord5 = { 930, 220, 0, 20 };
	//	Label* label5 = new Label(renderer, &coord5, BY_LEFT, "Second operand", "fonts/verdana.ttf", 11);
	//	label5->show(false);
	//	Labels.push_back(label5);

	//	SDL_Rect DropDownList_Rect4 = { 930, 240, 160, 20 };
	//	SDL_Rect item_Rect = { -1, -1, 160, 20 };
	//	DropDownList* DropDownList5 = new DropDownList(renderer, &DropDownList_Rect4, &item_Rect, DOWN_SIDE, "fonts/verdana.ttf", 12);
	//	DropDownList5->hide();
	//	DropDownLists.push_back(DropDownList5);
	//}


	//// ���� ��� ����� ������� ��� ������ //
	//{
	//	SDL_Rect coord8 = { 930, 220, 0, 20 };
	//	Label* label8 = new Label(renderer, &coord8, BY_LEFT, "Field for symbol", "fonts/verdana.ttf", 11);
	//	label8->show(false);
	//	Labels.push_back(label8);

	//	SDL_Rect coord9 = { 930, 240, 160, 18 };
	//	Input* newInput1 = new Input(renderer, &coord9, INPUT_SYMBOL_INDEX_OF, "fonts/verdana.ttf", 12);
	//	newInput1->hide();
	//	Inputs.push_back(newInput1);
	//}



	//// ������ ����� ����������
	//{
	//	SDL_Rect rect3 = { 850, 450, 160, 20 };
	//	Button* newButton3 = new Button(
	//		renderer,
	//		&rect3,
	//		"OK",
	//		BUTTON_OK_PERFORM_OPERATION,
	//		"fonts/verdana.ttf", 12
	//	);
	//	newButton3->hide();
	//	Buttons.push_back(newButton3);
	//}





	//{
	//	SDL_Rect coord6 = { 0, 0, 400, 500 };
	//	TextField* textField = new TextField(renderer, &coord6, "fonts/verdana.ttf", 11);

	//	TextFields.push_back(textField);
	//}



	//SDL_Rect coord7 = { 850, 80, 0, 20 };
	//Label* label7 = new Label(renderer, &coord7, BY_LEFT, "All classes", "fonts/verdana.ttf", 11);
	//Labels.push_back(label7);


	//SDL_Rect rect21 = { 1080, 20, 100, 20 };
	//Button* newButton21 = new Button(
	//	renderer,
	//	&rect21,
	//	"Quit",
	//	BUTTON_QUIT,
	//	"fonts/verdana.ttf", 12
	//);
	//Buttons.push_back(newButton21);

	render();
	onEvent();


	return 0;
}
