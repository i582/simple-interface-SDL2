#include "textField.h"

void TextField::add(string newLine)
{
	lines.push_back(newLine);
}

void TextField::render()
{
	SDL_SetRenderDrawColor(renderer, Colors.element_background.r, Colors.element_background.g, Colors.element_background.b, Colors.element_background.a);
	SDL_RenderFillRect(renderer, sizes);
	renderText();
}

void TextField::renderText()
{
	SDL_Rect rect = { sizes->x + 5, sizes->y + 10, sizes->w - 10, 15 };
	int count_lines = lines.size();

	rect.y += 16 * (count_lines - 1);
	if (count_lines > 0)
		renderLabel(lines.at(count_lines - 1), &rect);

	SDL_RenderPresent(renderer);
}
