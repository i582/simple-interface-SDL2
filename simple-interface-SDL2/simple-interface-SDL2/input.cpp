#include "input.h"

void Input::render()
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

	if (block) {
		SDL_SetRenderDrawColor(renderer, Colors.element_blocked.r, Colors.element_blocked.g, Colors.element_blocked.b, Colors.element_blocked.a);
	}
	else {
		if (focus)
			SDL_SetRenderDrawColor(renderer, Colors.element_background_focus.r, Colors.element_background_focus.g, Colors.element_background_focus.b, Colors.element_background_focus.a);
		else
			SDL_SetRenderDrawColor(renderer, Colors.element_background_unfocus.r, Colors.element_background_unfocus.g, Colors.element_background_unfocus.b, Colors.element_background_unfocus.a);
	}
	
	SDL_RenderFillRect(renderer, sizes);
	renderLabel(label, sizes);
	SDL_RenderPresent(renderer);
}

void Input::onEvent(SDL_Event* event)
{
	SDL_StartTextInput();
	while (focus) {
		while (SDL_PollEvent(event)) {
			switch (event->type)
			{

			case SDL_KEYDOWN:
			{
				if (event->key.keysym.sym == SDLK_BACKSPACE && label.length() > 0)
					label.pop_back();
				else if (event->key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL)
					SDL_SetClipboardText(label.c_str());
				else if (event->key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL)
					label = SDL_GetClipboardText();

				break;
			}

			case SDL_TEXTINPUT:
				if (!((event->text.text[0] == 'c' || event->text.text[0] == 'C') && (event->text.text[0] == 'v' || event->text.text[0] == 'V') && SDL_GetModState() & KMOD_CTRL))
					if (label.size() * (font_size - 2) + 10 < sizes->w)
						label += event->text.text;

				break;

			case SDL_MOUSEBUTTONDOWN:
			{
				int x, y;
				SDL_GetMouseState(&x, &y);

				SDL_Point point = { x, y };

				if (!SDL_PointInRect(&point, sizes))
					focus = false;

				render();
				break;
			}
			}
			render();
		}
	}
	SDL_StopTextInput();
}

void Input::Focus(bool value)
{
	focus = value;
}

string Input::getValue()
{
	return label;
}

void Input::clear()
{
	label = "";
}
