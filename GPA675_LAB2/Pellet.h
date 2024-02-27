#pragma once

#include"StaticEntity.h"

class Pellet : public StaticEntity
{
public:

	int score();									//query
	void setScore(int score);

	virtual void applyEffectOnSnake(Snake& snake);

private:
	int mScore;
};

