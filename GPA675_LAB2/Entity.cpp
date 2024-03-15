#include "Entity.h"

Entity::Entity(Board& board)
	: mBoard{ board }
	, mAge{}
	, mAlive{ true }
	, mColliding{nullptr}
{
}

Entity::~Entity()
{
}

double Entity::age()
{
	return mAge;
}

void Entity::setDead()
{
	mAlive = false;
}