#include "Game.h"

#include <vector>

#include "Player.h"
#include "Entity.h"
#include "Bullet.h"
#include "Utils.h"
#include "Asteroid.h"
#include "UserInterface.h"

using namespace std;

static const float ASTEROID_SPAWN_RATE = 1250;
static float timer = 0;
static int score = 0;
bool hasWon = false;

void Game::RunGame()
{
	srand(time(0));
	HideCursor();
	DrawBorder();
	vector<Entity*> entities = vector<Entity*>();

	UserInterface ui;

	entities.push_back(new Player({ {3,GetConsoleSize().y / 2},5,5 }));

	timer = clock() + ASTEROID_SPAWN_RATE;

	static int activeAsteroids = 0;
	bool isRunning = true;
	while (isRunning)
	{
		if (timer < clock())
		{
			entities.push_back(new Asteroid());
			timer = clock() + ASTEROID_SPAWN_RATE;
			activeAsteroids++;
		}

		for (int i = 0; i < entities.size(); i++)
		{

			if (i == 0)
			{
				static_cast<Player*>(entities.at(i))->Update(entities);
				entities.at(i)->Draw();
				ui.Draw(score, static_cast<Player*>(entities.at(i))->GetLives(), activeAsteroids);

				for (int j = 0; j < entities.size(); j++)
				{
					if (entities.at(i)->IsColliding(entities.at(j)))
					{
						if (dynamic_cast<Asteroid*>(entities.at(j)) != nullptr)
						{
							static_cast<Player*>(entities.at(i))->TakeDamage();
							entities.at(j)->SetShouldDestroy(true);
							break;
						}
					}
				}
				continue;
			}

			for (int j = 0; j < entities.size(); j++)
			{
				if (dynamic_cast<Bullet*>(entities.at(i)) != nullptr)
				{
					if (entities.at(i)->IsColliding(entities.at(j)) && dynamic_cast<Asteroid*>(entities.at(j)))
					{
						entities.at(i)->SetShouldDestroy(true);
						entities.at(j)->SetShouldDestroy(true);
						score += 10;
					}
				}
			}

			entities.at(i)->Update();
			entities.at(i)->Draw();

			if (entities.at(i)->GetShouldDestroy())
			{
				if (dynamic_cast<Asteroid*>(entities.at(i)) != nullptr)
					activeAsteroids--;

				Entity* auxPtr = entities.at(i);
				entities.erase(entities.begin() + i);
				delete auxPtr;
			}

		}

		//SetConsoleCursorPos({ 0,0 });
		//cout << entities.size();
		Sleep(20);

		if (dynamic_cast<Player*>(entities.at(0))->GetLives() <= 0)
			isRunning = false;
		else if (score >= 100)
		{
			isRunning = false;
			hasWon = true;
		}
	}

	if (hasWon)
	{
		ui.WinDraw();
		cin.get();
	}
	else
	{
		ui.GameOverDraw();
		cin.get();
	}

	for (int i = 0; i < entities.size(); i++)
	{
		delete entities.at(i);
	}

	cin.get();
}
