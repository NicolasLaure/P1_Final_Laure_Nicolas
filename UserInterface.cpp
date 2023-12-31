#include "UserInterface.h"

#include <iostream>

#include "Utils.h"
#include "Asteroid.h"

using namespace std;

static const int BORDER_SPACING = 12;
void UserInterface::Draw(int score, int lives)
{
	SetConsoleCursorPos({ 0, 1 });
	switch (lives)
	{
	case 1:
		cout << "Lives: <3        ";
		break;
	case 2:
		cout << "Lives: <3  <3    ";
		break;
	case 3:
		cout << "Lives: <3  <3  <3";
		break;
	default:
		break;
	}
	SetConsoleCursorPos({ GetConsoleSize().x / 2 - 4, 1 });
	cout << "Asteroids:" << Asteroid::GetActiveAsteroids();
	
	SetConsoleCursorPos({ GetConsoleSize().x - BORDER_SPACING, 1 });
	cout << "Score:" << score;
}

void UserInterface::GameOverDraw()
{
	SetConsoleCursorPos({ 0,0 });
	cout << "You Lose!";
}

void UserInterface::WinDraw()
{
	SetConsoleCursorPos({ 0,0 });
	cout << "You Won!";
}
