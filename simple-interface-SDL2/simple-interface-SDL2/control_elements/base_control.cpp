#include "base_control.h"

SDL_Renderer* Control::renderer = nullptr;

Control::Control(SDL_Rect _sizes, string _label, string _font, int _font_size, int _text_align)
{
	font_size = _font_size;
	sizes = new SDL_Rect;
	*sizes = _sizes;

	label = _label;
	text_align = _text_align;

	block = false;
	display = true;

	font = TTF_OpenFont(_font.c_str(), _font_size);
}

Control::~Control()
{
	TTF_CloseFont(font);
	delete sizes;
}

bool Control::SDL_SetRenderColor(SDL_Renderer* renderer, SDL_Color color)
{
	return !SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
}

void Control::render()
{
	// virtual
}

void Control::renderLabel(string text, SDL_Rect* place)
{
	SDL_Texture* textTexture = nullptr;
	SDL_Surface* textSurface = nullptr;
	SDL_Rect text_rect;

	textSurface = TTF_RenderUTF8_Blended(font, text.c_str(), Colors.element_text);
	if (textSurface == nullptr)
		return;

	text_rect.w = textSurface->w;
	text_rect.h = textSurface->h;
	

	if (text_align == LEFT_ALIGN)
		text_rect.x = place->x + 10;
	else if (text_align == CENTERED_ALIGN)
		text_rect.x = place->x + place->w / 2 - textSurface->w / 2;

	text_rect.y = place->y + place->h / 2 - textSurface->h / 1.88;

	textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_RenderCopy(renderer, textTexture, NULL, &text_rect);

	SDL_FreeSurface(textSurface);
	SDL_DestroyTexture(textTexture);
}

void Control::renderLabel(string text, SDL_Rect* place, int _text_align)
{
	SDL_Texture* textTexture = nullptr;
	SDL_Surface* textSurface = nullptr;
	SDL_Rect text_rect;

	textSurface = TTF_RenderUTF8_Blended(font, text.c_str(), Colors.element_text);
	if (textSurface == nullptr)
		return;

	text_rect.w = textSurface->w;
	text_rect.h = textSurface->h;


	if (_text_align == LEFT_ALIGN)
		text_rect.x = place->x + 10;
	else if (_text_align == CENTERED_ALIGN)
		text_rect.x = place->x + place->w / 2 - textSurface->w / 2;

	text_rect.y = place->y + place->h / 2 - textSurface->h / 1.88;

	textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_RenderCopy(renderer, textTexture, NULL, &text_rect);

	SDL_FreeSurface(textSurface);
	SDL_DestroyTexture(textTexture);
}

void Control::onEvent(SDL_Event* event)
{
	// virtual
}

void Control::Block()
{
	block = true;
}

void Control::Unlock()
{
	block = false;
}

bool Control::isBlock()
{
	return block;
}

void Control::Show()
{
	display = true;
}

void Control::Hide()
{
	display = false;
}

bool Control::isShow()
{
	return display;
}

void Control::Click(bool value)
{
	click = value;
}

bool Control::Hover(int x, int y)
{
	SDL_Point point = { x, y };
	if (!block && display)
		return SDL_PointInRect(&point, sizes);
	return false;
}
