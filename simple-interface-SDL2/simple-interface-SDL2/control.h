#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include "iostream"
using namespace std;

// ������� ����� ��� ��������� ����������
class Control {
protected:
	SDL_Rect* sizes; // ������� ��������
	string label; // ����� �� ��������
	TTF_Font* font; // ����� ��� ��������
	int font_size; // ������ ������

	SDL_Renderer* renderer;

	bool block; // ���� ��� ����������
	bool display; // ���� ��� �����������
public:
	Control(SDL_Renderer* renderer, SDL_Rect _sizes, string _font, int _font_size);
	~Control();
public:
	virtual void render(); // ������� ����������� ���� ��������
	virtual void renderLabel(string text, SDL_Rect* place); // ������� ����������� ������ ��������

	void Block(bool value); // ������� �������� ���������� block �������� value
	bool Block(); // ������� ������������ ������� �������� ���������� block

	void Display(bool value); // ������� �������� ���������� display �������� value
	bool Display(); // ������� ������������ ������� �������� ���������� display

	bool Hover(int x, int y); // ������� ����������� ������ �� ��� ����� � �������

	virtual void onEvent(SDL_Event* event); // ������� ������������ �������
};