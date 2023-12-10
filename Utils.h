#pragma once

struct Vector2
{
	int x;
	int y;
};

struct Rect
{
	Vector2 position;
	int width;
	int height;
};

enum Directions
{
	Up,
	Down,
	Left,
	Right
};

bool RectRectCollision(Rect box1, Rect box2);
Vector2 GetConsoleSize();

void SetConsoleCursorPos(Vector2 pos);
void HideCursor();

void DrawBorder();
