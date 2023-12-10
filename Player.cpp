#include "Player.h"

#include <iostream>
#include <conio.h>

#include "Bullet.h"
#include "Constants.h"

using namespace std;

static float timer = 0;

Player::Player()
{
	this->rect = { {0,0},5,5 };
}

Player::Player(Rect rect)
{
	this->rect = rect;
}

Player::~Player()
{

}

void Player::Update(vector<Entity*>& entities)
{
	Entity::Update();

	if (timer < clock())
		canShoot = true;

	if (_kbhit())
	{
		char keyPressed = _getch();

		if (keyPressed == 'w' || keyPressed == 'W')
			Move(Up);
		else if (keyPressed == 's' || keyPressed == 'S')
			Move(Down);
		else if (static_cast<int>(keyPressed) == 32)
			if (canShoot)
				Shoot(entities);
	}
}

void Player::Draw()
{
	if (prevPos.y != rect.position.y)
		UnDraw(false);

	SetConsoleCursorPos(rect.position);
	cout << static_cast<char>(205) << static_cast<char>(187);
	SetConsoleCursorPos({ rect.position.x + 1, rect.position.y + 1 });
	cout << static_cast<char>(46) << static_cast<char>(175);
	SetConsoleCursorPos({ rect.position.x + 1, rect.position.y + 2 });
	cout << static_cast<char>(91) << static_cast<char>(204) << static_cast<char>(93) << static_cast<char>(205) << static_cast<char>(175);
	SetConsoleCursorPos({ rect.position.x + 1, rect.position.y + 3 });
	cout << static_cast<char>(46) << static_cast<char>(175);
	SetConsoleCursorPos({ rect.position.x, rect.position.y + 4 });
	cout << static_cast<char>(205) << static_cast<char>(188);
}

void Player::UnDraw(bool unDrawActualPos)
{
	SetConsoleCursorPos(prevPos);
	cout << "  ";
	SetConsoleCursorPos({ prevPos.x, prevPos.y + 1 });
	cout << "   ";
	SetConsoleCursorPos({ prevPos.x, prevPos.y + 2 });
	cout << "      ";
	SetConsoleCursorPos({ prevPos.x, prevPos.y + 3 });
	cout << "   ";
	SetConsoleCursorPos({ prevPos.x, prevPos.y + 4 });
	cout << "  ";
}

void Player::Move(Directions dir)
{
	if (dir == Up && rect.position.y - 1 > UPPER_LIMIT)
	{
		prevPos = rect.position;
		rect.position.y--;
	}
	else if (dir == Down && rect.position.y + rect.height + 1 <= GetConsoleSize().y - 1)
	{
		prevPos = rect.position;
		rect.position.y++;
	}
}

void Player::Shoot(vector<Entity*>& entities)
{
	entities.push_back(new Bullet({ rect.position.x + 3, rect.position.y + 1 }));
	entities.push_back(new Bullet({ rect.position.x + 3, rect.position.y + 3 }));
	canShoot = false;
	timer = clock() + shootCoolDown;
}

void Player::TakeDamage()
{
	lives--;
}

int Player::GetLives()
{
	return lives;
}