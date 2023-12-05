#include "Asteroid.h"
#include "Utils.h"
#include "Constants.h"

Asteroid::Asteroid()
{
	rect.height = 4;
	rect.width = 3;
	rect.position.x = GetConsoleSize().x - (2 + rect.width);
	rect.position.y = rand() % (GetConsoleSize().y - rect.height - (UPPER_LIMIT + 1)) + UPPER_LIMIT + 1;
}

Asteroid::~Asteroid()
{
	UnDraw(true);
}

void Asteroid::Update()
{
	Entity::Update();
	Move(Left);
}

void Asteroid::Draw()
{
	if (prevPos.x != rect.position.x)
		UnDraw(false);

	SetConsoleCursorPos(rect.position);
	cout << "___";
	SetConsoleCursorPos({ rect.position.x, rect.position.y + 1 });
	cout << "/   \\";
	SetConsoleCursorPos({ rect.position.x, rect.position.y + 2 });
	cout << "|  _|";
	SetConsoleCursorPos({ rect.position.x, rect.position.y + 3 });
	cout << "\\__/";
}

void Asteroid::UnDraw(bool unDrawActualPos)
{
	if (unDrawActualPos)
	{
		SetConsoleCursorPos(rect.position);
		cout << "     ";
		SetConsoleCursorPos({ rect.position.x, rect.position.y + 1 });
		cout << "     ";
		SetConsoleCursorPos({ rect.position.x, rect.position.y + 2 });
		cout << "     ";
		SetConsoleCursorPos({ rect.position.x, rect.position.y + 3 });
		cout << "     ";
	}
	else
	{
		SetConsoleCursorPos(prevPos);
		cout << "     ";
		SetConsoleCursorPos({ prevPos.x, prevPos.y + 1 });
		cout << "     ";
		SetConsoleCursorPos({ prevPos.x, prevPos.y + 2 });
		cout << "     ";
		SetConsoleCursorPos({ prevPos.x, prevPos.y + 3 });
		cout << "     ";
	}
}

void Asteroid::Move(Directions dir)
{
	if (dir == Left && rect.position.x - 1 > 0)
		rect.position.x--;
	else if (rect.position.x - 1 <= 0)
		shouldDestroy = true;
}
