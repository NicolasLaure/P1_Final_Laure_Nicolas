#pragma once
#include "Entity.h"
class Asteroid : public Entity
{
private:
	static int activeAsteroids;
public:
	Asteroid();
	~Asteroid();

	void Update() override;
	void Draw() override;
	void UnDraw(bool unDrawActualPos) override;
	void Move(Directions dir) override;
	static int GetActiveAsteroids();
};