#include "dropDownList.h"

DropDownList::~DropDownList()
{
	delete item_sizes;
}

void DropDownList::render()
{
	if (!display) {
		SDL_Rect clearRect = *sizes;
		clearRect.x--;
		clearRect.y--;
		clearRect.w += 2;
		clearRect.h += 2;

		SDL_SetRenderDrawColor(renderer, Colors.background.r, Colors.background.g, Colors.background.b, Colors.background.a);
		SDL_RenderFillRect(renderer, &clearRect);
		return;
	}

	SDL_Rect renderRect = *item_sizes;

	if (drop_type == LEFT_SIDE) {
		renderRect.x = sizes->x + sizes->w + 2;
		renderRect.y = sizes->y;
	}
	else if (drop_type == DOWN_SIDE) {
		renderRect.x = sizes->x;
		renderRect.y = sizes->y + sizes->h + 2;
	}

	if (block)
		SDL_SetRenderDrawColor(renderer, Colors.element_blocked.r, Colors.element_blocked.g, Colors.element_blocked.b, Colors.element_blocked.a);
	else
		SDL_SetRenderDrawColor(renderer, Colors.element_background_unfocus.r, Colors.element_background_unfocus.g, Colors.element_background_unfocus.b, Colors.element_background_unfocus.a);

	SDL_RenderFillRect(renderer, sizes);
	renderLabel(label, sizes, LEFT_ALIGN);
	

	if (show_list && !block) 
	{
		for (int i = 0; i < List.size(); i++)
		{
			if (List.at(i)->Block()) 
				SDL_SetRenderDrawColor(renderer, Colors.element_blocked.r, Colors.element_blocked.g, Colors.element_blocked.b, Colors.element_blocked.a);
			else
				SDL_SetRenderDrawColor(renderer, Colors.element_background.r, Colors.element_background.g, Colors.element_background.b, Colors.element_background.a);

			SDL_RenderFillRect(renderer, &renderRect);
			renderLabel(List[i]->text, &renderRect, LEFT_ALIGN);
			renderRect.y += renderRect.h;
		}
	}
	else 
	{
		SDL_Rect clearRect = { renderRect.x, renderRect.y, renderRect.w, renderRect.h * List.size() };
		SDL_SetRenderDrawColor(renderer, Colors.background.r, Colors.background.g, Colors.background.b, Colors.background.a);
		SDL_RenderFillRect(renderer, &clearRect);
	}

	SDL_RenderPresent(renderer);
}

DropDownItem* DropDownList::add(string text, int flag)
{
	DropDownItem* newItem = new DropDownItem;
	newItem->text = text;
	newItem->flag = flag;

	List.push_back(newItem);

	return newItem;
}

void DropDownList::open(bool value)
{
	show_list = value;
}

bool DropDownList::open()
{
	return show_list;
}

int DropDownList::checkItemHover(int x, int y)
{
	if (block || !display || !show_list)
		return false;

	SDL_Point point = { x, y };

	SDL_Rect itemRect = *item_sizes;

	if (drop_type == LEFT_SIDE) {
		itemRect.x = sizes->x + sizes->w;
		itemRect.y = sizes->y;
	}
	else if (drop_type == DOWN_SIDE) {
		itemRect.x = sizes->x;
		itemRect.y = sizes->y + sizes->h;
	}

	int flag = 0;

	for (int i = 0; i < List.size(); i++) {
		bool hov = SDL_PointInRect(&point, &itemRect);
		itemRect.y += itemRect.h;

		if (hov) 
			if (!List.at(i)->Block())
				flag = List.at(i)->flag;
	}
	flag_select = flag;
	return flag;
}

void DropDownList::setValue(string value)
{
	label = value;
}

string DropDownList::getValue()
{
	return label;
}

int DropDownList::getFlag()
{
	return flag_select;
}

const vector<DropDownItem*>* DropDownList::getItems()
{
	return &List;
}

void DropDownList::clear()
{
	label = "";
}

DropDownList* DropDownList::deleteItems()
{
	List.clear();
	return this;
}
