#include "button.h"

void Button::render()
{
	if (!display) {
		SDL_Rect clearRect = *sizes;
		clearRect.x--;
		clearRect.y--;
		clearRect.w += 2;
		clearRect.h += 2;

		SDL_SetRenderDrawColor(renderer, Colors.background.r, Colors.background.g, Colors.background.b, Colors.background.a);

		SDL_RenderFillRect(renderer, &clearRect);
		SDL_RenderPresent(renderer);
		return;
	}

	if (block)
		SDL_SetRenderDrawColor(renderer, Colors.element_blocked.r, Colors.element_blocked.g, Colors.element_blocked.b, Colors.element_blocked.a);
	else
		SDL_SetRenderDrawColor(renderer, Colors.element_background.r, Colors.element_background.g, Colors.element_background.b, Colors.element_background.a);

	SDL_RenderFillRect(renderer, sizes);
	renderLabel(label, sizes);
	SDL_RenderPresent(renderer);
}
