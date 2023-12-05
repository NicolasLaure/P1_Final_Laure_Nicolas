#include "Entity.h"

Entity::~Entity()
{
}

Rect Entity::GetRect()
{
	return rect;
}

void Entity::Update()
{
	prevPos = rect.position;
}

bool Entity::IsColliding(Entity* other)
{
	return (RectRectCollision(rect, other->GetRect()));
}

bool Entity::GetShouldDestroy()
{
	return shouldDestroy;
}

void Entity::SetShouldDestroy(bool shouldDestroy)
{
	this->shouldDestroy = shouldDestroy;
}
