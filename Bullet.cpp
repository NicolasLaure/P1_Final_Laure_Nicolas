#include "Bullet.h"

#include <iostream>

using namespace std;

Bullet::Bullet(Vector2 position)
{
	this->rect.position = position;
	this->rect.width = 1;
	this->rect.height = 1;
}

Bullet::~Bullet()
{
	UnDraw(true);
}

void Bullet::Update()
{
	Entity::Update();
	Move(Directions::Right);
}

void Bullet::Draw()
{
	if (prevPos.x != rect.position.x)
		UnDraw(false);
	SetConsoleCursorPos(rect.position);
	cout << 'o';
}

void Bullet::UnDraw(bool unDrawActualPos)
{
	if (unDrawActualPos)
	{
		SetConsoleCursorPos(rect.position);
		cout << ' ';
	}
	else
	{
		SetConsoleCursorPos(prevPos);
		cout << " ";
	}
}

void Bullet::Move(Directions dir)
{
	prevPos = rect.position;
	if (dir == Right && rect.position.x + 1 < GetConsoleSize().x - 1)
		rect.position.x++;
	else if (rect.position.x + 1 >= GetConsoleSize().x - 1)
		shouldDestroy = true;
}
