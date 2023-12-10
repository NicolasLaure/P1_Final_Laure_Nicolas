#pragma once
#include "Utils.h"

class Entity
{
protected:
	Rect rect;
	Vector2 prevPos;
	bool shouldDestroy = false;
public:

	virtual ~Entity();
	Rect GetRect();
	virtual void Update();
	virtual void Draw() = 0;
	virtual void UnDraw(bool unDrawActualPos) = 0;
	virtual void Move(Directions dir) = 0;
	bool IsColliding(Entity* other);
	bool GetShouldDestroy();
	void SetShouldDestroy(bool shouldDestroy);
};