#include "itemList.h"

ItemList::~ItemList()
{
	delete item_sizes;
}

void ItemList::render()
{
	if (!display)
		return;

	SDL_Rect render_rect = *item_sizes;
	render_rect.x = sizes->x + sizes->w + 2;
	render_rect.y = sizes->y;

	if (block)
		SDL_SetRenderDrawColor(renderer, Colors.element_blocked.r, Colors.element_blocked.g, Colors.element_blocked.b, Colors.element_blocked.a);
	else
		SDL_SetRenderDrawColor(renderer, Colors.element_background.r, Colors.element_background.g, Colors.element_background.b, Colors.element_background.a);

	SDL_RenderFillRect(renderer, sizes);


	renderLabel(label, sizes);


	if (show_list && !block) {

		for (int i = 0; i < List.size(); i++)
		{
			SDL_SetRenderDrawColor(renderer, Colors.element_background.r, Colors.element_background.g, Colors.element_background.b, Colors.element_background.a);
			SDL_RenderFillRect(renderer, &render_rect);
			renderLabel(List[i]->text, &render_rect, LEFT_ALIGN);
			render_rect.y += render_rect.h;
		}
	}
	else 
	{
		SDL_Rect clear_rect = { render_rect.x, render_rect.y, render_rect.w, render_rect.h * List.size() };
		SDL_SetRenderDrawColor(renderer, Colors.background.r, Colors.background.g, Colors.background.b, Colors.background.a);
		SDL_RenderFillRect(renderer, &clear_rect);
	}

	SDL_RenderPresent(renderer);
}

void ItemList::add(string text, int flag)
{
	Item* newItem = new Item;
	newItem->text = text;
	newItem->flag = flag;

	List.push_back(newItem);
}

void ItemList::open(bool value)
{
	show_list = value;
}

bool ItemList::open()
{
	return show_list;
}

int ItemList::checkItemHover(int x, int y)
{
	if (block || !display || !show_list)
		return false;

	SDL_Point point = { x, y };

	SDL_Rect itemRect = *item_sizes;
	itemRect.x = sizes->x + sizes->w;
	itemRect.y = sizes->y;

	int flag = 0;
	for (int i = 0; i < List.size(); i++) {
		bool hov = SDL_PointInRect(&point, &itemRect);
		itemRect.y += itemRect.h;

		if (hov)
			flag = List.at(i)->flag;
	}
	return flag;
}
