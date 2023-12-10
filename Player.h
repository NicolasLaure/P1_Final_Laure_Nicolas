#pragma once
#include "Entity.h"

#include <vector>

using namespace std; 

class Player : public Entity
{
private:
	int lives = 3;
	float shootCoolDown = 150;
	bool canShoot = true;

public:
	Player();
	Player(Rect rect);
	~Player();

	void Update(vector<Entity*>& entities);
	void Draw() override;
	void UnDraw(bool unDrawActualPos) override;
	void Move(Directions dir) override;
	void Shoot(vector<Entity*>& entities);

	void TakeDamage();
	int GetLives();
};

