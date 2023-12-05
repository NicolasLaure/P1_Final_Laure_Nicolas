#pragma once
#include "Entity.h"

class Bullet : public Entity
{
public:
	Bullet(Vector2 position);
	~Bullet();

	void Update() override;
	void Draw() override;
	void UnDraw(bool unDrawActualPos) override;
	void Move(Directions dir) override;

};

