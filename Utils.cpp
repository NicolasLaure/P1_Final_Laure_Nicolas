#include "Utils.h"
#include "Constants.h"

bool RectRectCollision(Rect box1, Rect box2)
{
	return (box1.position.x + box1.width > box2.position.x
		&& box1.position.x < box2.position.x + box2.width
		&& box1.position.y + box1.height > box2.position.y
		&& box1.position.y < box2.position.y + box2.height);
}

Vector2 GetConsoleSize()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns, rows;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	return { columns, rows };
}

void SetConsoleCursorPos(Vector2 pos)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, { static_cast<short>(pos.x), static_cast<short>(pos.y) });
}

void HideCursor()
{
	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void DrawBorder()
{
	SetConsoleCursorPos({ 0, UPPER_LIMIT });
	cout << static_cast<char>(201);
	SetConsoleCursorPos({ GetConsoleSize().x - 1, UPPER_LIMIT });
	cout << static_cast<char>(187);
	SetConsoleCursorPos({ GetConsoleSize().x - 1, GetConsoleSize().y - 1 });
	cout << static_cast<char>(188);
	SetConsoleCursorPos({ 0, GetConsoleSize().y - 1 });
	cout << static_cast<char>(200);

	for (int i = 1; i < GetConsoleSize().x - 1; i++)
	{
		SetConsoleCursorPos({ i,UPPER_LIMIT });
		cout << static_cast<char>(205);
		SetConsoleCursorPos({ i,GetConsoleSize().y - 1 });
		cout << static_cast<char>(205);
	}

	for (int i = UPPER_LIMIT + 1; i < GetConsoleSize().y - 1; i++)
	{
		SetConsoleCursorPos({ 0, i });
		cout << static_cast<char>(186);
		SetConsoleCursorPos({ GetConsoleSize().x - 1, i });
		cout << static_cast<char>(186);
	}
}
