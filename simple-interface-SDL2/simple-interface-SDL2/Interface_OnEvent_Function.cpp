#include "interface.h"

void Interface::mouseButtonDown(SDL_Event* event)
{
	int x, y;
	SDL_GetMouseState(&x, &y);
}

void Interface::mouseButtonUp(SDL_Event* event)
{
	int x, y;
	SDL_GetMouseState(&x, &y);

	for (int i = 0; i < Inputs.size(); i++) {
		if (Inputs.at(i)->Hover(x, y)) {
			Inputs.at(i)->Focus(true);
			Inputs.at(i)->render();
			Inputs.at(i)->onEvent(event);
		}
	}


	for (int i = 0; i < ItemLists.size(); i++) {
		int flag = ItemLists.at(i)->checkItemHover(x, y);

		if (ItemLists.at(i)->Hover(x, y)) {

			if (!ItemLists.at(i)->open()) {
				for (int i = 0; i < ItemLists.size(); i++) {
					ItemLists.at(i)->open(false);
					ItemLists.at(i)->render();
				}

				ItemLists.at(i)->open(true);
				ItemLists.at(i)->render();
			}
			else {
				ItemLists.at(i)->open(false);
				ItemLists.at(i)->render();
			}
		}
		else {

			if (flag) {

				for (size_t i = 0; i < ItemLists.size(); i++) {
					ItemLists.at(i)->open(false);
					ItemLists.at(i)->render();
				}

				switch (flag)
				{

				case TEST_STRING_EQUAL: {

					break;
				}

				case TEST_STRING_GET_LENGTH: {

					break;
				}


				case TEST_IDENTIFICATION_OPERATOR_TO_LOWER_CASE: {

					break;
				}

				case TEST_IDENTIFICATION_OPERATOR_EQUAL: {

					break;
				}

				case TEST_IDENTIFICATION_OPERATOR_SUBTRACTION: {

					break;
				}

				case TEST_IDENTIFICATION_INDEX_OF: {

					break;
				}

				case TEST_BINARY_REVERSE: {

					break;
				}

				case TEST_BINARY_SUBTRACTION: {

					break;
				}

				default: break;
				}
			}
			else {
				if (ItemLists.at(i)->open()) {
					ItemLists.at(i)->open(false);
					ItemLists.at(i)->render();
				}
			}
		}
	}


	for (int i = 0; i < DropDownLists.size(); i++)
	{
		int flag = DropDownLists.at(i)->checkItemHover(x, y);

		if (DropDownLists.at(i)->Hover(x, y)) {

			if (!DropDownLists.at(i)->open()) {

				for (int j = 0; j < DropDownLists.size(); j++) {
					if (DropDownLists.at(j)->open()) {
						DropDownLists.at(j)->open(false);
						DropDownLists.at(j)->render();
					}
				}

				DropDownLists.at(i)->open(true);
			}
			else
				DropDownLists.at(i)->open(false);

			DropDownLists.at(i)->render();
		}
		else if (flag)
		{
			DropDownLists.at(i)->setValue(DropDownLists.at(i)->getItems()->at(flag - 10)->text);
			DropDownLists.at(i)->open(false);
			DropDownLists.at(i)->render();
		}
		else {
			if (DropDownLists.at(i)->open()) {
				DropDownLists.at(i)->open(false);
				DropDownLists.at(i)->render();
			}
		}
	}
}

