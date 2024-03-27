#pragma once
#ifndef PELLET_H
#define PELLET_H

#include"StaticEntity.h"

class Pellet : public StaticEntity
{
public:

	Pellet(Board& board);
	~Pellet();
	int score();									//query
	void setScore(int score);

private:
	int mScore;
};
#endif //PELLET_H